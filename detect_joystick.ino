void detect_joystick() {
  
  int coord[2][2];

  for(int i=0; i<2; i++) {
    joystick(VRxPin[i], VRyPin[i], coord[i]);

    if(gameOver <= 0) {
      control_motor(coord[i][0], i);
      //mode1(i, coord[i]);
      mode2(i, lastYCoord[i], coord[i][1]);
    }   
    lastYCoord[i] = coord[i][1];
  }

  if(gameOver > 0 && coord[0][1] == 0 && coord[1][1] == 0) {
    game_restart();
  }

}

void mode1(int player, int *coord) {
  int currentTime = millis();
  bool loadState = (currentTime > lastShootTime[player] + coldDownTime);
  if(loadState && coord[1] == 0) {
    Serial.print("player ");
    Serial.print(player);
    Serial.println(" SHOOTING");
    activate_laser(player);
    loadState = 0;
  }
  if(!loadState && lightState[player][0]) { 
    Serial.print("player ");
    Serial.print(player);
    Serial.println(" Cold Down");
    cold_down_light(player);
  }
  else if(!loadState && !lightState[player][1]) {
    zhuci_on_light(player);
  }
  else if(loadState && !lightState[player][2]) {
    Serial.print("player ");
    Serial.print(player);
    Serial.println(" Ready");
    ready_light(player);
  }
}

void mode2(int player, int lastY, int nowY) {
  if(lastY == 1 && nowY == 0) {
    Serial.print("player ");
    Serial.print(player);
    Serial.println(" SHOOTING");
    activate_laser(player);
    //loadState = 0;
    Serial.print("player ");
    Serial.print(player);
    Serial.println(" Cold Down");
    cold_down_light(player);
  }
  else if(lastY == 0 && nowY == 1) {
    Serial.print("player ");
    Serial.print(player);
    Serial.println(" Ready");
    //loadState = 1;
    side_on_light(player);
  }
}

void joystick(int VRxPin, int VRyPin, int *coord) {
   
  int x = analogRead(VRxPin);
  int y = digitalRead(VRyPin);

  int iXCoord = map(x,0,1023,-50,50);

  coord[0] = iXCoord;
  coord[1] = y;

}
