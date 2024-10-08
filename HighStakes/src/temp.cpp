#include "vex.h"
using namespace vex;

void warning()
{
    motor* motors[] = {&leftMotorA, &leftMotorB, &rightMotorA, &rightMotorB, &firstStageIntake, &secondStageIntake, &armMotor};

    for (motor* Motor : motors)
    {
        if (Motor->temperature(celsius) > 55)
        {
            Controller.Screen.clearScreen();
            Controller.Screen.setCursor(1, 1);
            Controller.Screen.print("Motor port: ", Motor->index());
            Controller.Screen.print(", temp: %d", Motor->temperature(celsius));
            Controller.rumble("...--");
        }
    }
    wait(250, msec);
}