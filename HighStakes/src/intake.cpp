#include "vex.h"
using namespace vex;

void R1Press()
{
    intakeForward = !intakeForward;
    intakeReverse = false;
    wait(5, msec);
}

void R2Press()
{
    intakeForward = false;
    intakeReverse = !intakeReverse;
    wait(5, msec);
}

void intake()
{
    intakeMotors.setVelocity(0, percent);
    while (true)
    {
        antiJamEnable = false;
        if (intakeForward)
        {
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(100, msec);
            antiJamEnable = true;
        }
        else if (intakeReverse)
        {
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(reverse);
            wait(100, msec);
            antiJamEnable = true;
        }
        else if (Controller.ButtonY.pressing())
        {
            intakeMotors.setVelocity(50, percent);
            intakeMotors.stop();
            intakeMotors.spinFor(reverse, 150, msec);
        }
        else
        {
            intakeMotors.setVelocity(0, percent);
        }

        // intake is jammed if:
        // voltage is high
        // |rpm| is close to zero
        // ladybrown select = 1 (ladybrown is loading)
        // antiJam is disabled
    
        float intakeRPM = intakeMotors.velocity(rpm);
        if ((intakeMotors.voltage() > 0) && (fabs(intakeRPM) < 60) && (lbSelect != 2) && antiJamEnable)
        {
            if (intakeMotors.direction() == forward)
            {
                intakeMotors.spinFor(reverse, 150, msec);
                intakeMotors.spin(forward);
            }
            else if (intakeMotors.direction() == reverse)
            {
                intakeMotors.spinFor(forward, 150, msec);
                intakeMotors.spin(reverse);
            }
        }

        wait(15, msec);
    }
}

void antiJam()
{
    while (true)
    {
        if ((intakeMotors.power() > 6) && (abs(intakeMotors.velocity(rpm)) < 20) && (lbSelect != 2) && antiJamEnable)
        {
            if (intakeMotors.direction() == forward)
            {
                intakeMotors.spinFor(reverse, 150, msec);
                intakeMotors.spin(forward);
            }
            else if (intakeMotors.direction() == reverse)
            {
                intakeMotors.spinFor(forward, 150, msec);
                intakeMotors.spin(reverse);
            }
        }
    }
}