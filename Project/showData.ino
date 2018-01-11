// Show data by serial
void showData()
{
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.print(theta);
  Serial.print(" ");
  Serial.print(omega);
  Serial.print(" ");
  Serial.println(state);
  /*Serial.print(speedLR);
  Serial.print(" ");
  Serial.print(omega);
  Serial.print(" ");
  Serial.println(millis());*/
}

