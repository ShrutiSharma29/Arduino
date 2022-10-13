#define echoPin 2
#define trigPin 6
#include<Servo.h>
Servo Myservo;
int pos;
long duration;
int distance;

void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
  Myservo.attach(3);
  pinMode(13,OUTPUT);
    // put your setup code here, to run once:

}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);  // put your main code here, to run repeatedly:
   digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
   digitalWrite(trigPin,LOW);  
   duration=pulseIn(echoPin,HIGH);
   distance=duration * 0.034/2; //speed of sound wave divided by 2(go and come back)

   if(distance>500) 
{ /
digitalWrite(13,HIGH);

   for(pos=0;pos<=90;pos++)
{
  Myservo.write(pos);
  delay(15);

}
delay(500);
  // put your main code here, to run repeatedly:

for(pos=90;pos>=0;pos--)
{
Myservo.write(pos);
  delay(15);  
}
delay(500);

}
if (distance <=500)
{ 
digitalWrite(13,LOW);
  //stop
}
Serial.print("Distance : ");
Serial.print(distance);
Serial.println("cm");
}
