// Given the desired linear and angular velocity, try to chase the command
// linear  velocity in  cm/sec
// angular velocity in rad/sce
// Process time: 25ms
void velocity_control(float linear_desired, float angular_desired)
{
    float linear_KP_R  = 3, linear_KP_L  = 3;
    float linear_KI_R  = 0.4,  linear_KI_L  = 0.4;
    float angular_KP_R = 10, angular_KP_L = 10;
    float angular_KI_R = 0.6,  angular_KI_L = 0.6;
    speedLR = (speedL + speedR) / 2; // take the average of left and right wheels  as the robot linear velocity
    linear_error = speedLR - linear_desired;
    linear_error_sum += linear_error;
    omega = (speedR - speedL) / WIDTH;
    omega_error= omega - angular_desired;
    omega_error_sum += omega_error;
    pwmL = -linear_KP_R*linear_error - linear_KI_R*linear_error_sum + (angular_KP_R*omega_error + angular_KI_R*omega_error_sum)/2;
    pwmR = -linear_KP_L*linear_error - linear_KI_L*linear_error_sum - (angular_KP_L*omega_error + angular_KI_L*omega_error_sum)/2;
    // pwm must less than or equal to 255
    if(abs(pwmL)> 255)  pwmL = 255 * pwmL / abs(pwmL);
    if(abs(pwmR)> 255)  pwmR = 255 * pwmR / abs(pwmR);
    pwm_control(pwmL, pwmR);
}
void clear_sum()
{
  linear_error_sum=0;
  omega_error_sum =0;
}

