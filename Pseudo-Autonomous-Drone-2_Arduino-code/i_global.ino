const char* scaleMode[] = {"MAJ", "MIN", "HMI", "MMI"};
const char* arpMode[] = {"OFF", "INC", "DEC", "RND"};
const char* playMode[] = {"STOP", "PLAY"};
const char* entropyMode[] = {"IENT", "EENT"};
const char* omniMode[] = {"POLY","OMNI"};
const char* screenMode[] = {"MOD1", "MOD2"};
//button states
byte playState;
byte omniState;
byte entropyState;
byte screenState;
//input ranges
byte bpmMin = 1;
byte bpmMax = 255;
byte noteMin = 10;
byte noteMax = 60;
byte scaleCount = 1;
byte progCount = 32;
byte arpCount = 3;




int potValue[16];
byte potCount = 16; //number of total pots on multiplexer
//CURRENT INPUT VALUES (MAPPED AND RANGED)
byte currBpm;
byte currBpmProb;
byte currNote;
byte currNoteProb;
byte currScale;
byte currScaleProb;
byte currProg;
byte currProgProb;
byte currFifthProb;
byte currSeventhProb;
byte currEleventhProb;
byte currMuteProb;
byte currTranspProb;
byte currSubstProb;
byte currArp;
byte currArpProb;


//PULSE
boolean endOfProgressiomPlay = false;
const int pulseStateLedPin =  13;
byte rndMillisA=0;
byte rndMillisB=0;
byte rndMillisC=0;
byte rndA=0;
byte rndB=0;
byte rndC=0;
byte pulseStateLed = HIGH; // this variable is necesary to help arduino monitor the status of LED
volatile unsigned long currentMillis = 0;    // stores the value of millis() in each iteration of loop()
volatile unsigned long previousLedMillis = 0;   // will store last time the LED was updated
float pulseDuration = 10000.0;
float pulseInterval = 50000.0;
//NOTES
byte scaleMin = 0;
byte scaleMax = 1;
//SCALES
const byte scaleSteps[2][8] = {
  {0, 2, 2, 1, 2, 2, 2, 1},
  {0, 2, 1, 2, 2, 1, 2, 2}
};

byte scaleNumber = 0;
byte scaleStepsNumber = 0;
//byte currScaleNumber = 0;
//byte currScale[8] = {0, 0, 0, 0, 0, 0, 0, 0};


//CHORDS
// halftone steps for creation of chords: 0=MAJOR, 1=MINOR, 2=DIMINISHED, 3=AUGMENTED
const byte chordTriads[4][3] = {
  {0, 4, 7},
  {0, 3, 7},
  {0, 3, 6},
  {0, 4, 8}
};

//CHORD QUALITY FOR EVERY SCALE STEP 0=MAJOR, 1=MINOR, 2=DIMINISHED, 3=AUGMENTED
const byte scaleStepChordQuality[2][8] = {
  {0, 1, 1, 0, 0, 1, 2, 0},
  {1, 2, 0, 1, 1, 0, 0, 1}
};
//PROGRESSIONS
const byte progressionChordScaleSteps[33][4] = {
  {1, 5, 1, 5},
  {1, 2, 3, 4},
  {1, 2, 3, 5},
  {1, 3, 6, 5},
  {1, 6, 5, 5},
  {1, 4, 5, 5},
  {1, 2, 5, 5},
  {1, 2, 6, 5},
  {1, 3, 5, 5},
  {1, 3, 2, 5},
  {1, 2, 1, 5},
  {1, 4, 5, 5},
  {1, 4, 1, 5},
  {1, 4, 2, 5},
  {1, 4, 3, 5},
  {1, 4, 4, 5},
  {1, 4, 5, 5},
  {1, 4, 6, 5},
  {1, 3, 6, 4},
  {1, 6, 5, 4},
  {1, 4, 5, 4},
  {1, 2, 5, 4},
  {1, 2, 6, 4},
  {1, 3, 5, 4},
  {1, 3, 2, 4},
  {1, 2, 1, 4},
  {1, 4, 5, 4},
  {1, 4, 1, 4},
  {1, 4, 2, 4},
  {1, 4, 3, 4},
  {1, 4, 4, 4},
  {1, 4, 5, 4},
  {1, 4, 6, 4}
};

byte currProgressionPlayLength = 4;
byte currProgressionStep = 0;
boolean currProgressionLastStep = false;
//init start values
byte scaleAbsoluteSteps[2][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};
byte currProgressionChord[3] = {0, 0, 0};
byte currProgressionChords[4][3] = {
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
};
byte progressionAbsoluteChordScaleSteps1[4][3] = {
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
};
byte progressionAbsoluteChordScaleSteps2[4][3] = {
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
};
byte currScaleChords[8][3] = {
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
};
byte chordAbsoluteTriads1[8][3] = {
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
};
byte chordAbsoluteTriads2[8][3] = {
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
};
//ENCODER
//const int encoderPinClk = 3;
//const int encoderPinDt = 4;
//const int encoderPinSwitch = 5;
//boolean encoderDirection;
//boolean encoderSwitch = false;
//int encoderClkLast;
//int encoderClkCurr;

//MENU
//int menuValue[] = {60, 38, 0, 1, 16, 70, 501};
//int menuMinValue[] = {10, 1, 0, 0, 16, 70, 501};
//int menuMaxValue[] = {300, 128, 1, 5, 16, 70, 501};
//int currPage = 0;
//boolean menuEdit = false;
//byte  menuLength = 5;
//const char* menuHeadline[] = {
//  "BPM",
//  "NOTE",
//  "SCALE",
//  "PROGRESSION",
//  "GRID",
//  "VARIATION"
//};
//char* menuValueline[] = {
//  "120",
//  "36",
//  "minPent",
//  "16",
//  "90",
//  "MODN"
//};
