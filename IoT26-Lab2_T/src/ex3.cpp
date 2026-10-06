#include "Arduino.h"

#define LIGHT_SENSOR_PIN 33

/****************************************************/
void setup(void)
{
    Serial.begin(115200);
}

/****************************************************/
void loop(void)
{
    static unsigned long lastCheckTime = 0;
    static bool alertActive = false;
    unsigned long currentTime = millis();
    if (currentTime - lastCheckTime < 300)
    {
        return;
    }

    lastCheckTime = currentTime;

    int lightValue = analogRead(LIGHT_SENSOR_PIN);

    if (alertActive && lightValue < 2500)
    {
        alertActive = false;
        Serial.println("ALERT=0");
    }
    else if (!alertActive && lightValue > 3000)
    {
        alertActive = true;
        Serial.println("ALERT=1");
    }


    
}

