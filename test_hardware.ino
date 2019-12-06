void test() {
  //test_joystick();
  //side_on_light(0);
  //side_on_light(1);
  //side_off_light(0);
  //side_off_light(1);
  //test_motor_both();
  //test_motor_side(0);
  //test_motor_side(1);
  //activate_laser(0);
  //activate_laser(1);
  //stop_laser(0);
  //stop_laser(1);
  test_control_motor();
  //test_sensor();
}

void test_sensor() {
  for(int i=0; i<2; i++) {
    int read = analogRead(sensorPin[i]);
    Serial.print("Sensor ");
    Serial.print(i+1);
    Serial.print(" : ");
    Serial.println(read);
  }
}

void test_control_motor() {
  int coord[2][2];
  for(int i=0; i<2; i++) {
    joystick(VRxPin[i], VRyPin[i], coord[i]);
    control_motor(coord[i][0], i);
  }
}

void test_motor_both() {
  for(int i=0; i<2; i++) 
    set_motor_pwm(absSpeed, motorPin[i][0], motorPin[i][1]);
}

void test_motor_side(int player) {
  set_motor_pwm(absSpeed, motorPin[player][0], motorPin[player][1]);
}

void test_joystick() {

  int coord[2][2];
  
  for(int i=0; i<2; i++) {
    joystick(VRxPin[i], VRyPin[i], coord[i]);
  }

  test_print_joystick(coord[0][0], coord[0][1], coord[1][0], coord[1][1]);
}

void test_print_joystick(int iX1, int iY1, int iX2, int iY2) {
  
  Serial.print("VRrx11 = ");
  Serial.print(iX1);
  Serial.print("\tVRry12 = ");
  Serial.print(iY1);
  Serial.print("\n");
  Serial.print("VRrx21 = ");
  Serial.print(iX2);
  Serial.print("\tVRry22 = ");
  Serial.print(iY2);
  Serial.print("\n");
}
