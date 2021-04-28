#include <AFMotor.h>
#define lefts A0
#define rights A3
AF_DCMotor motor1(4,MOTOR12_8KHZ);
AF_DCMotor motor2(3,MOTOR12_8KHZ);
int a=1;
void setup() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
 pinMode(lefts,INPUT);
 pinMode(rights,INPUT);
 Serial.begin(9600);
}

void loop() {
  Serial.print(digitalRead(rights));
  Serial.print('\t');
  Serial.println(digitalRead(lefts));
  int b,c;
  b=digitalRead(rights);
  c=digitalRead(lefts);
  if(b==a&&c==a)
  {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  }
  else if(c==a&&b!=a)
  {
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
  }
  else if(c!=a&&b==a)
  {motor1.run(FORWARD);
  motor2.run(BACKWARD);
  }
else if(c!=a&&b!=a)
  {motor1.run(FORWARD);
  motor2.run(FORWARD);
  }

}