# noolite_replay
Emulate Noolite remote  by Arduino and cheap 433 MHz RC transmitter


This project aims to replay Noolite remote RC sequences. Sequences should be captured in advance by noolite_scan.ino sketch. Noolite remotes have two RC codes for the each button and you shold run noolite_scan.ino twice.

## How to use it.

1. Plug the RC receiver to PIN 2 of your Arduino. Run oolite_scan.ino sketch and open the serial monitor.
2. Press the button of Noolite remote, reset Arduino or tuen it off and on.
3. Repeat step 2 to scan second RC sequence of the button

## Then

4. Copy output of noolite_scan.ino to seq1 and seq2 arrays of noolite_replay.ino
5. Plug the RC transmittert to PIN 4 of Arduino
6. Run noolite_replay.ino to automate of pressing specified button
