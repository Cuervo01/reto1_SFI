#include <Arduino.h>
#include "task1.h"

void task1()
{
    enum TaskStates
    {
        INIT,
        BLINK,
    };

    static TaskStates taskState = TaskStates::INIT;
    constexpr u_int8_t led_blink = 26;
    static uint32_t lasTime;
    const uint32_t BlinkInterval = 1000;

    static bool ledStatus = false;

    switch (taskState)
    {
        //Initialization of Vars
        case TaskStates::INIT:
        {
            pinMode(led_blink, OUTPUT);
            digitalWrite(led_blink, LOW);
            lasTime = millis();

            taskState = TaskStates::BLINK;
            break;
        }

        case TaskStates::BLINK:
        {
            uint32_t currentTime = millis();

            if( (currentTime - lasTime) >= BlinkInterval)
            {
                lasTime = currentTime;
                digitalWrite(led_blink,ledStatus);
                ledStatus = !ledStatus;
            } 
            break;
        }

    }
}