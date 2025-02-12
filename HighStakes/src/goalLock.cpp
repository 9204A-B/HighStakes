#include "vex.h"

using namespace vex;

void driverLock()
{
    if (locked == false && goalDetect.objectDistance(mm) <= clampDistance)
    {
        locked = !locked;
        mobileGoalLock.set(locked);
    }
    else if (locked == true)
    {
        locked = !locked;
        mobileGoalLock.set(locked);
    }
}

void lock()
{
    while (true)
    {

        while ((!(Controller.ButtonL1.pressing() && goalDetect.objectDistance(mm) <= clampDistance)) || locked)
        {
            wait(5, msec);
        }

        locked = !locked;
        mobileGoalLock.set(locked);

        while (Controller.ButtonL1.pressing())
        {
            wait(5, msec);
        }

        wait(10, msec);
    }
}

