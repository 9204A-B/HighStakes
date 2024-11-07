#include "vex.h"

using namespace vex;

void lock()
{
    while (true)
    {

            while (!(Controller.ButtonL1.pressing() && goalDetect.objectDistance(mm) <= clampDistance))
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
        wait(5, msec);
}

