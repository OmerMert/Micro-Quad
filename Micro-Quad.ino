#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "GoUZDALi-QzeyraNSAeZGb7YRApeqBRk";
char ssid[] = "SUPERONLINE_WiFi_8875";
char pass[] = "HPVATVJU77PA";

int motor[4] = {D5, D6, D7, D8};
bool is_armable = false;
int throttle = 0;


void setup() 
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  
  for(int i = 0; i < 4; i++)
  {
    pinMode(motor[i], OUTPUT);
    analogWrite(motor[i], 0);
  }
 
}

BLYNK_WRITE(V0)
{
  is_armable = param.asInt(); // assigning incoming value from pin V0 to a variable
}

BLYNK_WRITE(V1)
{
  throttle = param.asInt(); // assigning incoming value from pin V1 to a variable

}

void loop()
{
  Blynk.run();

  if(is_armable) {
    for(int i = 0; i < 4; i++)
    analogWrite(motor[i], throttle);
  }else{
    for(int i = 0; i < 4; i++)
    analogWrite(motor[i], 0);
  }  
  
   
}
