#include <ESP8266WiFi.h>

void setup()
{
Serial.begin(115200);
Serial.println();
//disconnect any previous connections
WiFi.disconnect();
delay(1000);
//scan for number of nearby networks & print SSIDs
Serial.print ("Nearby networks found   :");
Serial.println(WiFi.scanNetworks());
delay(500);

Serial.println( "List of surrounding Network SSIDs....");
int n = WiFi.scanNetworks();

for (int i = 0; i < n; i++)
{
Serial.println(WiFi.SSID(i));
}

Serial.println();
Serial.println ("Scan completed....");
 
}


void loop()
{
}
