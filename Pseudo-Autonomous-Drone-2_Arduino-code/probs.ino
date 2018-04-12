void manageProbs() {
  mapRnd();
  throwProg();
  throwTransp();
}
void  mapRnd() {
  rndA    =   map(rndMillisA, 0, 255, 1, 99);
  rndB    =   map(rndMillisB, 0, 255, 1, 99);
  rndC    =     map(rndMillisC, 0, 255, 1, 99);
}

void  throwProg() {
  //check for probability threshold
  if (rndA < currProgProb) {
    //check even or odd
    if (rndA % 2) {
      //increment
      currProg = currProg + 1;
    } else {
      //decrement if possible else increment
      if (currProg > 1) {
        currProg = currProg - 1;
      } else {
        currProg = currProg + 1;
      }
    }
    lastCurrProg = currProg;
    lcdRedraw();
  }
}
void  throwTransp() {
  //check for probability threshold
  if (rndB < currTranspProb) {
    //check even or odd
    if (rndB % 2) {
      //transpose root chord note up
      if ( currProgressionChord[0] + 12 < noteMax) {
        currProgressionChord[0] =     currProgressionChord[0] + 12;
      }
    } else {
      //transposeroot chord note down
      if ( currProgressionChord[0] - 12 > noteMin) {

        currProgressionChord[0] =    currProgressionChord[0] - 12;
      }
    }
  }
}

void  throwFifth() {

}
