#include "vex.h"
using namespace vex;

void armMovement()
{
    bool up = false;
    while (true)
    {

            while (!(Controller.ButtonL2.pressing()))
            {
                wait(5, msec);
            }

            up = !up;
            if (up)
            {
                armMotor.spinTo(800, degrees, false);
            }
            else
            {
                armMotor.spinTo(10, degrees, false);
            }

            while (Controller.ButtonL1.pressing())
            {
                wait(5, msec);
            }

            wait(10, msec);
        }
        wait(5, msec);
}