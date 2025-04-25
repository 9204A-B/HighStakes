#include "vex.h"
using namespace vex;

float max_voltage = 6;
float settle_error = .5;
float settle_time = 300;
float timeout = 500;
float kp = .375;
float ki = 0;
float kd = 2.4;
float starti = 1.5;

void lbLoadButton()
{
    if (lbSelect == 1)
    {
        ladybrownReset();
    }
    else
    {
        ladybrownLoading();
    }
}

void lbScoreButton()
{
    if (lbSelect == 2)
    {
        ladybrownReset();
    }
    else
    {
        ladybrownScoring();
    }
}

void ladybrownLoading()
{
    lb.setMaxTorque(100, percent);
    lb.setVelocity(80, percent);

    if (lbSelect == 0)
    {
        // TODO: Tune rotation sensor so we don't break the new lb        
        // while (lbRotation.position(rotationUnits::deg) < 348)
        // {
        //     lb.setVelocity(25, percent);
        //     lb.spin(forward);
        //     wait(5, msec);
        // }
        Drive::MotorTurn(lbRotation, lb, 10, max_voltage, settle_error, settle_time, timeout, kp, ki, kd, starti);
    }
    else if (lbSelect == 2)
    {
        // Here as well
        // while (lbRotation.position(rotationUnits::deg) > 190.5)
        // {
        //     lb.setVelocity(25, percent);
        //     lb.spin(reverse);
        //     wait(5, msec);
        // }
        Drive::MotorTurn(lbRotation, lb, 190.5, max_voltage, settle_error, settle_time, timeout, kp, ki, kd, starti);
    }
    lbSelect = 1;

    lb.stop(hold);
}

void ladybrownScoring()
{
    // This requires tuning as well
    if (lbRotation.position(rotationUnits::deg) < 190.5)
    {
        lbSelect = 2;
        YPress();
        wait(60, msec);
        lb.setStopping(hold);
        lb.setVelocity(80, percent);
        lb.spinFor(.6, sec);
        wait(.5, sec);
    }
}

void ladybrownReset()
{
    if (lbSelect == 2)
    {
        lb.spinFor(reverse, 0.5, sec);
        lb.stop(coast);
    }
    else if (lbSelect == 1)
    {
        lb.spinFor(reverse, 0.1, sec);
        lb.stop(coast);
    }

    lbSelect = 0;
}

void ladybrown()
{
    switch (lbSelect)
    {
    case 0:
    {
        ladybrownLoading();
        break;
    }
    case 1:
    {
        ladybrownScoring();
        break;
    }
    case 2:
    {
        ladybrownReset();
        break;
    }
    }
}