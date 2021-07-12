#include <ESP8266WiFi.h>
char ssid[]="Abhishek's JioFi";  // replace with your ssid & pass
char pass[]="Axel@123#";

void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.print("Connecting to..");
  Serial.println(ssid);
  delay(500);
  WiFi.disconnect();
  WiFi.begin(ssid,pass);
while(WiFi.status() != WL_CONNECTED)
{
  delay(500);
  Serial.println(".");
}
Serial.print("SSID...");
Serial.println (WiFi.SSID());
Serial.println("Successfully connected!!!");

Serial.print("IP Address allotted to NodeMcu ESP..");
Serial.println(WiFi.localIP());

Serial.print("MAC Address of ESP...");
Serial.println(WiFi.macAddress());
WiFi.printDiag(Serial);
}
void loop()
{
}
