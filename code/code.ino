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
  pinMode(switchPin, INPUT);
}

void loop() {
  switchStatus =
  digitalRead(switchPin);
  if (switchStatus == LOW && i == 0) {
    i = 2;
  } else if (switchStatus == HIGH && i == 2) {
    i = 1;
  }
  Serial.println(i);
  Serial.println(switchStatus);

  if (switchStatus == HIGH && i == 1) {
    turnServo(false, 180, 180);
    turnServo(true, 1, 180);
    Serial.println("set i to 0");
    i = 0;
  }
}

void turnServo(bool direction, int posStart, int posLimit) {
  pos = posStart;
  for (int angle = 1; angle < posLimit; angle++ ) {
    myServo.write(pos);
    delay(0);
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
