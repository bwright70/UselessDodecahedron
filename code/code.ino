//Paul Schakel
//Useless Dodechedron
//Opens the door to box if switch is on

#include <Servo.h>

Servo myServo;

int switchPin = 2;
int servoPin = 12;
int i = 0;
int switchStatus;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  pinMode(switchStatus, INPUT);
  myServo.write(90);
}

void loop() {
  switchStatus = digitalRead(switchPin);
  myServo.write(90);

  Serial.println(switchStatus);

  if (switchStatus == HIGH && i == 1) {
      myServo.write(135);
      i = 0;
      myServo.write(90);
    }
  else {
      i = 1;
    }
}
