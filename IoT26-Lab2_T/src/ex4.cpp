#include "Arduino.h"

#define RED_LED_PIN 26
#define GREEN_LED_PIN 27
#define YELLOW_LED_PIN 12
#define BLUE_LED_PIN 14
#define BUTTON_PIN 25

/****************************************************/

void setup(void)
{
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);

    Serial.begin(115200);

    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
}

/****************************************************/
void loop(void)
{
    static bool lastButtonState = LOW;
    static int counter = 0;

    bool currentButtonState = digitalRead(BUTTON_PIN);

    if (lastButtonState == LOW && currentButtonState == HIGH)
    {
        counter = (counter + 1) % 5;

        Serial.print("count=");
        Serial.println(counter);
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(YELLOW_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, LOW);

        if (counter >= 1)
        {
            digitalWrite(RED_LED_PIN, HIGH);
        }
        if (counter >= 2)
        {
            digitalWrite(GREEN_LED_PIN, HIGH);
        }
        if (counter >= 3)
        {
            digitalWrite(YELLOW_LED_PIN, HIGH);
        }
        if (counter >= 4)
        {
            digitalWrite(BLUE_LED_PIN, HIGH);
        }
    }

    lastButtonState = currentButtonState;


















    
}

