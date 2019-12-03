bool detect_light(int player) {
  
  int light = analogRead(sensorPin[player]);
  if(light > 0) {
    Serial.print(player);
  Serial.print(" ");
  Serial.println(light);
  }
  
  if(light > lightLimit) {
    Serial.println("Game Over");
    gameOver = 1;
    state[player] = -1;
  }
  
}
