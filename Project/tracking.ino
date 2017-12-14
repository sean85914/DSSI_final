// Following throught the given axis with given distance
// Process time: 20ms
bool tracking(char axis, float distance)
{
  float linear_tolerance = 0.01;
  if(axis == 'X')
  {
    if(distance-x>linear_tolerance)  // Need to change
    {
      velocity_control(25, 0);
      return false;
    }
    else  
    {
      pwm_control(0,0);
      return true;
    }
  }
  if(axis == 'Y')
  {
    if(distance-y>linear_tolerance)
    {
      velocity_control(25, 0);
      return false;
    }
    else  
    {
      pwm_control(0,0);
      return true;
    }
  }

}

