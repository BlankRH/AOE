void cold_down_light(int player) {
  side_off_light(player);
}

void ready_light(int player) {
  mcp.digitalWrite(LEDPin[player][2], HIGH);
  lightState[player][2] = 1;
}

void win_light(int winner) {
  
  side_on_light(winner);
  delay(1000);
  off_light();
  delay(1000);
  side_on_light(winner);
  delay(1000);
  off_light();
  
}

void tie_light() {
  
  win_light(0);
  win_light(1);
  
}

void side_on_light(int player) {
  for(int i=0; i<3; i++) {
    mcp.digitalWrite(LEDPin[player][i], HIGH);
    lightState[player][i] = true;
  }
  Serial.print(player);
  Serial.println(" light on");
}

void zhuci_on_light(int player) {
  for(int i=0; i<1; i++)
    if(!lightState[player][i]) {
      mcp.digitalWrite(LEDPin[player][i], HIGH);
      lightState[player][i] = true;
      break;
    }
}

void side_off_light(int player) {
  for(int i=0; i<3; i++) {
    mcp.digitalWrite(LEDPin[player][i], LOW);
    lightState[player][i] = false;
  }
}

void off_light() {
  
  for(int i=0; i<2; i++)
    side_off_light(i);
      
}

void restart_light() {
  
  for(int i=0; i<2; i++)
    side_on_light(i);
      
}
