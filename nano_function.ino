/*--------------------------------------------------------
   割り込みに使う関数
  ---------------------------------------------------------*/
void changePWM() {
  pid_r.update_conVar(r);
  pid_l.update_conVar(l);
  /*Serial.print("Rpwm = ");
  Serial.print(pid_r.get_conVar());
  Serial.print(", R_rotation = ");
  Serial.print(r);
  Serial.print("  Lpwm = ");
  Serial.print(pid_l.get_conVar());
  Serial.print(", L_rotation = ");
  Serial.println(l);*/
  r = 0; l = 0;
  motor_r.rotationNormal_p(pid_r.get_conVar());
  motor_l.rotationNormal_p(pid_l.get_conVar());
}

/*----------------------------------------
 *  スタック判定時の挙動(その場で旋回)
----------------------------------------- */
void stackMove(){
  motor_r.stop();
  motor_l.stop();
  motor_r.rotationNormal();
  motor_l.rotationInvert();
  delay(1000);
  motor_r.rotationInvert();
  motor_l.rotationNormal();
  delay(1000);
  motor_r.stop();
  motor_l.stop();
}

