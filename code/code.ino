//Paul Schakel
//Useless Dodechedron
//Opens the door to box if switch is on

#include <Servo.h>

Servo myServo;

int switchPin = 2;
int servoPin = 12;
int i = 0;
int switchStatus;
int pos = 0;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  pinMode(switchStatus, INPUT);
}

void loop() {
  switchStatus = digitalRead(switchPin);
  Serial.println(switchStatus);

  if (switchStatus == HIGH && i > 0) {
    turnServo(true, 1, 180);
    turnServo(false, 180, 180);
    i = 0;
  }
  else {
    i = 1;
  }
}

void turnServo(bool direction, int posStart, int posLimit) {
  pos = posStart;
  for (int angle = 1; angle < posLimit; angle++ ) {
    myServo.write(pos);
    delay(50);
    Serial.println(pos);
    if (direction) {
      pos++;
    }
    else if (!direction) {
      pos--;
    }
    else {
      Serial.println("Lord help us the world is about to end");
      }
  }
}
