#include "vex.h"
using namespace vex;

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
        while (lbRotation.position(rotationUnits::deg) < 70)
        {
            lb.setVelocity(25, percent);
            lb.spin(forward);
            wait(5, msec);
        }
    }
    else if (lbSelect == 2)
    {
        // Here as well
        while (lbRotation.position(rotationUnits::deg) > 70)
        {
            lb.setVelocity(25, percent);
            lb.spin(reverse);
            wait(5, msec);
        }
    }
    lbSelect = 1;

    lb.stop(hold);
}

void ladybrownScoring()
{
    // This requires tuning as well
    if (lbRotation.position(rotationUnits::deg) < 50)
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