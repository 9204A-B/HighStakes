#include "vex.h"

using namespace vex;

void driverLock()
{
    while (Controller.ButtonL1.pressing())
    {
        if (locked == false && goalDetect.objectDistance(mm) <= clampDistance) 
        { 
            locked = !locked;
            mobileGoalLock.set(locked);
            return;
        }
 
        else if (locked == true)
 
        {
 
            locked = !locked; 
            mobileGoalLock.set(locked);
            return;
        }
        wait(10, msec);
    }
}