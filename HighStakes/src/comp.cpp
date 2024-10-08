#include "vex.h"
#include "pid.h"

using namespace vex;
using namespace Autons;

void drive(void)
{
    thread lockThread = thread(lock);
    thread intakeThread = thread(intake);
    Drivetrain.setDriveVelocity(100, percent);
    Drivetrain.setStopping(brake);
    while (true)
    {
        leftMotorA.setVelocity(Controller.Axis3.position() + Controller.Axis1.position(), percent);
        leftMotorB.setVelocity(Controller.Axis3.position() + Controller.Axis1.position(), percent);
        rightMotorA.setVelocity(Controller.Axis3.position() - Controller.Axis1.position(), percent);
        rightMotorB.setVelocity(Controller.Axis3.position() - Controller.Axis1.position(), percent);
        leftMotorA.spin(forward);
        leftMotorB.spin(forward);
        rightMotorA.spin(forward);
        rightMotorB.spin(forward);
        wait(10, msec);
    }
}

void auton(void)
{   
    LeftSide::run();
}