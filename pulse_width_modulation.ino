// Set input pinsx
uint8_t pinR = 3;
uint8_t pinG = 5;
uint8_t pinB = 7;

// Pulse frequency
int PWMFreq = 1000;

// Set pin channels
int PWMChannelR = 0;
int PWMChannelG = 1;
int PWMChannelB = 2;

int PWMResolution = 10;
int MAX_DUTY_CYCLE = 1023;

// initializing functions and classes: 
void setColor(int r, int g, int b, float frac);
int frac = 10;


void setup() {
  Serial.begin(9600);
  ledcSetup(PWMChannelR, PWMFreq, PWMResolution);
  ledcSetup(PWMChannelG, PWMFreq, PWMResolution);
  ledcSetup(PWMChannelB, PWMFreq, PWMResolution);

  ledcAttachPin(pinR, PWMChannelR);
  ledcAttachPin(pinG, PWMChannelG);
  ledcAttachPin(pinB, PWMChannelB);
}

void loop() {
  // random assignment of rgb
  int r = rand() % 1024;
  int g = rand() % 1024;
  int b = rand() % 1024;

  for(int dutyCycle = 0; dutyCycle <= 512; dutyCycle++){

    //setColor(r,g,b,10);
      ledcWrite(PWMChannelR, r -= frac);
      ledcWrite(PWMChannelG, g -= frac);
      ledcWrite(PWMChannelB, b -= frac);

    }
    Serial.printf("red: %d green: %d blue: %d\n", r, g, b);
    delay(2000);
}


/*int setColor(int red, int green, int blue, int frac){
  for(int i = 0; i < 100; i++){
    ledcWrite(PWMChannelR, red -= frac);
    ledcWrite(PWMChannelG, green -= frac);
    ledcWrite(PWMChannelB, blue -= frac);
    //Serial.printf("red: %d green: %d blue: %d\n", red, green, blue);
    //return red, green, blue;
  }
      return red, green, blue;

}*/