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
