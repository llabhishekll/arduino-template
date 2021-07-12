int LED_OUT = 1;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(LED_OUT, OUTPUT);
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
  digitalWrite(LED_OUT,HIGH);                                  // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  delay(1000);                      // Wait for a second
  Serial.println("led off");
  delay(250);                      // Wait for one-quarter of second

  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(LED_OUT, LOW);// Turn the LED off by making the voltage HIGH
  delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)
  Serial.println("led on");
  delay(250);                      // Wait for one-quarter of second
}
