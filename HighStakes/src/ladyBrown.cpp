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
    float kd = 2.4;
    float starti = 1.5;

    while (true)
    {
        lb.setVelocity(80, percent);

        while (!Controller.ButtonRight.pressing())
        {
            wait(5, msec);
        }

        lb.setBrake(hold);        
        Drive::MotorTurn(lb, 43.5, max_voltage, settle_error, settle_time, timeout, kp, ki, kd, starti);
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

        Drive::MotorTurn(lb, 190, max_voltage, settle_error, settle_time, timeout, kp, ki, kd, starti);
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

        Drive::MotorTurn(lb, -230, max_voltage, settle_error, settle_time, timeout, kp, ki, kd, starti);
        lb.setBrake(coast);
        // Wait until release
        while (Controller.ButtonRight.pressing())
        {
            wait(5, msec);
        }
        lb.resetPosition();   
    }
}