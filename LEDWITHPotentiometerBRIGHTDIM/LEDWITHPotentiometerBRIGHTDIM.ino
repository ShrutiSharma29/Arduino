#define POTENTIOMETER_PIN A0
const int LED =11;


void setup() {
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop(){

  for(int volts =0; volts<255; volts++){
  analogWrite(LED,volts);
  delay(10);
  }
  for(int volts=254; volts>0; volts--){
  analogWrite(LED,volts);
  delay(10);
  }
}