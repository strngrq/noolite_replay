#define SAMPLESIZE 500

static unsigned int timings[SAMPLESIZE];
static unsigned int pos = 0;
static unsigned long lastTime = 0;

static int receiverPin = 2;
static int interruptPin = 0;

void setup() {
  interruptPin = digitalPinToInterrupt(receiverPin);
  Serial.begin(9600); 
    pinMode(5, OUTPUT);
    digitalWrite(5, HIGH);  
}

inline int checkLength(long v){
  return (v>440 && v<550)?1:0;
}


void loop() {
     Serial.print("Press a button on the Noolite remote... ");
     
    while(1) 
      if(checkLength(pulseIn(receiverPin,LOW)) && checkLength(pulseIn(receiverPin,HIGH))) break;
    pulseIn(receiverPin,HIGH); // waitong for sync ( 500us pulses)
 
    attachInterrupt(interruptPin, handleInterrupt, CHANGE);

      Serial.print("... ");
      delay(1000);
    
    Serial.println("Done");    
    detachInterrupt(interruptPin);
     
    for (unsigned int i = 0; i < pos; i++) {
      Serial.print( timings[i] );
      Serial.print(",");
    }

    Serial.println("");
    Serial.println("Reset your Arduino to scan again...");

    while(true) {} 
  
}

void handleInterrupt() {
  const long time = micros();
  long v = time - lastTime;
  if(v>300 && v < 4000) timings[pos++] = v;
  lastTime = time;
  if ((pos > SAMPLESIZE-1) || (pos > 100 && (v< 300 || v > 4000) )) {
     detachInterrupt(interruptPin);
  }
}
