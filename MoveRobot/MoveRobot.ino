// based on sensor values, changes the motor speeds

#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

const int leftSensorPin = A0;
const int rightSensorPin = A1;
const int leftWheelPin = 3;
const int rightWheelPin = 5;

// speed ranges from 0 (off) to 255 (max speed)
int leftWheelSpeed = 10;
int rightWheelSpeed = 10;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");

}


void loop() {
  // put your main code here, to run repeatedly:

  // continually read in the sensor values
  // if both values represent black, continue straight
  // if left value represents white, turn right
  // if right value represents white, turn left a bit

  if (analogRead(rightSensorPin) > 500) {
    Serial.println("Black tape");
    turnRight();
  } else {
    Serial.println("Reflective floor");
    // TODO: change the right wheel speed back to normal
  }

  if (analogRead(leftSensorPin) > 500) {
    Serial.println("Black tape");
    turnLeft();
  } else {
    Serial.println("Reflective floor");
    // TODO: change the left wheel speed back to normal
  }

}


// helper functions for controlling wheel movement
void turnLeft() {
  // slow left wheel speed
}

void turnRight() {
  // slow right wheel speed here
}

void logData() {
  // send wheel velocity data to a file and save
}
