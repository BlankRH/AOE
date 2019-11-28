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
