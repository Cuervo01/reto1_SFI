#include <Arduino.h>
#include "task2.h"


String btnState(uint8_t btnState)
{
  if(btnState == HIGH){
    return "OFF";
  }
  else return "ON";
}

void task2()
{

enum TaskStates
{
    INIT,
    CALL,
};

static TaskStates taskState = TaskStates::INIT;
constexpr uint8_t led = 25;
constexpr uint8_t buttonTlc = 27;

  switch (taskState)
  {
    case TaskStates::INIT:
    {
        Serial.begin(115200);
        pinMode(led, OUTPUT);
        digitalWrite(led, LOW);
        pinMode(buttonTlc, INPUT_PULLUP);
        taskState = TaskStates::CALL;
    }
    break;

    case TaskStates::CALL:
    {
        if (Serial.available() > 0)
        {
            String command = Serial.readStringUntil('\n');
            if (command == "CMS")
            {
                Serial.print("btn");
                Serial.print(btnState(digitalRead(buttonTlc)).c_str());
                Serial.print("led");
                Serial.print(digitalRead(led));
                Serial.print('\n');
                
            }
            else if (command == "ledON")
            {
                digitalWrite(led, HIGH);
            }
            else if (command == "ledOFF")
            {
                digitalWrite(led, LOW);
            }
        }
    }
    break;



    default:
    break;

  }

}

