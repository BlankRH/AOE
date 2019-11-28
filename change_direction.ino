void change_direction(int iXCoord,int player) {

  int speed;
  
  if(iXCoord > -1)
    speed = absSpeed;
  else if(iXCoord< -1)
    speed = -absSpeed;
    
  set_motor_pwm(speed, motorPin[player][0], motorPin[player][1]);
  
}
