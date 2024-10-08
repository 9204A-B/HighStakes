#include "vex.h"
using namespace vex;

namespace Autons
{
    void LeftSide::run()
    {
        piddrive.move(5, forward);
        piddrive.move(24, reverse);
        pidturn.turn(45, right);
        leftMotors.spin(reverse);
        rightMotors.spin(reverse);
        waitUntil(goalDetect.objectDistance(mm) < 55);
        mobileGoalLock.set(true);
        leftMotors.setVelocity(0, percent);
        rightMotors.setVelocity(0, percent);
        piddrive.move(4, reverse);
        pidturn.turn(90, right);
        intakeMotors.setVelocity(intakeSpeed, percent);
        intakeMotors.spin(forward);
        piddrive.move(8, forward);
        intakeMotors.stop();
        piddrive.move(1, reverse);
        pidturn.turn(90, right);
        intakeMotors.spin(forward);
        piddrive.move(10, forward);
        intakeMotors.stop();
        pidturn.turn(90, right);
        piddrive.move(10, forward);
    }
}