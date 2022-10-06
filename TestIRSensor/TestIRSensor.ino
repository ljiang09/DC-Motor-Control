// test that the two IR reflectance sensors function similarly, and that they change consistently as distance changes

const int sensorPin = A5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(sensorPin));
}
