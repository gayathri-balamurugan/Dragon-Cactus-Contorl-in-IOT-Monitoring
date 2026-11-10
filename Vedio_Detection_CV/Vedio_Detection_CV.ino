#include <Servo.h>

Servo jumpServo;

const int REST_ANGLE = 20;
const int JUMP_ANGLE = 55;

void setup() 
{
  Serial.begin(9600);

  jumpServo.attach(9);
  jumpServo.write(REST_ANGLE);

  Serial.println("Dino Jump System Ready");
}

void loop() {
  if (Serial.available() > 0)
  {
    char command = Serial.read();

    if (command == 'J') 
    {
      jumpServo.write(JUMP_ANGLE);
      delay(180);

      jumpServo.write(REST_ANGLE);
      delay(100);

      Serial.println("Jump completed");
    }
  }
}
