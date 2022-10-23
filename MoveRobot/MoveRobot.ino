// based on sensor values, changes the motor speeds

#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Initialize motors in the 1 and 2 positions on the shield
Adafruit_DCMotor *leftMotor = AFMS.getMotor(3);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(4);

const int rightSensorPin = A0;
const int leftSensorPin = A2;

float sensorThreshold = 200;

// speed ranges from 0 (off) to 255 (max speed)
int leftMotorSpeed = 25;
int rightMotorSpeed = leftMotorSpeed;

// for logging data
int leftSpeed = leftMotorSpeed;
int rightSpeed = rightMotorSpeed;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");

  Serial.println("Enter an integer for the baseline wheel speed.");
  while (Serial.available() == 0) {
    leftMotorSpeed = Serial.parseInt();
    rightMotorSpeed = leftMotorSpeed;
    leftSpeed = leftMotorSpeed;
    rightSpeed = rightMotorSpeed;
    leftMotor->setSpeed(leftMotorSpeed);
    rightMotor->setSpeed(rightMotorSpeed);
  }
}


void loop() {
  if ((analogRead(rightSensorPin) > sensorThreshold) && (analogRead(leftSensorPin) > sensorThreshold)) {
    leftMotorSpeed = leftMotorSpeed;
    rightMotorSpeed = rightMotorSpeed;
    return;
  }

  if (analogRead(rightSensorPin) > sensorThreshold) {  // black tape
    turnRight();
  } else {  // Reflective floor
    goStraight();
  }

  if (analogRead(leftSensorPin) > sensorThreshold) {  // black tape
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
  leftSpeed = leftMotorSpeed*1.25;
  rightSpeed = -rightMotorSpeed*1.25;
  leftMotor->run(BACKWARD);
  rightMotor->run(BACKWARD);
}

// turns in place, about the center
void turnLeft() {
  leftMotor->setSpeed(leftMotorSpeed*1.25);
  rightMotor->setSpeed(rightMotorSpeed*1.25);
  leftSpeed = -leftMotorSpeed*1.25;
  rightSpeed = rightMotorSpeed*1.25;
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
}

// moves the bot forward
void goStraight() {
  leftMotor->setSpeed(leftMotorSpeed);
  rightMotor->setSpeed(rightMotorSpeed);
  leftSpeed = leftMotorSpeed;
  rightSpeed = rightMotorSpeed;
  leftMotor->run(BACKWARD);
  rightMotor->run(FORWARD);
}


// helper function to print data into the monitor for pyserial to read
void logData() {
  // log sensor data, commanded speeds
  Serial.print(String(analogRead(leftSensorPin)) + " " + String(analogRead(rightSensorPin)) + " ");
  Serial.println(String(leftSpeed) + " " + String(rightSpeed));
}
