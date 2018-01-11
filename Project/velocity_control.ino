// Given the desired linear and angular velocity, try to chase the command
// linear  velocity in  cm/sec
// angular velocity in rad/sce
// Process time: 25ms
void velocity_control(float linear_desired, float angular_desired)
{
      speedLR = (speedL + speedR) / 2; // take the average of left and right wheels  as the robot linear velocity
      omega = (speedR - speedL) / WIDTH;
      // Given desired linear and angular velocity, we can know the desired velocity of left and right wheel
      float speedR_desired = linear_desired + WIDTH/2 * angular_desired;
      float speedL_desired = linear_desired - WIDTH/2 * angular_desired;
      // PI coefficients
      float KP_R = 1.0, KP_L = 2.0;
      float KI_R = 0.3, KI_L = 0.3;
      // Directly control two wheels velocities may cause the heading not zero,
      // so I use the theta with PI controller to compensate the heading.
      // While wheel_odometry use angle with branch [0, 2*pi), for this case,
      // it should be converted to branch [-pi, pi)
      float KP_theta = 100, KI_theta = 1; 
      float theta_error = -theta_comp;
      theta_error_sum += theta_comp;
      speedR_error = speedR_desired - speedR;
      speedL_error = speedL_desired - speedL;
      speedR_error_sum += speedR_error;
      speedL_error_sum += speedL_error;
      // If angular velocity is zero, so the heading should be zero
      pwmR = speedR_error * KP_R + speedR_error_sum * KI_R - (theta_comp * (KP_theta+20) + theta_error_sum * KI_theta) * (angular_desired == 0 && !joystick) / 2;
      pwmL = speedL_error * KP_L + speedL_error_sum * KI_L + (theta_comp * KP_theta + theta_error_sum * KI_theta) * (angular_desired == 0 && !joystick) / 2;
      pwm_control(pwmL, pwmR);
}
// New command given, clear sum
void clear_sum()
{
  speedR_error_sum = 0;
  speedL_error_sum = 0;
}

