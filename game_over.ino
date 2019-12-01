void game_over() {

  int winner = 0;
  
  int loser = 0;
  if(state[0] == state[1]) {
    //tie_light();
    return;
  }
  if(state[0] < state[1]) {
    winner = 2;
    loser = 1;
  }
  else {
    winner = 1;
    loser = 2;
  }

  //win_light(winner);
  //lose_light(loser);

  delay(restartDelay);

}

void game_restart() {
  
  reset();
  
  //restart_light();
  
}

void reset() {
  
  gameOver = 0;
  
  for(int i=0; i<2; i++) {
    state[i] = 0;
    lastShootTime[i] = 0;
  }
  
}
