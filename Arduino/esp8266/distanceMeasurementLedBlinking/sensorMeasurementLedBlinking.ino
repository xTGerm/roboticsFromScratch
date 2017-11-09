#define trigPin 12
#define echoPin 13
#define led1 LED_BUILTIN

long duration, distance;
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);


}

void loop() {
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  Serial.println("distance : " + String(distance) + "cm");
  
  if (distance < 10) {  
    digitalWrite(led1,HIGH); 

}
  else {
    digitalWrite(led1,LOW);

  }
  
  delay(200);
} 
