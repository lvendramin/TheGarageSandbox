int pinP = 3;
int pinA = 4;
int pinB = 5;
int pinC = 6;
int pinD = 8;
int pinE = 9;
int pinF = 10;
int pinG = 11;

int pins[8] = {pinP, pinA, pinB, pinC, pinD, pinE, pinF, pinG};

int NUMBERS[10][8] = {{0,1,1,1,1,1,1,0}, //0
                      {0,0,1,1,0,0,0,0}, //1
                      {0,1,1,0,1,1,0,1}, //2
                      {0,1,1,1,1,0,0,1}, //3
                      {0,0,1,1,0,0,1,1}, //4
                      {0,1,0,1,1,0,1,1}, //5
                      {0,1,0,1,1,1,1,1}, //6
                      {0,1,1,1,0,0,0,0}, //7
                      {0,1,1,1,1,1,1,1}, //8
                      {0,1,1,1,1,0,1,1} //9
                      };

int LETTERS[10][8] = {{0,1,1,1,0,1,1,1}, //A
                      {0,0,0,1,1,1,1,1}, //B
                      {0,1,0,0,1,1,1,0}, //C
                      {0,0,1,1,1,1,0,1}, //D
                      {0,1,0,0,1,1,1,1}, //E
                      {0,1,0,0,0,1,1,1}, //F
                      };


void setup() {
  Serial.begin(9600);
  
  for (int i=0; i < 8; i++) {
    pinMode(pins[i], OUTPUT);
  }
  
  int initializeHIGH[8] = {1,1,1,1,1,1,1};
  
  showInitialization();  
}

void loop() {
  for (int i = 0; i < 10; i++) {
    showDisplay(NUMBERS[i], 250);    
  }
  for (int i = 0; i < 10; i++) {
    showDisplay(LETTERS[i], 250);
  }
}

void showInitialization() {
  
  //Set all pins to HIGH
  for (int i=0; i < 8; i++) {
    digitalWrite(pins[i], 1);
  }
  
  delay(1000);

  //Set all pins to HIGH
  for (int i=0; i < 8; i++) {
    digitalWrite(pins[i], 0);
  }
  
  //round and round
  changeSegment(7, 0);
  changeSegment(0, 1);
  
  for (int r = 0; r < 3; r++) {
    
    for (int i=1; i < 7; i++) {
      if (i == 1) {
        changeSegment(i, 1);
      } else {
        changeSegment(i-1, 0);
        changeSegment(i, 1);
      }
      
      if (i % 2) {
        changeSegment(0, 0);        
      } else {        
        changeSegment(0, 1);
      }
    }  
    
    changeSegment(6, 0);
  }
}

void showDisplay(int display[], int d) {
  
  //Set all pins to ZERO
  for (int i=0; i < 8; i++) {
    digitalWrite(pins[i], 0);
  }
  
  delay(d);
  
  if (display != 0) {
    //Write the given values
    for (int i=0; i < 8; i++) {
      Serial.println(display[i]);
      digitalWrite(pins[i], display[i]);
    }
  }
  delay(d);
}

void changeSegment(int seg, int value) {
  digitalWrite(pins[seg], value);
  delay(50);
}

