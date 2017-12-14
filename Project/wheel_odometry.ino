// Odometry by wheel, called after velocity_control
// Process time: 24ms
void wheel_odometry()
{
  if(millis() - now >= dt)
  {
    speed_time = millis() - now;
    disL = dis_per_tick* (encoderLPre - encoderLPrior);
    disR = dis_per_tick* (encoderRPre - encoderRPrior);
    speedL = disL/ speed_time * 1000;
    speedR = disR/ speed_time * 1000;
    dtheta = (disR - disL) / WIDTH ;
    x += (disR + disL) /2 * cos(theta + dtheta / 2.) / 100; // in meters
    y += (disR + disL) /2 * sin(theta + dtheta / 2.) / 100; // in meters
    theta += dtheta; // in radians
    // theta in range [0, 2pi)
    if(theta<0) theta += 2*PI;
    if(theta>=2*PI) theta -= 2*PI;
    // encoder and time update
    encoderLPrior = encoderLPre;
    encoderRPrior = encoderRPre;
    now = millis();
  }
}
