#include "vex.h"
#include "pid.h"

using namespace vex;
using namespace Autons;

void drive(void)
{
    thread lockThread = thread(lock);
    thread intakeThread = thread(intake);
    thread armThread = thread(armMovement);
    Drivetrain.setDriveVelocity(100, percent);
    Drivetrain.setStopping(brake);
    while (true)
    {
        leftMotorA.setVelocity(Controller.Axis3.position() + Controller.Axis1.position() * .8, percent);
        leftMotorB.setVelocity(Controller.Axis3.position() + Controller.Axis1.position() * .8, percent);
        rightMotorA.setVelocity(Controller.Axis3.position() - Controller.Axis1.position() * .8, percent);
        rightMotorB.setVelocity(Controller.Axis3.position() - Controller.Axis1.position() * .8, percent);
        leftMotorA.spin(forward);
        leftMotorB.spin(forward);
        rightMotorA.spin(forward);
        rightMotorB.spin(forward);
        wait(10, msec);
    }
}

void auton(void)
{   
    pid piddrive = pid(leftMotors, rightMotors, 3.25, 1.145, 0.065, 0.15, 2.25);
    pid pidturn = pid(Inertial, leftMotors, rightMotors, 3.25, 0.08, 0.045, 0.02, 2.25);
    LeftSide::run();
    //add auton selector
}