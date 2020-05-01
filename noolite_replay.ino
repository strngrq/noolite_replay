// 
// Emulate Noolite by cheap RC transmitter and receiver
//
// This sketch replays RC sequence captured by noolite_scan.ino sketch. Noolite remotes have two RC codes for the each button. 
// 1. Plug the RC receiver to PIN 2 of your Arduino. Run oolite_scan.ino sketch and open the serial monitor.
// 2. Press the button of Noolite remote, reset Arduino or tuen it off and on.
// 3. Repeat step 2 to scan second RC sequence of the button
//
// 4. Copy output of noolite_scan.ino to seq1 and seq2 arrays of noolite_replay.ino
// 5. Plug the RC transmittert to PIN 4 of Arduino
// 6. Run noolite_replay.ino to automate of pressing specified button


#define RC_TX_PIN 4

const unsigned seq1[]  = {500,484,508,480,508,484,508,480,512,476,512,480,508,480,512,480,508,26412};
const unsigned seq2[]  = {508,476,516,472,516,476,516,472,516,476,516,472,516,472,520,472,516,472,520,472,516,472,520,472,516,472,520,468,520,472,516,472,520,472,516,472,520,472,516,472,520,468,15976};


void setup() {
  pinMode(RC_TX_PIN, OUTPUT);
  Serial.begin(9600);
}


void sendSignal(const unsigned *seq, unsigned s){
  int state=0;
  for(int i=0 ; i < s ; i++){
    digitalWrite(RC_TX_PIN, state);
    delayMicroseconds(seq[i]);
    state = !state; 
  }  
  digitalWrite(RC_TX_PIN, 0);
}


void loop() {

  sendSignal(seq1,sizeof(seq1)/sizeof(unsigned));

  Serial.println("Turn off...");

  delay(2000);

  Serial.println("Turn on...");

  sendSignal(seq2,sizeof(seq2)/sizeof(unsigned));

  delay(2000);
}
