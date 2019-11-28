void detect_joystick() {
  
  int coord[2][2]; // coord[1/2][x/y]

  for(int i=0; i<2; i++) {
    joystick(VRxPin[i], VRyPin[i], coord[i]);

    if(!gameOver) {
      change_direction(coord[i][0], i);

      if(millis() > lastShootTime[i] + coldDownTime && coord[i][1] > -1) 
        activate_laser(i); /*
      else if(millis() < lastShootTime[i] + coldDownTime)
        cold_down_light(i);
      else if(millis() > lastShootTime[i] + coldDownTime)
        ready_light(i);*/
    }   
  }

  if(gameOver && coord[0][1] > -1 && coord[1][1] > -1) {
    game_restart();
  }
    
  //test_print_joystick(coord[0][0], coord[0][1], coord[1][0], coord[1][1]);
}

void joystick(int VRxPin, int VRyPin, int *coord) {
   
  int x = analogRead(VRxPin);
  int y = analogRead(VRyPin);

  int iXCoord = map(x,0,1023,-2,2);
  int iYCoord = map(y,0,1023,-2,2);

  coord[0] = iXCoord;
  coord[1] = iYCoord;

}

void test_print_joystick(int iX1, int iY1, int iX2, int iY2) {
  Serial.print("VRrx11 = ");
  Serial.print(iX1);
  Serial.print("\tVRry12 = ");
  Serial.print(iY1);
  Serial.print("\n");
  Serial.print("VRrx21 = ");
  Serial.print(iX2);
  Serial.print("\tVRry22 = ");
  Serial.print(iY2);
  Serial.print("\n");
}
