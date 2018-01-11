  int len = 0;
String str_, linear_str, angular_str;
void joystick_control()
{
  char val;
  char command[30];
  float linear;
  float angular;
  if(BT.available())
  {
    val = BT.read();
    command[len++] = val;
    if(len >= 30) len = 0;
    if(val == 'e')
    {
      len = 0;
    }
  }
  str_ = String(command);
  int start_, comma, end_;
  for(int i=0; i<str.length(); ++i)
  {
    if(str[i]=='s') start_ = i;
    if(str[i]==';') comma = i;
    if(str[i]=='e') {end_ = i;break;}
  }
  linear_str = str_.substring(start_+1, comma);
  angular_str = str_.substring(comma+1, end_);
  linear = linear_str.toFloat();
  angular = angular_str.toFloat()/100;
  if(angular>PI || angular <-PI)  angular = 0; // Ignore too large case
  if(linear==0 && angular==0) pwm_control(0,0);
  else  
    velocity_control(linear, angular);
  Serial.print("Linear: ");Serial.print(linear);Serial.print(" Angular: ");Serial.print(angular);
}
