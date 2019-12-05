#include "Adafruit_MCP23017.h"
#include <Wire.h>

Adafruit_MCP23017 mcp;

const int VRxPin[2] = {A2, A3};
const int VRyPin[2] = {3, 2}; //A1
const int motorPin[2][2] = {4, 5, 6, 7};// motorPin[1/2][A/B]
const int laserPin[2] = {8, 9};
const int sensorPin[2] = {A0, A1};
const int LEDPin[2][3] = {9, 10, 11, 12, 13, 14};

const int absSpeed = 255;
const int lightLimit = 830;
const int shootTime = 300;
const int coldDownTime = 1500;
const int restartDelay = 5000;

int gameOver = 0;
int state[2] = {0};
int lastShootTime[2] = {0, 0};
bool sideLightState[2] = {0, 0};

void setup() {

  mcp.begin();
  
  for(int i=0; i<2; i++) {
    for(int j=0; j<2; j++)
      pinMode(motorPin[i][j], OUTPUT);
    for(int j=0; j<3; j++)
      mcp.pinMode(LEDPin[i][j], OUTPUT);
    pinMode(laserPin[i], OUTPUT);
    pinMode(VRyPin[i], INPUT);
  }
  
  Serial.begin(9600);

}

void loop() {
  
  test();
  main();
  
}

void main() {
  
  detect_joystick();
  
  for(int i=0; i<2; i++) {
    stop_laser(i);
    detect_light(i);
  }
  
  if(gameOver == 1) 
    game_over();
    
}
