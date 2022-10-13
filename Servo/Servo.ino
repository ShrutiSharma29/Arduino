
#include<Servo.h>
Servo Myservo;
int pos;
void setup()
 {
  Myservo.attach(3);

  // put your setup code here, to run once:
}

void loop() {
for(pos=0;pos<=90;pos++)
{
  Myservo.write(pos);
  delay(15);

}
delay(1000);
  // put your main code here, to run repeatedly:

for(pos=90;pos>=0;pos--)
{
Myservo.write(pos);
  delay(15);  
}
delay(1000);
}

