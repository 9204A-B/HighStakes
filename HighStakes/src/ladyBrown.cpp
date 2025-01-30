#include "vex.h"
using namespace vex;

void lbLoadButton()
{
    if (lbSelect = 1)
    {
        ladyBrownReset();
    }
    else
    {
        ladyBrownLoading();
    }
}

void lbScoreButton()
{
    if (lbSelect = 2)
    {
        ladyBrownReset();
    }
    else
    {
        ladyBrownScoring();
    }
}

void ladybrownLoading()
{
    lbSelect = 1;
    lb.setMaxTorque(100, percent);
    lb.setVelocity(80, percent);

    while (lbDistance.objectDistance(mm) < 70)
    {
        lb.setVelocity(25, percent);
        lb.spin(forward);
        wait(5, msec);
    }
    lb.stop(hold);
}

void ladybrownScoring()
{
    if (lbDistance.isObjectDetected())
    {
        lbSelect = 2;
        lb.setStopping(hold);
        lb.setVelocity(80, percent);
        lb.spinFor(.5, sec);
        wait(.5, sec);
    }
}

void ladybrownReset()
{
    lbSelect = 0;
    while (lbDistance.objectDistance(mm) > 40)
    {
        lb.spin(reverse);
    }
    lb.stop(coast);
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