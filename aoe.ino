#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp;

/*
const int VRxPin1 = A0;//0，-1
const int VRyPin1 = A4;
const int VRxPin2 = A1;//-1，-1
const int VRyPin2 = A5;
const int motorPin1A = 2;
const int motorPin1B = 3;
const int motorPin2A = 4;
const int motorPin2B = 5;
const int laserPin1 = 8;
const int laserPin2 = 9;
const int sensorPin1 = A2;
const int sensorPin2 = A3; 
*/

const int VRxPin[2] = {A0, A1};
const int VRyPin[2] = {A4, A5};
const int motorPin[2][2] = {2, 3, 4, 5};// motorPin[1/2][A/B]
const int laserPin[2] = {8, 9};
const int sensorPin[2] = {A2, A3};
const int LEDPin[2][3];

/*
const int LEDPin1A;
const int LEDPin1B;
const int lEDPin1C;
const int LEDPin2A;
const int LEDPin2B;
const int LEDPin2C;
*/

const int absSpeed = 255;
const int lightLimit = 300;
const int shootTime = 200;
const int restartDelay = 10000;
const int coldDownTime = 3000;

bool gameOver = 0;
int state[2] = {0};
int lastShootTime[2] = {-3000, -3000};

void setup() {

  for(int i=0; i<2; i++) {
    for(int j=0; j<2; j++)
      pinMode(motorPin[i][j], OUTPUT);
    for(int j=0; j<3; j++)
      pinMode(LEDPin[i][i], OUTPUT);
    pinMode(laserPin[i], OUTPUT);
  }

  mcp.begin();
  /*
   * Set up pin modes for all GPIO
   * mcp.pinMode(0, OUTPUT);
   */
  
  Serial.begin(9600);
}

void loop() {
  
  detect_joystick();
  /*
   * mcp methods
   * mcp.digitalWrite()
   */

  
  for(int i=0; i<2; i++) {
    stop_laser(i);
    detect_light(i);
  }
  
  if(gameOver) 
    game_over();
    
}
