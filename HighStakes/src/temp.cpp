#include "vex.h"
#include "array"
using namespace vex;

void warning()
{
    motor* motors[] = {&leftMotorA, &leftMotorB, &rightMotorA, &rightMotorB, &firstStageIntake, &secondStageIntake, &armMotorA, &armMotorB};
    int ports[] = {11, 12, 19, 20, 13, 21, 4, 5};

    while (true)
    {
        for (int x = 0; x < 7; x++)
        {
            if (motors[x]->temperature(celsius) > 50)
            {            
                Controller.Screen.clearScreen();
                Controller.Screen.setCursor(1, 1);
                Controller.Screen.print("Motor port: %d", ports[x]);
                Controller.Screen.print(", temp: %f", motors[x]->temperature(celsius));
                Controller.rumble("...--");
            }
        }
    wait(250, msec);
    }
}