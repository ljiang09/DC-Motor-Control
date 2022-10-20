// test that the two IR reflectance sensors function similarly, and that they change consistently as distance changes

const int leftSensorPin = A0;
const int rightSensorPin = A1;
int sum = 0;
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//  sum = sum + analogRead(sensorPin);
//  counter++;
//  if (counter >= 20) {
//    Serial.println(sum / 20);
//    counter = 0;
//    sum = 0;
//  }

  Serial.print("left:  ");
  Serial.println(analogRead(leftSensorPin));
  Serial.print("right: ");
  Serial.println(analogRead(rightSensorPin));
}
