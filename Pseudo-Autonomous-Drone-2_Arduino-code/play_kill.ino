void playCurrentChord() {
  //  for every chord note
  for (byte i = 0; i < sizeof(currProgressionChord); i++) {
    // for (byte i = 0; i < 3; i++) {
    //    play on the next channel
    noteOn(0x90 + i, currProgressionChord[i], 0x50);
  }
}
void killCurrentChord() {
  //  for every chord note
  for (byte i = 0; i < sizeof(currProgressionChord); i++) {
    //for (byte i = 0; i < 3; i++) {
    //    kill on the next channel
    noteOn(0x90 + i, currProgressionChord[i], 0x00);
  }
}

//  play MIDI note.  TODO : if cmd is greater than 127, or that data values are  less than 127:
void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
