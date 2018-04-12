byte currProgressionStepMax = 3;
void manageProgressionState() {
  setCurrentProgressionStep();
  setCurrentProgressionChord();
}
void setCurrentProgressionStep() {
  if (currProgressionStep < currProgressionStepMax ) {
    currProgressionStep++;
  }
  else {
    currProgressionStep = 0;
    //    recalculate everything
  }
  //  if (currProgressionLastStep) {
  //    //recalculate and retrigger everything?
  //    //
  //    //    reset play endpont mark
  //    currProgressionLastStep = !currProgressionLastStep;
  //    //    reset to starting step
  //    currProgressionStep = 0;
  //  }
  //  else
  //  {
  //    currProgressionStep++;
  //    //  check for last step in the next tick
  //    if (currProgressionStep = (currProgressionPlayLength - 1)) {
  //      currProgressionLastStep = true;
  //    }
  //  }
}
void setCurrentProgressionChord() {
  //  copy every note
  for (byte i = 0; i < 3; i++) {
    currProgressionChord[i] = currProgressionChords[currProgressionStep][i];
  }
}
//void setCurrProgressionPlayLength() {
//}
