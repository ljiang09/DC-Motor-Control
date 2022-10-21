// based on sensor values, changes the motor speeds

#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Initialize motors in the 1 and 2 positions on the shield
Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(4);

const int leftSensorPin = A1;
const int rightSensorPin = A0;

float leftThreshold = 200;
float rightThreshold = 200;


// NTOE TO SELF: motors are flipped irl and in code
// sensors are correct tho

// speed ranges from 0 (off) to 255 (max speed)
float motorRatio = 60/100;
int leftMotorSpeed = 24;
int rightMotorSpeed = 40;  //leftMotorSpeed * motorRatio;
int leftSlowedSpeed = round(leftMotorSpeed * 0.75);
int rightSlowedSpeed = round(rightMotorSpeed * 0.75);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");

  leftMotor->setSpeed(leftMotorSpeed);
  rightMotor->setSpeed(rightMotorSpeed);
}


void loop() {
//  goStraight();
//  delay(1000);
//  backUp();

//  if ((analogRead(rightSensorPin) > rightThreshold) && (analogRead(leftSensorPin) > leftThreshold)) {
//      stopMoving();
//  }

  if (analogRead(rightSensorPin) > rightThreshold) {  // black tape
    stopMoving();
    turnRight();
  } else {  // Reflective floor
    goStraight();
  }

  if (analogRead(leftSensorPin) > leftThreshold) {  // black tape
    stopMoving();
    turnLeft();
  } else {  // Reflective floor
    goStraight();
  }

  logData();

}


void stopMoving() {
  leftMotor->setSpeed(leftMotorSpeed*1.25);
  rightMotor->setSpeed(rightMotorSpeed*1.5);
  rightMotor->run(FORWARD);
  leftMotor->run(BACKWARD);
  delay(300);
  leftMotor->setSpeed(0);
  rightMotor->setSpeed(0);
  delay(1000);
}

//void backUp() {
//  leftMotor->setSpeed(leftMotorSpeed);
//  rightMotor->setSpeed(rightMotorSpeed*0.75);
//  leftMotor->run(BACKWARD);
//  rightMotor->run(FORWARD);
//  delay(700);
//}

// helper functions for controlling wheel movement
// turns in place
void turnRight() {
//  backUp();
  leftMotor->setSpeed(0);
  rightMotor->setSpeed(rightMotorSpeed*1.5);
  leftMotor->run(BACKWARD);
  rightMotor->run(BACKWARD);

  // turning right until the floor is spotted
  for (int i = 0; i < 1000; i++) {
    Serial.println("turning left");
    if ((analogRead(leftSensorPin) <= leftThreshold) && (analogRead(rightSensorPin) <= rightThreshold)) {
      leftMotor->setSpeed(0);
      rightMotor->setSpeed(0);
      delay(500);
      return;
    }
  }
}

// turns in place, about the center
void turnLeft() {
//  backUp();
  leftMotor->setSpeed(leftMotorSpeed*1.5);
  rightMotor->setSpeed(0);
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);

  for (int i = 0; i < 1000; i++) {
    Serial.println("turning right");
    if ((analogRead(leftSensorPin) <= leftThreshold) && (analogRead(rightSensorPin) <= rightThreshold)) {
      leftMotor->setSpeed(0);
      rightMotor->setSpeed(0);
      delay(500);
      return;
    }
  }
}

// moves the bot forward
void goStraight() {
  leftMotor->setSpeed(leftMotorSpeed);
  rightMotor->setSpeed(rightMotorSpeed);
  leftMotor->run(FORWARD);
  rightMotor->run(BACKWARD);
}


// helper function to print data into the monitor for pyserial to read
void logData() {
  // log sensor data, commanded speeds
  // TODO: implement this!!
}
