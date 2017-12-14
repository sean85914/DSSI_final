// Given PWMs of two motors, write to the output pin
// Process time: 23ms
// Left PWM, Right PWM
void pwm_control(int pwmL, int pwmR)
{
  //if(abs(pwmL)<30 && abs(pwmR)<30)  {pwmL=0; pwmR=0;}
  if(pwmL>0 && pwmR>0)
  {
    analogWrite(motorLIn1, pwmL);
    analogWrite(motorLIn2, 0);
    analogWrite(motorRIn1, pwmR);
    analogWrite(motorRIn2, 0);
    delay(10);
  }
  else if(pwmL>0 && pwmR<0)
  {
    analogWrite(motorLIn1, pwmL);
    analogWrite(motorLIn2, 0);
    analogWrite(motorRIn1, 0);
    analogWrite(motorRIn2, -pwmR);
    delay(10);
  }
  else if(pwmL<0 && pwmR>0)
  {
    analogWrite(motorLIn1, 0);
    analogWrite(motorLIn2, -pwmL);
    analogWrite(motorRIn1, pwmR);
    analogWrite(motorRIn2, 0);
    delay(10);
  }
  else
  {
    analogWrite(motorLIn1, 0);
    analogWrite(motorLIn2, -pwmL);
    analogWrite(motorRIn1, 0);
    analogWrite(motorRIn2, -pwmR);
    delay(10);
  }
}
