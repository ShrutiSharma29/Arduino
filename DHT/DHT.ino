#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);


void setup() {
Serial.begin(9600);
dht.begin();
pinMode(13,OUTPUT);  // put your setup code here, to run once:

}

void loop() {
  delay(2000);

float t=dht.readTemperature();
float h=dht.readHumidity();

if(h>80)
{
 digitalWrite(13,LOW);
 delay(500);
  digitalWrite(13,HIGH);
 delay(500);
}
if(h<=80)
{
  digitalWrite(13,LOW);
 delay(2000);
  digitalWrite(13,HIGH);
 delay(2000);
}

Serial.print("Humidity = ");
Serial.print(h);
Serial.print("% Temperature =");
Serial.print(t);
Serial.println(" *C");
 // put your main code here, to run repeatedly:
}
