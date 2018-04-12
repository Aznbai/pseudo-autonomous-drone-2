void setup()
{ 
  //Serial.begin(9600);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
    pinMode(playBtn, INPUT);
    pinMode(omniBtn, INPUT);
    pinMode(entropyBtn, INPUT);
    pinMode(screenBtn, INPUT);

  digitalWrite(S0, LOW);
  digitalWrite(S1, LOW);
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  lcd.begin (20, 4); //  our LCD is a 20x4, change for your LCD if needed
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);  // LCD Backlight ON
  lcd.setBacklight(HIGH);
  // lcd.home (); // go home on LCD
  // lcd.print("TEST THIS LCD!");
  // delay(2000);
  lcdRedraw();
  getOnce();
  Serial.begin(31250); //  Setup for MIDI baudrate:
}
