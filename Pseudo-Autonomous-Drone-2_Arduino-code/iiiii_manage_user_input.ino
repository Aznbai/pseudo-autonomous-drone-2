byte lastCurrBpm;
byte lastCurrBpmProb;
byte lastCurrNote;
byte lastCurrNoteProb;
byte lastCurrScale;
byte lastCurrScaleProb;
byte lastCurrProg;
byte lastCurrProgProb;
byte lastCurrFifthProb;
byte lastCurrSeventhProb;
byte lastCurrEleventhProb;
byte lastCurrMuteProb;
byte lastCurrTranspProb;
byte lastCurrSubstProb;
byte lastCurrArp;
byte lastCurrArpProb;
byte lastPlayState;
byte lastOmniState;
byte lastEntropyState;
byte lastScreenState;

byte  currBpmVal  ;
byte  currNoteVal  ;
byte  currScaleVal ;
byte  currProgressionVal  ;
byte  currChordVal  ;
byte  currArpVal;

void getBtns() {
  if (digitalRead(playBtn)) {
    playState = 1;
  }
  else {
    playState = 0;
  }

  if (digitalRead(omniBtn)) {
    omniState = 1;
  }
  else {
    omniState = 0;
  }

  if (digitalRead(entropyBtn)) {
    entropyState = 1;
  }
  else {
    entropyState = 0;
  }

  if (digitalRead(screenBtn)) {
    screenState = 1;
  }
  else {
    screenState = 0;
  }

}

void getOnce() {
  scaleNumber = sizeof(scaleSteps) / sizeof(scaleSteps[0]); //calc number of scales
  scaleStepsNumber = sizeof(scaleSteps[0]); //calc number of scale steps
}
void manageUserInput() {

  //update last vals
  lastCurrBpm = currBpm;
  lastCurrBpmProb = currBpmProb;
  lastCurrNote = currNote;
  lastCurrNoteProb = currNoteProb;
  lastCurrScale = currScale;
  lastCurrScaleProb = currScaleProb;
  lastCurrProg = currProg;
  lastCurrProgProb = currProgProb;
  lastCurrFifthProb = currFifthProb;
  lastCurrSeventhProb = currSeventhProb;
  lastCurrEleventhProb = currEleventhProb;
  lastCurrMuteProb = currMuteProb;
  lastCurrTranspProb = currTranspProb;
  lastCurrSubstProb = currSubstProb;
  lastCurrArp = currArp;
  lastCurrArpProb = currArpProb;
  lastPlayState = playState;
  lastOmniState = omniState;
  lastEntropyState = entropyState;
  lastScreenState = screenState;
    //get button states
  getBtns();
  //get and map new analog multiplexer values input values
  getPotValues();
  mapPotValues();

  //  serialPotValues();

  //check for UI (analog multiplexer) changes and recalculate if needed
  if (lastCurrBpm != currBpm ||
      lastCurrBpmProb != currBpmProb ||
      lastCurrNote != currNote ||
      lastCurrNoteProb != currNoteProb ||
      lastCurrScale != currScale ||
      lastCurrScaleProb != currScaleProb ||
      lastCurrProg != currProg ||
      lastCurrProgProb != currProgProb ||
      lastCurrFifthProb != currFifthProb ||
      lastCurrSeventhProb != currSeventhProb ||
      lastCurrEleventhProb != currEleventhProb ||
      lastCurrMuteProb != currMuteProb ||
      lastCurrTranspProb != currTranspProb ||
      lastCurrSubstProb != currSubstProb ||
      lastCurrArp != currArp ||
      lastCurrArpProb != currArpProb ||
      lastPlayState != playState ||
      lastOmniState != omniState ||
      lastEntropyState != entropyState ||
      lastScreenState != screenState) {
    calculateBaseData();
    lcdRedraw();
    // delay(100);
  }
}



void getPotValues() {
  for (int i = 0; i < potCount; i ++) {
    potValue[i] = readMux(i) / 5;
  }
}
void mapPotValues() {
  //  map(value, fromLow, fromHigh, toLow, toHigh)

  currBpm = map(potValue[15], 0, 204, bpmMin, bpmMax); //
  currNote = map(potValue[13], 0, 204, noteMin, noteMax);
  currScale = map(potValue[11], 0, 204, 0, scaleCount);
  currProg = map(potValue[9], 0, 204, 0, progCount); //rv //
  currArp = map(potValue[1], 0, 204, 0, arpCount);
  currBpmProb = map(potValue[14], 0, 204, 0, 99); //
  currNoteProb = map(potValue[12], 0, 204, 0, 99);
  currScaleProb = map(potValue[10], 0, 204, 0, 99); //
  currProgProb = map(potValue[8], 0, 204, 0, 99);  //
  currFifthProb = map(potValue[7], 0, 204, 0, 99); //
  currSeventhProb = map(potValue[5], 0, 204, 0, 99); //
  currEleventhProb = map(potValue[3], 0, 204, 0, 99); //
  currMuteProb = map(potValue[2], 0, 204, 0, 99);
  currTranspProb = map(potValue[6], 0, 204, 0, 99); //
  currSubstProb = map(potValue[4], 0, 204, 0, 99);
  currArpProb = map(potValue[0], 0, 204, 0, 99);
}



int readMux(byte channel) {
  byte controlPin[] = {S0, S1, S2, S3};
  byte muxChannel[16][4] = {
    {0, 0, 0, 0}, //channel 0
    {1, 0, 0, 0}, //channel 1
    {0, 1, 0, 0}, //channel 2
    {1, 1, 0, 0}, //channel 3
    {0, 0, 1, 0}, //channel 4
    {1, 0, 1, 0}, //channel 5
    {0, 1, 1, 0}, //channel 6
    {1, 1, 1, 0}, //channel 7
    {0, 0, 0, 1}, //channel 8
    {1, 0, 0, 1}, //channel 9
    {0, 1, 0, 1}, //channel 10
    {1, 1, 0, 1}, //channel 11
    {0, 0, 1, 1}, //channel 12
    {1, 0, 1, 1}, //channel 13
    {0, 1, 1, 1}, //channel 14
    {1, 1, 1, 1} //channel 15
  };
  //loop through the 4 sig
  for (byte i = 0; i < 4; i ++) {
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }
  int val = analogRead(SIG);
  return val;
}
