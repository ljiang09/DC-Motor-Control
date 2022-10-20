// based on sensor values, changes the motor speeds

#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Initialize motors in the 1 and 2 positions on the shield
Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(4);

const int leftSensorPin = A0;
const int rightSensorPin = A1;

const int leftThreshold = 700;
const int rightThreshold = 500;

// speed ranges from 0 (off) to 255 (max speed)
int rightMotorSpeed = 40;
int leftMotorSpeed = rightMotorSpeed * 60/100;
int leftSlowedSpeed = leftMotorSpeed / 3;
int rightSlowedSpeed = rightMotorSpeed / 3;
int i = 0;


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
  leftMotor->run(BACKWARD);
  rightMotor->run(FORWARD);

  // continually read in the sensor values
  // if both values represent black, continue straight
  // if left value represents white, turn right
  // if right value represents white, turn left a bit

//  Serial.println(analogRead(rightSensorPin));
//  Serial.println(analogRead(leftSensorPin));

  if (analogRead(rightSensorPin) > rightThreshold) {
//    Serial.print("Black tape  ");
//    Serial.println(analogRead(leftSensorPin));
//    leftMotor->setSpeed(0);
//    rightMotor->setSpeed(0);
    turnRight();
  } else {
//    Serial.print("Reflective floor");
//    Serial.println(analogRead(leftSensorPin));
    goStraight();
  }

  if (analogRead(leftSensorPin) > leftThreshold) {
//    Serial.print("Black tape  ");
//    Serial.println(analogRead(rightSensorPin));
//    leftMotor->setSpeed(0);
//    rightMotor->setSpeed(0);
    turnLeft();
  } else {
//    Serial.print("Reflective floor");
//    Serial.println(analogRead(rightSensorPin));
    goStraight();
  }

}


// helper functions for controlling wheel movement
void turnRight() {
  // slow left wheel speed
  leftMotor->setSpeed(leftSlowedSpeed);
}

void turnLeft() {
  // slow right wheel speed
  rightMotor->setSpeed(rightSlowedSpeed);
}

void goStraight() {
  leftMotor->setSpeed(leftMotorSpeed);
  rightMotor->setSpeed(rightMotorSpeed);
}

void logData() {
  // send wheel velocity data to a file and save
}
