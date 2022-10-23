// based on sensor values, changes the motor speeds

#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Initialize motors in the 1 and 2 positions on the shield
Adafruit_DCMotor *rightMotor = AFMS.getMotor(4);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(3);

const int leftSensorPin = A2;
const int rightSensorPin = A0;

float leftThreshold = 200;
float rightThreshold = 200;


// NTOE TO SELF: motors are flipped irl and in code
// sensors are correct tho

// speed ranges from 0 (off) to 255 (max speed)
float motorRatio = 60/100;
int leftMotorSpeed = 25;
int rightMotorSpeed = 25;  //leftMotorSpeed * motorRatio;
int leftSlowedSpeed = round(leftMotorSpeed * 0.75);
int rightSlowedSpeed = round(rightMotorSpeed * 0.75);


bool runningTimer = false;  // if true, tells the loop to not overwrite the timer start value
unsigned long startMoving = 0;

String prevMsg = "";



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
  Serial.println(analogRead(rightSensorPin));
  Serial.println(analogRead(leftSensorPin));
  if ((analogRead(rightSensorPin) > rightThreshold) && (analogRead(leftSensorPin) > leftThreshold)) {
    leftMotorSpeed = leftMotorSpeed;
    rightMotorSpeed = rightMotorSpeed;
    return;
  }

  if (analogRead(rightSensorPin) > rightThreshold) {  // black tape
    turnRight();
  } else {  // Reflective floor
    goStraight();
  }

  if (analogRead(leftSensorPin) > leftThreshold) {  // black tape
    turnLeft();
  } else {  // Reflective floor
    goStraight();
  }

  logData();

}


// helper functions for controlling wheel movement
// turns in place
void turnRight() {
  leftMotor->setSpeed(leftMotorSpeed*1.25);
  rightMotor->setSpeed(rightMotorSpeed*1.25);
  leftMotor->run(BACKWARD);
  rightMotor->run(BACKWARD);
}

// turns in place, about the center
void turnLeft() {
  leftMotor->setSpeed(leftMotorSpeed*1.25);
  rightMotor->setSpeed(rightMotorSpeed*1.25);
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
}

// moves the bot forward
void goStraight() {
  leftMotor->setSpeed(leftMotorSpeed);
  rightMotor->setSpeed(rightMotorSpeed);
  leftMotor->run(BACKWARD);
  rightMotor->run(FORWARD);
}


// helper function to print data into the monitor for pyserial to read
void logData() {
  // log sensor data, commanded speeds
  // TODO: implement this!!
}
