
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL3OpuAMbwL"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "H_cWYbWgXqJ7cJQFHTZh9RNV6ATAB4rA"

#define led2 D2 //GPIO4

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Meena_Samsung";
char pass[] = "PER24@68fect";

BLYNK_WRITE(V0)
{
  int value = param.asInt(); // Set incoming value from pin V0 to a variable 
  
  digitalWrite(led2, value); // Update state
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  delay(100);

  pinMode(led2, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
}

void loop()
{
  Blynk.run();
}

/*BLYNK_WRITE(V0)
{
  Blynk.virtualWrite(D0, value);
  if(value == 0)
  {
    digitalWrite(led2, LOW);
  }
  else
  {    
    digitalWrite(led2, HIGH);
  }
  
}

BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0);
}*/
