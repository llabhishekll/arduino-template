#include <Wire.h>
 
const int ADDR =0x40;
int X0,X1,Y0,Y1,Y2,Y3;
double X,Y,X_out,Y_out1,Y_out2;
 
void setup()
{ 
  Serial.begin(9600);   
  Wire.begin();                                   
  delay(100);  
  Wire.beginTransmission(ADDR);
  Wire.endTransmission();                        
}
 
void loop()
{
  /**Send command of initiating temperature measurement**/
  Wire.beginTransmission(ADDR);
  Wire.write(0xE3);
  Wire.endTransmission();
  
  /**Read data of temperature**/
  Wire.requestFrom(ADDR,2);
 
  if(Wire.available()<=2);
  {
    X0 = Wire.read();
    X1 = Wire.read();
    X0 = X0<<8;
    X_out = X0+X1;
  }
 
  /**Calculate and display temperature**/
  X=(175.72*X_out)/65536;                        
  X=X-46.85;
 
  /**Send command of initiating relative humidity measurement**/
  Wire.beginTransmission(ADDR);                     
  Wire.write(0xE5);
  Wire.endTransmission(); 
 
  /**Read data of relative humidity**/
  Wire.requestFrom(ADDR,2);
  if(Wire.available()<=2);
  {
    Y0 = Wire.read();
    Y2=Y0/100; 
    Y0=Y0%100;
    Y1 = Wire.read();
    Y_out1 = Y2*25600;
    Y_out2 = Y0*256+Y1;
  }
 
  /**Calculate and display relative humidity**/
  Y_out1 = (125*Y_out1)/65536;                     
  Y_out2 = (125*Y_out2)/65536;
  Y = Y_out1+Y_out2;
  Y=Y-6;

  Serial.print(X);
  Serial.print(',');
  Serial.println(Y);
 }
