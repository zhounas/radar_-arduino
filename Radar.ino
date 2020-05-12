#include <Servo.h>
Servo myservo;
const int Signal = 5;
const int Echo = 6;
int pos = 0;
long echotime;
int distance;
float speedOfSound = 0.0343; // cm/µs
String data;

void setup() {
  myservo.attach(9);
  pinMode(Signal, OUTPUT);
  pinMode(Echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(15);
    data = pos;
    data += ":";
    data += readDistance();
    Serial.println(data);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
    data = pos;
    data += ":";
    data += readDistance();
    Serial.println(data);
  }
}

int readDistance() {
  digitalWrite(Signal, LOW);
  delayMicroseconds(5);
  digitalWrite(Signal, HIGH);
  delayMicroseconds(10);
  digitalWrite(Signal, LOW);
  echotime = pulseIn(Echo, HIGH);
  distance = echotime * speedOfSound / 2;
  return (distance);
}
