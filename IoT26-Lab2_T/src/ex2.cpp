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
    static unsigned long lastPrintTime = 0;

    unsigned long currentTime = millis();
    if (currentTime - lastPrintTime < 1000)
    {
        return;
    }

    lastPrintTime = currentTime;

    int minValue = 4095;
    int maxValue = 0;
    long sum = 0;


    for (int i = 0; i < 10; i++)
    {
        int value = analogRead(LIGHT_SENSOR_PIN);

        if (value < minValue)
        {
            minValue = value;
        }
        if (value > maxValue)
        {
            maxValue = value;
        }
        sum += value;
    }

    int average = sum / 10;
    Serial.print("min=");
    Serial.print(minValue);
    Serial.print(" max=");
    Serial.print(maxValue);
    Serial.print(" avg=");
    Serial.println(average);

    
}





