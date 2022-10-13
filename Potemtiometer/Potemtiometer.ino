#define POTENTIOMETER_PIN A0
const int LED =11;


void setup() {
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop()
 {

  int data = analogRead(POTENTIOMETER_PIN);
  int volts = map(data, 0, 1023, 0, 254);
  analogWrite(LED,volts);
  Serial.print(" Volts are : ");
  Serial.println(volts);
 /*Serial.print(" Potentiometer at : ");
  Serial.print(percentage);
  Serial.println("%");*/
  delay(50);

  // put your main code here, to run repeatedly:
}