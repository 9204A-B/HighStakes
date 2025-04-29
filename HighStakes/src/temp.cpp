#include "vex.h"
#include "array"
#include <string>
using namespace vex;

void warning()
{
    motor* motors[] = {&leftMotorA, &leftMotorB, &leftMotorC, &rightMotorA, &rightMotorB, &rightMotorC, &intakeMotors, &lb};
    std::string names[] = {"left Motors", "left Motors", "left Motors", "right Motors", "right Motors", "right Motors", "intake", "lb"};

    while (true)
    {
        for (int x = 0; x < 8; x++)
        {
            if (motors[x]->temperature(celsius) > 50)
            {            
                Controller.Screen.clearScreen();
                Controller.Screen.setCursor(1, 1);
                //Controller.Screen.print(names[x]);
                Controller.Screen.setCursor(2, 1);
                Controller.Screen.print("temp: %f", motors[x]->temperature(celsius));
                Controller.rumble("...--");
                wait(250, msec);
            }
        }      
        wait(250, msec);  
    }
}