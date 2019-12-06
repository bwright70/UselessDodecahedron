//Paul Schakel
//Useless Dodechedron
//Opens the door to box if switch is on

#include <Servo.h>

Servo myServo;

int switchPin = 2;
int servoPin = 12;
int i = 0;
int switchStatus;
int pos = 90;
int servoDirection;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  pinMode(switchStatus, INPUT);
  myServo.write(pos);
}

void loop() {
  switchStatus = digitalRead(switchPin);
  Serial.println(switchStatus);

  if (switchStatus == HIGH && i == 1) {
    while (true) {
      myServo.write(pos);
      pos++;
      delay(75);
      Serial.println(pos);
      if (pos > 180) {
        pos = 90;
        continue;
      }
      
    }
    i--;
  }
  else {
    i = 1;
    pos = 90;
  }
}
