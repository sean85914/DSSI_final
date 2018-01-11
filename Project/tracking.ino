// Following throught the given axis with given point
// Process time: 20ms
bool tracking(char axis, float distance)
{
  float linear_tolerance = 0.01; // tolerance distance
  if(axis == 'X')
  {
    if(distance>x && distance-x>linear_tolerance)  
    {
      velocity_control(vel, 0);
      return false;
    }
    else if(x>distance && x-distance>linear_tolerance)
    {
      velocity_control(-vel, 0);
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
    if(distance>y && distance-y>linear_tolerance)
    {
      velocity_control(vel, 0);
      return false;
    }
    else if(y>distance && y-distance>linear_tolerance)
    {
      velocity_control(-vel, 0);
      return false;
    }
    else  
    {
      pwm_control(0,0);
      return true;
    }
  }

}

int sign(double x)
{
  if(x>0) return 1;
  else if(x==0) return 0;
  else return -1;
}

