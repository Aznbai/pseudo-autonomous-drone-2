
void loop()
{
  //currentMillis = millis();   // capture the latest value of millis()
  currentMillis = micros();   // capture the latest value of millis()
  rndMillisA = micros();   // capture the latest value of millis()

  //  lcdRedraw();
  //  delay(500);
  //  manageProgressionState();
  manageTimerState(); //checks time, manages pulses and pauses.triggers managePulseInterval(), managePulseDuration()
  rndMillisB = micros();   // capture the latest value of millis()
  manageUserInput(); // refreshes input, checks for changes , TODO: triggers recalculation if needed;
  rndMillisC = micros();   // capture the latest value of millis()
}
