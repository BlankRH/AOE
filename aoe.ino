#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp;

const int VRxPin[2] = {A2, A3};
const int VRyPin[2] = {2, 3};
const int motorPin[2][2] = {4, 5, 6, 7};// motorPin[1/2][A/B]
const int laserPin[2] = {8, 9};
const int sensorPin[2] = {A0, A1};
const int LEDPin[2][3] = {9, 10, 11, 12, 13, 14};

const int absSpeed = 255;
const int lightLimit = 80;
const int shootTime = 200;
const int coldDownTime = 500;

bool gameOver = 0, restart = 0;
int state[2] = {0};
int lastShootTime[2] = {-coldDownTime, -coldDownTime};

void setup() {

  mcp.begin();
  
  for(int i=0; i<2; i++) {
    for(int j=0; j<2; j++)
      pinMode(motorPin[i][j], OUTPUT);
    for(int j=0; j<3; j++)
      mcp.pinMode(LEDPin[i][j], OUTPUT);
    pinMode(laserPin[i], OUTPUT);
    pinMode(sensorPin[i], OUTPUT);
  }
  
  Serial.begin(9600);
  
}

void loop() {
  
  detect_joystick();

  for(int i=0; i<2; i++) {
    stop_laser(i);
    detect_light(i);
  }

  //Serial.print(millis());
  
  if(gameOver && !restart) 
    game_over();
    
}
