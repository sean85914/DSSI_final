// Interrupt function
void EncoderL()
{
  if(digitalRead(encoderLPinB)==HIGH)
  {
    encoderLPre-=1;
  }
  else
    encoderLPre+=1;
}
void EncoderR()
{
  if(digitalRead(encoderRPinB)==HIGH)
  {
    encoderRPre-=1;
  }
  else
    encoderRPre+=1;
}
