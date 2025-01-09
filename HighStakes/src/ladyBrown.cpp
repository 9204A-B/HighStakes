#include "vex.h"
using namespace vex;

void ladybrownLoading()
{
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
        lb.setStopping(hold);
        lb.setVelocity(80, percent);
        lb.spinFor(.5, sec);
        wait(.5, sec);
    }
}

void ladybrownReset()
{
    while (lbDistance.objectDistance(mm) > 40)
    {
        lb.spin(reverse);
    }
    lb.stop(coast);
}

int select = 0;
void ladybrown()
{
    switch (select)
    {
        case 0:
        {
            select++;
            ladybrownLoading();
            break;
        }
        case 1:
        {
            select++;
            ladybrownScoring();
            break;
        }
        case 2:
        {
            select = 0;
            ladybrownReset();
            break;
        }
    }
}