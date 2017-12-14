// Check whether data in range (lower, upper)
// Return true if so and false otherwise
// Since branch cut of theta at 0, turn the yaw to theta have to be specoally processing
bool inRange(float data,float upper, float lower)
{
  if(data<upper && data >lower) return true;
  else return false;
}
// Turn the yaw of the robot to the given angle
// Process time: 15ms
bool turn(float yaw)
{
  // branch cut at 0, so we need to process this special case
  float KP_R=8.0, KP_L=3.0; // 8.0 3.0 
  float KI_R=0.15, KI_L=0.15;  // 0.15
  float tolerance = 0.05; // 0.05
  int count=0; // deadzone counter
  angle_error = yaw - theta;
  angle_error_sum += angle_error;
  // case1. non zero yaw, then if abs(angle_error)<tolerance, stop and return 
  if(abs(angle_error)< tolerance && yaw !=0) {pwm_control(0,0);angle_error_sum=0;return true;}
  // case2: yaw=0, then if theta in [0, tolerance) or (2pi-tolerance, 2pi], stop and return
  if(yaw == 0 && (inRange(abs(angle_error), tolerance, 0) || inRange(abs(angle_error), 2*PI, 2*PI-tolerance)))  {pwm_control(0,0);angle_error_sum=0;return true;}
  // case3. PWM in deadzone and hence with the same pose, quit after 0.5s
  if(disL==0 && disR==0) {count++;}
  if(count>=5)  {pwm_control(0,0);angle_error_sum=0;return true;} 
  // if-if to turn through minor arc for time-saving
  if(yaw > theta)
  {
      // case1. yaw > theta and yaw-theta <= PI: CCW (L-R+)
      if(yaw - theta <= PI)  pwm_control(-angle_error*KP_L-angle_error_sum*KI_L, angle_error*KP_R+angle_error_sum*KI_R);
      // case2. yaw > theta and yaw-theta > PI:  CW  (L+R-)
      else  pwm_control(angle_error*KP_L+angle_error_sum*KI_L, -angle_error*KP_R-angle_error_sum*KI_R);
  }
  else
  {
      // case3. yaw < theta and theta-yaw >= PI: CW (L-R+), but the error is positive, so differant polarity with line 38
      if(theta - yaw >= PI)  pwm_control(angle_error*KP_L+angle_error_sum*KI_L, -angle_error*KP_R-angle_error_sum*KI_R);
      // case4. yaw < theta and theta-yaw < PI:  CCW(L+R-)
      else  pwm_control(-angle_error*KP_L-angle_error_sum*KI_L, angle_error*KP_R+angle_error_sum*KI_R);
  }
  return false;
}

