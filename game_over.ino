void game_over() {

  int winner = 0;
  
  int loser = 0;

  off_light();
  
  if(state[0] == state[1]) {
    Serial.println("Tie");
    tie_light();
  }
  else {
    if(state[0] < state[1]) {
      Serial.println("Winner is player 2");
      winner = 2;
      loser = 1;
    }
    else {
      Serial.println("Winner is player 1");
      winner = 1;
      loser = 2;
    }
    win_light(winner);
  }

  gameOver += 1;

  delay(restartDelay);
  
}

void game_restart() {

  Serial.println("Game Restart..");
  reset();
  
  restart_light();
  
}

void reset() {
  
  gameOver = 0;
  
  for(int i=0; i<2; i++) {
    state[i] = 0;
    lastShootTime[i] = 0;
  }
  
}
