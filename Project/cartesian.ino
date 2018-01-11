// Traverse the map through Cartesian method
void cartesian()
{
    if(state==0)
    {
      if(tracking('X', 0.48))
      {
        state++;
        // clear error sum
        clear_sum();
        pwm_control(0,0);
        delay(20);
      }
    }
    if(state==1)
    {
      if(turn(PI/2))  {state++;pwm_control(0,0);delay(20);}
    }
    if(state==2)
    {
      if(tracking('Y', 0.48))
      {
        state++;
        // clear error sum
        clear_sum();
        pwm_control(0,0);
        delay(20);
      }
    }
    if(state==3)
    {
      if(turn(0)) {state++;pwm_control(0,0);delay(20);}
    }
    if(state==4)
    {
      if(tracking('X', 1.44))
      {
        state++;
        clear_sum();
        pwm_control(0,0);
        delay(20);
      }
    }
    if(state==5)
    {
      if(turn(-PI/2)) {state++;pwm_control(0,0);delay(20);}
    }
    if(state==6)
    {
      if(tracking('Y', 0))
      {
        state++;
        clear_sum();
        delay(20);
        pwm_control(0,0);
      }
    }
    if(state==7)
    {
      if(tracking('X', 1.92))
      {
        state++;
        clear_sum();
        delay(20);
        pwm_control(0,0);
      }
    }
    if(state==8)
    {
      if(tracking('X', 1.44))
      {
        state++;
        clear_sum();
        pwm_control(0,0);
        delay(20);
      }
    }
    if(state==9)
    {
      if(turn(-PI/2)) {state++;pwm_control(0,0);delay(20);}
    }
    if(state==10)
    {
      if(tracking('Y', 0.48))
      {
        state++;
        clear_sum();
        pwm_control(0,0);
        delay(20);
      }
    }
    if(state==11)
    {
      if(turn(0)) {state++;pwm_control(0,0);delay(20);}
    }
    if(state==12)
    {
      if(tracking('X', 0))
      {
        pwm_control(0, 0);
        clear_sum();
        pwm_control(0,0);
        delay(20);
      }
    }
    Serial.print("State: ");Serial.println(state);
}


