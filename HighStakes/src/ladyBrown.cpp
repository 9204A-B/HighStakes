#include "vex.h"
using namespace vex;

void ladybrown()
{
    float max_voltage = 6;
    float settle_error = .5;
    float settle_time = 300;
    float timeout = 500;
    float kp = .375;
    float ki = .03;
    float kd = .4;
    float starti = 0;

    while (true)
    {

        lb.setMaxTorque(100, percent);
        lb.setStopping(coast);

        lb.setVelocity(80, percent);

        while (!Controller.ButtonRight.pressing())
        {
            wait(5, msec);
        }

        while (lbDistance.objectDistance(mm) < 70)
        {
            lb.setVelocity(25, percent);
            lb.spin(forward);
            wait(5, msec);
        }       
        lb.stop(hold);    

        while (Controller.ButtonRight.pressing())
        {
            wait(5, msec);
        }

        // Wait until button is pressed again
        while (!Controller.ButtonRight.pressing())
        {
            wait(5, msec);
        }
        
        lb.setVelocity(80, percent);
        lb.spinFor(.5, sec);
        wait(.5, sec);

        lb.setStopping(coast);
        
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

        lb.setStopping(coast);
        while (lbDistance.objectDistance(mm) > 40)
        {
            lb.spin(reverse);
        }
        lb.stop();
        // Wait until release
        while (Controller.ButtonRight.pressing())
        {
            wait(5, msec);
        } 
    }
}