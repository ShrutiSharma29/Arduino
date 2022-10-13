const int ledPin =13;
const int ldrPin =10;

void setup() {
  Serial.begin(9600);
pinMode(ledPin,OUTPUT);
pinMode(ldrPin,INPUT);

  // put your setup code here, to run once:

}

void loop() {
int ldrStatus=digitalRead(ldrPin);
if(ldrStatus==1)

digitalWrite(ledPin,LOW);
Serial.print("Its DARK trun on the lights ");
Serial.println(ldrStatus);

}
else
{
digitalWrite(ledPin,HIGH);
Serial.print("Its BRIGHT turn off the lights ");
Serial.println(ldrStatus);
}
  // put your main code here, to run repeatedly:

}
