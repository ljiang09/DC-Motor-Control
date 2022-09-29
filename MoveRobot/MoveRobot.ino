const int leftSensorPin = A0;
const int rightSensorPin = A1;
const int leftWheelPin = 3;
const int rightWheelPin = 5;

var leftWheelSpeed = 10;
var rightWheelSpeed = 10;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:

  // continually read in the sensor values
  // if both values represent black, continue straight
  // if left value represents white, turn right
  // if right value represents white, turn left a bit

}


// helper functions for controlling wheel movement
void turnLeft() {
  // change leftWheelSpeed and rightWheelSpeed here
}

void turnRight() {
  // change leftWheelSpeed and rightWheelSpeed here
}
