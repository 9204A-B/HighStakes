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
        Drive::MotorTurn(lb, 43.5, 8, 2, 300, 1500, .4, .03, 2, 5);    
        lb.setBrake(hold);        
        //Braking is still being set to brake and not hold after adding PID

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

        Drive::MotorTurn(lb, 190, 8, 1.5, 300, 2000, .4, .03, 2, 5);
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

        Drive::MotorTurn(lb, -230, 8, 3, 300, 1800, .4, .03, 2, 5);
        lb.setBrake(coast);
        // Wait until release
        while (Controller.ButtonRight.pressing())
        {
            wait(5, msec);
        }   
    }
}