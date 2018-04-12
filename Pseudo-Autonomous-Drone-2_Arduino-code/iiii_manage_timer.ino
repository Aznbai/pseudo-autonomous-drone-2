void manageTimerState() {
  //currentMillis = millis();   // capture the latest value of millis()
  currentMillis = micros();   // capture the latest value of millis()
  //if play button is pressed
  if (playState > 0) {
    if (pulseStateLed == LOW) {
      managePulseInterval();
    }
    else {
      managePulseDuration();
    }
  }
}
void managePulseInterval() {
  pulseCalcInterval();
  if ((unsigned long) currentMillis - previousLedMillis >= pulseInterval) {
    manageProgressionState();
    manageProbs();

    //    serialCurrentProgressionStep();
    //    serialCurrentChord();
    playCurrentChord();
    pulseStateLed = HIGH;
    digitalWrite(pulseStateLedPin, pulseStateLed);
    previousLedMillis += pulseInterval;
    // NOTE: The previous line could alternatively be
    //        previousLedMillis = currentMillis
    //        Adding on the pulseInterval is a better way to ensure that succesive periods are identical

  }
}

void  managePulseDuration() {
  if ((unsigned long) currentMillis - previousLedMillis >= pulseDuration) {
    killCurrentChord() ;
    pulseStateLed = LOW;
    digitalWrite(pulseStateLedPin, pulseStateLed);
    previousLedMillis += pulseDuration;
    // NOTE: The previous line could alternatively be
    // previousLedMillis = currentMillis  Adding on the duration is a better way to ensure that succesive periods are identical

  }
}
void pulseCalcInterval() {
  // pulseInterval = 60.0/ menuValue[0] * 1000;
  /// pulseInterval = (1.0 / menuValue[0]) * 60.0 * 1000.0;
  pulseInterval = (1.0 / currBpm) * 60.0 * 1000000.0;
}
