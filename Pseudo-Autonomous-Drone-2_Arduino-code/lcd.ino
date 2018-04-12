
void lcdRedraw() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcdizeVal(currBpm);
  lcd.print(" ");
  lcdizeCent(currBpmProb);
  lcd.setCursor(0, 1);
  lcdizeVal(currNote);
  lcd.print(" ");
  lcdizeCent(currNoteProb);
  lcd.setCursor(0, 2);
  lcd.print(scaleMode[currScale]);
  lcd.print(" ");
  lcdizeCent(currScaleProb);
  lcd.setCursor(0, 3);
  lcdizeVal(currProg);
  lcd.print(" ");
  lcdizeCent(currProgProb);
  lcd.setCursor(13, 0);
  lcdizeCent(currFifthProb);
  lcd.print(" ");
  lcdizeCent(currTranspProb);
  lcd.setCursor(13, 1);
  lcdizeCent(currSeventhProb);
  lcd.print(" ");
  lcdizeCent(currSubstProb);
  lcd.setCursor(13, 2);
  lcdizeCent(currEleventhProb);
  lcd.print(" ");
  lcdizeCent(currMuteProb);
  lcd.setCursor(13, 3);
  //  lcdizeVal(currArp);
  lcd.print(arpMode[currArp]);
  lcd.print(" ");
  lcdizeCent(currArpProb);

  lcd.setCursor(8, 0);
  lcd.print(playMode[playState]);

  lcd.setCursor(8, 1);
  lcd.print(omniMode[omniState]);
  lcd.setCursor(8, 2);
  lcd.print(entropyMode[entropyState]);
  lcd.setCursor(8, 3);
 lcd.print(rndA);
//  lcd.print(screenMode[screenState]);


}
char lcdizeVal(byte val) {
  if (val < 100) {
    lcd.print('0');
  }
  if (val < 10) {
    lcd.print('0');
  }
  lcd.print(val);
}
char lcdizeCent(byte val) {
  if (val < 10) {
    lcd.print('0');
  }
  lcd.print(val);
  lcd.print("%");
}
