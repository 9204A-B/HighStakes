#include "vex.h"

using namespace vex;

void drive(void)
{
    Drivetrain.setDriveVelocity(100, percent);
    Drivetrain.setStopping(brake);
    while (true)
    {
        leftMotors.setVelocity(Controller.Axis3.position() + Controller.Axis2.position(), percent);
        rightMotors.setVelocity(Controller.Axis3.position() - Controller.Axis2.position(), percent);
        leftMotors.spin(forward);
        rightMotors.spin(forward);
        wait(10, msec);
    }
}

void auton(void)
{
    PIDdrive(300, 0);
}