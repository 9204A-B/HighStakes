#include "vex.h"
using namespace vex;

float max_voltage = 4;
float settle_error = 0;
float settle_time = 300;
float timeout = 750;
float kp = .375;
float ki = 0;
float kd = 1.4;
float starti = .5;

void lbLoadButton()
{
    if (lbShift) {
        lb.spin(reverse, 8, volt);

        while (Controller.ButtonRight.pressing())
        {
            wait(5, msec);
        }
        lb.stop(coast);
    }
    else {
        lb.setStopping(hold);
        Drive::MotorTurn(lbRotation, lb, 25, 4, settle_error, settle_time, timeout, kp, ki, kd, starti);
    }
}

void lbScoreButton()
{
    if (lbShift) {
        lb.spin(forward, 8, volt);

        while (Controller.ButtonY.pressing())
        {
            wait(5, msec);
        }
        lb.stop(coast);
    }
    else {
        YPress();
        Drive::MotorTurn(lbRotation, lb, 160, 12, settle_error, settle_time, timeout, .15, ki, .6, 25);
        lb.setStopping(hold);
        lbSelect = 2;
    }
    
}

void lbResetButton()
{
    Drive::MotorTurn(lbRotation, lb, 0, 12, settle_error, settle_time, timeout, .15, ki, .6, 25);
    lb.setStopping(coast);
}

void lbShiftKey()
{
    lbShift = true;
}

void lbUnshiftKey()
{
    lbShift = false;
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
        Drive::MotorTurn(lbRotation, lb, 25, max_voltage, settle_error, settle_time, timeout, kp, ki, kd, starti);
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
        Drive::MotorTurn(lbRotation, lb, 180, max_voltage, settle_error, settle_time, timeout, kp, ki, 1.8, starti);
        lb.stop(hold);
    }
    lbSelect = 1;

    lb.stop(hold);
}

void ladybrownScoring()
{
    lbSelect = 2;
    // YPress();
    Drive::MotorTurn(lbRotation, lb, 160, 12, settle_error, settle_time, timeout, .16, ki, .75, 25);
    lb.setStopping(hold);
    // This requires tuning as well
    // if (lbRotation.position(rotationUnits::deg) < 180)
    // {
    //     lbSelect = 2;
    //     YPress();
    //     wait(60, msec);
    //     lb.setStopping(hold);
    //     lb.setVelocity(80, percent);
    //     lb.spinFor(.6, sec);
    //     wait(.5, sec);
    // }
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