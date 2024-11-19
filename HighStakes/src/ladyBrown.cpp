#include "vex.h"
using namespace vex;

void ladybrown()
{
    while (true)
    {
        lb.setVelocity(80, percent);

        while (!Controller.ButtonRight.pressing())
        {
            wait(5, msec);
        }

        lb.setBrake(hold);
        lb.spinToPosition(30, degrees, true);

        // Wait until button is let go
        while (Controller.ButtonRight.pressing())
        {
            wait(5, msec);
        }

        // Wait until button is pressed again
        while (!Controller.ButtonRight.pressing())
        {
            wait(5, msec);
        }

        lb.spinToPosition(400, degrees, false);
        wait(.5, sec);

        lb.stop(coast);
        
        // Wait until button is released
        while (Controller.ButtonRight.pressing())
        {
            wait(5, msec);
        }

        // Wait until button is pressed again
        while (!Controller.ButtonRight.pressing())
        {
            wait(5, msec);
        }

        lb.spinToPosition(0, degrees, false); 
        lb.setBrake(coast);
        // Wait until release
        while (Controller.ButtonRight.pressing())
        {
            wait(5, msec);
        }   
    }
}