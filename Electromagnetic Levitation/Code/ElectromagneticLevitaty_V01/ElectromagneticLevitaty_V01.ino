#define VERSION             0.1

#define MAG_THRESHOLD       200
#define OSCILLATION_TIME    5000

#define ELECTROMAGNET_LED   22
#define ELECTROMAGNET       23
#define ELECTROMAGNET_PIN   2
#define ELECTROMAGNET_LED_PIN 1
#define PHOTOCELL           14

// the setup routine runs once when you press reset:
void setup() { 
  Serial.begin(9600);               
  // initialize the digital pin as an output.
  pinMode(ELECTROMAGNET_LED, OUTPUT);     
  pinMode(ELECTROMAGNET, OUTPUT);
  pinMode(PHOTOCELL, INPUT);

  Serial.println("================================================");
  Serial.println("ELECTROMAGNET LEVITATION");
  Serial.print("VERSION: ");Serial.println(VERSION);
  Serial.println("================================================");

}

// the loop routine runs over and over again forever:
void loop() {
  
  //Serial.println(analogRead(PHOTOCELL));
  //delay(100);
  
  
  //pulsingElectromagnet();
  
  
  uint16_t currentReading = analogRead(PHOTOCELL);
  if(currentReading < MAG_THRESHOLD){
    //PORTC |= (1<<ELECTROMAGNET_PIN);
    //PORTC |= (1<<ELECTROMAGNET_LED_PIN);
    digitalWrite(ELECTROMAGNET_LED, HIGH);   
    digitalWrite(ELECTROMAGNET, HIGH); 
  } else {
    //PORTC &= ~(1<<ELECTROMAGNET_PIN);
    //PORTC &= ~(1<<ELECTROMAGNET_LED_PIN);
    digitalWrite(ELECTROMAGNET_LED, LOW); 
    digitalWrite(ELECTROMAGNET, LOW);
  }
  
}

void pulsingElectromagnet(){
  digitalWrite(ELECTROMAGNET_LED, HIGH);   
  digitalWrite(ELECTROMAGNET, HIGH);
  //PORTC |= (1<<ELECTROMAGNET_PIN);
  //PORTC |= (1<<ELECTROMAGNET_LED_PIN);
  delayMicroseconds(OSCILLATION_TIME);
  digitalWrite(ELECTROMAGNET_LED, LOW); 
  digitalWrite(ELECTROMAGNET, LOW);
  //PORTC &= ~(1<<ELECTROMAGNET_PIN);
  //PORTC &= ~(1<<ELECTROMAGNET_LED_PIN);
  delayMicroseconds(OSCILLATION_TIME * 1.5);
}

