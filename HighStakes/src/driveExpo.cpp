#include "vex.h"
#include "drive.h"

using namespace vex;

void setDriveExpo(vex::directionType direction, float percent, Side side)
{
    if (percent >= 0)
    {
        percent = _expoFunction(percent);
    }
    else
    {
        percent = -1 * _expoFunction(fabs(percent));
    }

    if (side == Side::LEFT)
    {
        leftMotors.spin(direction, percent, vex::velocityUnits::pct);
        return;
    }    

    rightMotors.spin(direction, percent, vex::velocityUnits::pct);
}

float _expoFunction(float percent)
{
    return 1.2 * pow(1.043, percent) - 1.2 + .2 * percent;
}