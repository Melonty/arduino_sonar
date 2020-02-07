#include <Arduino.h>
#include <Servo.h>
#include <NewPing.h>

#define TRIG 8
#define ECHO 9
#define SERVO 10
#define MAX_DISTANCE 700

Servo servo;
NewPing sonar = NewPing(TRIG, ECHO, MAX_DISTANCE);

unsigned angle = 90;
bool clockwise = true; // 0 -> 180 clockwise; 180 -> 0 counterclockwise

void setup()
{
  servo.attach(SERVO);
  Serial.begin(9600);
}

void loop()
{
  servo.write(angle);
  Serial.print(angle);
  Serial.print(",");
  Serial.print(sonar.ping_cm());
  Serial.print(".");
  if (clockwise)
  {
    ++angle;
    if (angle == 180)
      clockwise = false;
  }
  else
  {
    --angle;
    if (angle == 0)
      clockwise = true;
  }
  delay(50);
}