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

const unsigned seq1[]  = {500,484,508,480,508,484,508,480,512,476,512,480,508,480,512,480,508,480,512,476,512,476,512,480,512,476,512,476,516,476,512,476,516,476,512,476,512,476,516,476,516,472,516,472,520,472,516,472,516,476,520,468,516,476,516,472,520,468,516,476,516,472,520,472,520,468,516,468,2060,968,524,472,528,464,1024,968,524,468,1024,964,1028,468,528,468,528,464,528,964,524,468,528,468,1024,964,1028,468,528,960,1028,960,528,468,524,468,524,476,516,472,520,476,528,468,528,460,528,468,532,460,1028,468,528,468,528,960,1028,960,2564,964,528,464,532,464,1028,960,536,464,1028,960,1028,468,524,468,528,468,528,960,532,464,532,464,1024,964,1028,468,528,960,1028,964,528,464,532,464,528,468,528,464,532,464,532,464,528,460,532,464,532,464,1024,468,532,464,528,960,1028,964,26412};
const unsigned seq2[]  = {508,476,516,472,516,476,516,472,516,476,516,472,516,472,520,472,516,472,520,472,516,472,520,472,516,472,520,468,520,472,516,472,520,472,516,472,520,472,516,472,520,468,520,472,520,468,516,476,516,472,520,472,516,472,520,468,520,472,516,472,520,472,520,468,520,468,524,460,2064,472,528,960,532,464,1024,964,524,472,1024,964,1028,468,524,472,528,464,532,960,524,468,524,472,1020,968,1024,472,524,964,1028,960,528,468,528,464,532,464,528,464,532,464,528,468,532,456,528,468,524,468,532,464,528,468,524,468,532,464,1024,964,2556,476,524,964,528,464,1020,968,524,472,1020,968,1020,476,520,476,520,472,520,968,524,472,520,476,1020,968,1020,472,524,968,1020,968,520,476,520,472,524,472,520,476,520,472,524,472,520,468,524,472,520,472,524,472,524,472,520,472,524,472,1020,968,15976};


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
