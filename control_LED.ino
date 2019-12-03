void cold_down_light(int player) {
  for(int i=0; i<3; i++)
    mcp.digitalWrite(LEDPin[player][i], LOW);
}
void ready_light(int player) {
  for(int i=0; i<3; i++)
    mcp.digitalWrite(LEDPin[player][i], HIGH);
}

void win_light(int winner) {
  
  for(int i=0; i<3; i++)
    mcp.digitalWrite(LEDPin[winner][i], HIGH);
  delay(1000);
  off_light();
  delay(1000);
  for(int i=0; i<3; i++)
    mcp.digitalWrite(LEDPin[winner][i], HIGH);
  delay(1000);
  off_light();
  
}

void tie_light() {
  
  win_light(0);
  win_light(1);
  
}

void off_light() {
  
  for(int i=0; i<2; i++)
    for(int j=0; j<3; j++)
      mcp.digitalWrite(LEDPin[i][j], LOW);
      
}

void restart_light() {
  
  for(int i=0; i<2; i++)
    for(int j=0; j<3; j++)
      mcp.digitalWrite(LEDPin[i][j], HIGH);
      
}
