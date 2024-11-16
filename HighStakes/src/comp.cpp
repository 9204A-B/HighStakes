#include "vex.h"
#include "pid.h"

using namespace vex;
using namespace Autons;

void drive(void)
{
    thread lockThread = thread(lock);
    thread intakeThread = thread(intake);
    thread timeThread = thread(startTimer);
    Drivetrain.setDriveVelocity(100, percent);
    Drivetrain.setStopping(brake);
    while (true)
    {
        leftMotors.setVelocity(Controller.Axis3.position() + Controller.Axis1.position() * .8, percent);
        rightMotors.setVelocity(Controller.Axis3.position() - Controller.Axis1.position() * .8, percent);
        leftMotors.spin(forward);
        rightMotors.spin(forward);
        wait(10, msec);
    }
}

void auton(void)
{   
    //pid piddrive = pid(leftMotors, rightMotors, 3.25, 1.145, 0.065, 0.15, 2.25);
    //pid pidturn = pid(Inertial, leftMotors, rightMotors, 3.25, 0.08, 0.045, 0.02, 2.25);
    if (autonSelect == 0)
    {
        Autons::LeftSide::run(Autons::Color::red);
    }
    else if (autonSelect == 1)
    {
        Autons::RightSide::run(Autons::Color::red);
    }
    else if (autonSelect == 2)
    {
        Autons::LeftSide::run(Autons::Color::blue);
    }
    else if (autonSelect == 3)
    {
        Autons::RightSide::run(Autons::Color::blue);
    }
    else
    {
        Autons::Skills::run();
    }
}