 
#define trigger 12 // Arduino Pin an HC-SR04 Trig
#define echo 13    // Arduino Pin an HC-SR04 Echo


void setup()
{
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trigger, HIGH); //Signal abschalten
 
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
}

void loop() // Arduino Hauptschleife
{
 int distance=getdistance();
 
 
 Serial.write("distance:");
 Serial.print(distance) ;
 Serial.write("cm\n");
 
 delay(1000); //1 Sekunde warten
}


// Entfernung in cm über gewöhnlichen Ultraschallsensor mit Echo und Trigger messen
int getdistance(){ 
 
 long distance=0;
 long zeit=0;

 digitalWrite(trigger, LOW); 
 delayMicroseconds(3);
 noInterrupts();
 digitalWrite(trigger, HIGH); //Trigger Impuls 10 us
 delayMicroseconds(10);
 digitalWrite(trigger, LOW); 
 zeit = pulseIn(echo, HIGH); // Echo-Zeit messen
 interrupts(); 
 
 zeit = (zeit/2); // Zeit halbieren
 distance = zeit / 29.1; // Zeit in Zentimeter umrechnen
 return(distance); 
}
