 
#define trigger 12 
#define echo 13


void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600); 
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
 
 
  
}

void loop() 
{
 int distance=getdistance();
 
 
 Serial.write("distance:");
 Serial.print(distance) ;
 Serial.write("cm\n");
 
 
 delay(1000); 
}


// distance in cm über gewöhnlichen Ultraschallsensor mit Echo und Trigger messen
int getdistance(){ 
 
 long distance=0;
 long duration=0;

 digitalWrite(trigger, LOW); 
 delayMicroseconds(3);
 digitalWrite(trigger, HIGH); //Trigger Impuls 10 us
 delayMicroseconds(10);
 digitalWrite(trigger, LOW); 
 duration = pulseIn(echo, HIGH); // Echo-Zeit messen

 
 duration = (duration/2); // Zeit halbieren
 distance = duration / 29.1; // Zeit in Zentimeter umrechnen
 return(distance); 
}
