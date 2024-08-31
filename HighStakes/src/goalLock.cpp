#include "vex.h"

using namespace vex;

void lock()
{
    while (true)
    {
        // Wait until button press and goal detected
        while (!Controller.ButtonL1.pressing() || !goalDetect.objectDistance(mm) > 20)
        {
            wait(5, msec);
        }
        mobileGoalLock.set(true);

        // Wait until button release
        while (Controller.ButtonL1.pressing())
        {
            wait(5, msec);
        }

        while (!Controller.ButtonL1.pressing())
        {
            wait(5, msec);
        }
        mobileGoalLock.set(false);
        wait(5, msec);
    }
}

