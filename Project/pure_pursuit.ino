/*// Following plan B. pure pursuit for wheel case
void pure_pursuit()
{
  //if((square(x - way_pointX[9])+square(y - way_pointY[9]) < square(0.05)))  {if(turn(0))  pwm_control(0,0);return;} // If distance to the last way point 
                                                                                                                      // less than 5cm, turn to 0.
  if(state==8)
  {
    if(x < -0.05) { pwm_control(0,0);return;}  // Reach, stop
  }
  if(x<-0.1) {pwm_control(0,0); return;} // Back too far, stop
  if(x>2.2) {pwm_control(0,0); return;} // Go too far, stop
  float goal_x, goal_y;
  float K1 = way_pointX[state+1] - way_pointX[state];
  float K2 = way_pointX[state] - x;
  float K3 = way_pointY[state+1] - way_pointY[state];
  float K4 = way_pointY[state] - y;
  float M = K1*K2 + K3*K4;
  float A = square(K1) + square(K3);
  float del = 2*K1*K2*K3*K4 - (square(K1*K4)+square(K3*K2)) + square(vel/100*A);
  float t = (del>0?(-M+sqrt(del))/A:1);
  // Expression after derivation
  goal_x = way_pointX[state] + K1*t;
  goal_y = way_pointY[state] + K3*t; 
  float dis = square(x-way_pointX[state+1]) + square(y-way_pointY[state+1]); 
  if(state <= 7 && dis < square(vel/100)) // If the distance to the nect way point less than look ahead distance, change the state
  {
    if(state==6)  {pwm_control(0,0);delay(100);}
    if(state!=5)  state++;
    else
    {if(dis<square(0.15)) state++;} // Make sure maker 2 is reached
    //if(state==6)  pwm_control(0,0);
    clear_sum();
  }
  if(state==8 && dis < square(0.15))  pwm_control(0,0); //reach
  // Forward state
  if(state<6){
    if(abs(atan2(goal_y-y, goal_x-x)-theta_comp) < 0.2) omega = 0; // Too small angle differance, just go straight
    else {omega = (atan2(goal_y-y, goal_x-x)-theta_comp) / dt * 1000 / 10; // divided by N for better dynamic}
    }
    velocity_control(vel, omega);
    delay(10);
    //Serial.print("Omega:");Serial.println(omega);
  }
  // Backward state
  if(state>=6){
    if(abs(atan2(goal_y-y, goal_x-x)-(theta_comp+PI)) < 0.2) omega = 0; // Too small angle differance, just go straight
    else{ 
        float atan_ = atan2(goal_y-y, goal_x-x);
        if(atan_ + PI <1) atan_ += 2*PI;  // avoid too huge angular velocity, method try by simulation in Matlab
        omega = ((atan_-(theta_comp+ PI)) / dt * 1000 / 16); // divided by N for better dynamic
    }
    //if(state==7)  omega+=0.1;
     velocity_control(-vel, omega);
     //Serial.print("Omega:");Serial.println(omega);
     delay(10);
  }
  //Serial.print("State: ");Serial.println(state);
  delay(10);
}*/
/* 
  There are totally 10 way points:
  ---- Go forward ----
    (0, 0)
    (0.48, 0)
    (0.48, 0.48)
    (0.96, 0.48)
    (1.44, 0.48)
    (1.44, 0)
    (1.92, 0)
  ---- Go backward ----
    (1.44, 0)
    (1.44, 0.48)
    (0, 0.48)
  ---- End traverse ----
*/
// Following plan B. pure pursuit for visual case
void pure_pursuit()
{
  //if((square(x - way_pointX[9])+square(y - way_pointY[9]) < square(0.05)))  {if(turn(0))  pwm_control(0,0);return;} // If distance to the last way point 
                                                                                                                      // less than 5cm, turn to 0.
  if(state==8)
  {
    if(posX < -0.05) { pwm_control(0,0);return;}  // Reach, stop
  }
  if(posX<-0.1) {pwm_control(0,0); return;} // Back too far, stop
  if(posX>2.2) {pwm_control(0,0); return;} // Go too far, stop
  float goal_x, goal_y;
  float K1 = way_pointX[state+1] - way_pointX[state];
  float K2 = way_pointX[state] - posX;
  float K3 = way_pointY[state+1] - way_pointY[state];
  float K4 = way_pointY[state] - posY;
  float M = K1*K2 + K3*K4;
  float A = square(K1) + square(K3);
  float del = 2*K1*K2*K3*K4 - (square(K1*K4)+square(K3*K2)) + square(vel/100*A);
  float t = (del>0?(-M+sqrt(del))/A:1);
  // Expression after derivation
  goal_x = way_pointX[state] + K1*t;
  goal_y = way_pointY[state] + K3*t; 
  float dis = square(posX-way_pointX[state+1]) + square(posY-way_pointY[state+1]); 
  if(state <= 7 && dis < square(vel/100)) // If the distance to the nect way point less than look ahead distance, change the state
  {
    if(state==6)  {pwm_control(0,0);delay(100);}
    if(state!=5)  state++;
    else
    {if(dis<square(0.15)) state++;} // Make sure maker 2 is reached
    //if(state==6)  pwm_control(0,0);
    clear_sum();
  }
  if(state==8 && dis < square(0.15))  pwm_control(0,0); //reach
  // Forward state
  if(state<6){
    //if(abs(atan2(goal_y-posY, goal_x-posX)-theta_comp) < 0.2) omega = 0; // Too small angle differance, just go straight
    //else {omega = (atan2(goal_y-posY, goal_x-posX)-theta_comp) / dt * 1000 / 10; // divided by N for better dynamic}
    //}
    //velocity_control(vel, omega);
    //delay(10);
    //Serial.print("Omega:");Serial.println(omega);
  }
  // Backward state
  if(state>=6){
    if(abs(atan2(goal_y-posY, goal_x-posX)-(theta_comp+PI)) < 0.2) omega = 0; // Too small angle differance, just go straight
    else{ 
        float atan_ = atan2(goal_y-posY, goal_x-posX);
        if(atan_ + PI <1) atan_ += 2*PI;  // avoid too huge angular velocity, method try by simulation in Matlab
        omega = ((atan_-(theta_comp+ PI)) / dt * 1000 / 16); // divided by N for better dynamic
    }
    //if(state==7)  omega+=0.1;
     velocity_control(-vel, omega);
     //Serial.print("Omega:");Serial.println(omega);
     //delay(10);
  }
  //Serial.print("State: ");Serial.println(state);
  //delay(10);
}
