#include "vex.h"
using namespace vex;

void R1Press()
{
    intakeMotors.stop();
    intakeForward = !intakeForward;
    intakeReverse = false;

    if (intakeForward)
    {
        intakeMotors.setVelocity(intakeSpeed, percent);
        intakeMotors.spin(forward);
    }

    wait(5, msec);
}

void R2Press()
{
    intakeMotors.stop();
    intakeForward = false;
    intakeReverse = !intakeReverse;

    if (intakeReverse)
    {
        intakeMotors.setVelocity(intakeSpeed, percent);
        intakeMotors.spin(reverse);
    }

    wait(5, msec);
}

void YPress()
{
    intakeMotors.stop();
    intakeMotors.setVelocity(50, percent);
    intakeMotors.spinFor(reverse, 150, msec);
    intakeMotors.setVelocity(intakeSpeed, percent);
}

void antiJam()
{
    while (true)
    {
        float intakeRPM = fabs(intakeMotors.velocity(rpm));

        if (intakeRPM < 70)
        {
            wait(50, msec);

            intakeRPM = fabs(intakeMotors.velocity(rpm));

            if ((intakeMotors.voltage() > 3) && (intakeRPM < 50) && (lbSelect != 1) && antiJamEnable)
            {
                intakeMotors.stop();
                intakeMotors.spinFor(reverse, 150, msec);
                intakeMotors.spin(forward);
            }
        }
        wait(15, msec);
    }
}

// driver control loop
void intake()
{
    intakeMotors.setVelocity(0, percent);
    while (true)
    {
        if (intakeForward)
        {
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
        }
        else if (intakeReverse)
        {
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(reverse);
        }
        else if (Controller.ButtonY.pressing())
        {
            intakeMotors.setVelocity(50, percent);
            intakeMotors.stop();
            intakeMotors.spinFor(reverse, 150, msec);
        }
        else
        {
            intakeMotors.stop();
        }

        wait(15, msec);
    }
}