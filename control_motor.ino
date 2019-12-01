void change_direction(int iXCoord,int player) {

  int speed;
  
  if(iXCoord > -1)
    speed = absSpeed;
  else if(iXCoord< -1)
    speed = -absSpeed;
    
  set_motor_pwm(speed, motorPin[player][0], motorPin[player][1]);
  
}

void set_motor_pwm(int pwm, int INA_PIN, int INB_PIN) {
  
  if(pwm < 0) {
    digitalWrite(INB_PIN, LOW);
    analogWrite(INA_PIN, -pwm);
  }
  else {
    digitalWrite(INA_PIN, LOW);
    analogWrite(INB_PIN, pwm);
  }
  
}
