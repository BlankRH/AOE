void activate_laser(int player) {
  
  digitalWrite(laserPin[player], HIGH);
  lastShootTime[player] = millis();
}

void stop_laser(int player) {
  
  if(millis() > lastShootTime[player] + shootTime)
    digitalWrite(laserPin[player], LOW);
}
