void activate_laser(int player) {
 
  digitalWrite(laserPin[player], HIGH);
  lastShootTime[player] = millis();
  
}

void stop_laser(int player) {

  int currentTime = millis();
  if(gameOver > 0 || currentTime > lastShootTime[player] + shootTime){
    digitalWrite(laserPin[player], LOW);
  }
  
}
