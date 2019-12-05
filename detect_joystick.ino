void detect_joystick() {
  
  int coord[2][2];

  for(int i=0; i<2; i++) {
    joystick(VRxPin[i], VRyPin[i], coord[i]);

    if(gameOver <= 0) {
      control_motor(coord[i][0], i);

      int currentTime = millis();
      bool loadState = (currentTime > lastShootTime[i] + coldDownTime);
      if(loadState && coord[i][1] == 0) {
        Serial.print("player ");
        Serial.print(i);
        Serial.println(" SHOOTING");
        activate_laser(i);
        cold_down_light(i);
      }
      else if(!loadState && sideLightState[i]) { 
        cold_down_light(i);
      }
      else if(loadState && !sideLightState[i])
        ready_light(i);
    }   
  }

  if(gameOver > 0 && coord[0][1] == 0 && coord[1][1] == 0) {
    game_restart();
  }

}

void joystick(int VRxPin, int VRyPin, int *coord) {
   
  int x = analogRead(VRxPin);
  int y = digitalRead(VRyPin);

  int iXCoord = map(x,0,1023,-50,50);

  coord[0] = iXCoord;
  coord[1] = y;

}
