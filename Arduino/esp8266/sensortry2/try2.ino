#define trigPin 12
#define echoPin 13
#define led1 13


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);


}

void loop() {
 long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(0); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(0); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 10) {  
    digitalWrite(led1,HIGH); 

}
  else {
    digitalWrite(led1,LOW);

  }
  
  delay(200);
} 
