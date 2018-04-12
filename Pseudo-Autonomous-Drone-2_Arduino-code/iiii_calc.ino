//calculate fresh scale, chord, progression values based on unser input
void calculateBaseData() {
  getAbsoluteScales();
  getCurrentScaleChords();
  getScaleChordProgressions();
  //  manageProgressionState();
  //  getAbsoluteScalesChords();
}

//get current absolute value for every scale, based on currNote
void getAbsoluteScales() {
  // i is current scale
  for (byte i = 0; i < scaleNumber; i++) {
    //  accumulates the halftonsteps as we iterate thru a scale
    byte stepAccumulator = 0;
    // j is current scale step (in current i-scale)
    for (byte j = 0; j < scaleStepsNumber; j++) {
      scaleAbsoluteSteps[i][j] = currNote + scaleSteps[i][j] + stepAccumulator;
      stepAccumulator += scaleSteps[i][j];
    }
  }
}

//based on absolute values of current scale
void getCurrentScaleChords() {
  byte currentChordQuality = 0;
  byte currentChordNoteStep = 0;
  // j is current scale step
  for (byte j = 0; j < scaleStepsNumber; j++) {
    // k is current chord note
    for (byte k = 0; k < 3; k++) {
      // chord quality for current scale step
      currentChordQuality = scaleStepChordQuality[currScale][j];
      // current chord note interval
      currentChordNoteStep = chordTriads[currentChordQuality][k];
      currScaleChords[j][k] = scaleAbsoluteSteps[currScale][j] + currentChordNoteStep;
    }
  }
}

void getScaleChordProgressions() {
  // j is progression step counter
  for (byte j = 0; j < 5; j++) {
    // k is current note of a tranferable chord
    for (byte k = 0; k < 4; k++) {
      currProgressionChords[j][k] = currScaleChords[progressionChordScaleSteps[currProg][j] - 1][k];
    }
  }
}
