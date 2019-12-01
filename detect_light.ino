bool detect_light(int player) {
  
  int light = analogRead(sensorPin[player]);
  
  if(light > lightLimit) {
    gameOver = 1;
    state[player] = -1;
  }
  
}
