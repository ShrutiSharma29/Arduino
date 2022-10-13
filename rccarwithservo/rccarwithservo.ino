#define echoPin 4
#define trigPin 5

long duration;
int distance;
char t;

void setup() {
  pinMode(13, OUTPUT);  //left motors forward
  pinMode(12, OUTPUT);  //left motors reverse
  pinMode(11, OUTPUT);  //right motors forward
  pinMode(10, OUTPUT);  //right motors reverse
                        //pinMode(9,OUTPUT);   //Led
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  //delayMicroseconds(2);  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, HIGH);
  //delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  //speed of sound wave divided by 2(go and come back)
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println("cm");

  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }

  if (distance < 50) {
    int randoms = random(10);
    int number = randoms % 3;

    if (number == 0) {
      reverse();
    } else if (number == 1) {
      turnRight();
    } else {
      turnLeft();
    }
  } else {
    reverse();
  }

  delay(60);
}


void forward() {  //move forward(all motors rotate in forward direction)
  digitalWrite(13, HIGH);
  digitalWrite(11, HIGH);
}

void reverse() {
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
    /* if  (distance <80)   {
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
    }*/
  }

void turnRight() {  //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(11, HIGH);
}

void turnLeft() {  //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(13, HIGH);
}

void stop() {  //STOP (all motors stop)
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}