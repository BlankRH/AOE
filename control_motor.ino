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
