#include "vex.h"

using namespace vex;
using namespace Autons;

void drive(void)
{
    thread lockThread = thread(lock);
    thread intakeThread = thread(intake);
    thread lbThread = thread(ladybrown);
    thread timeThread = thread(startTimer);
    thread doinkerThread = thread(doink);
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
    Autons::Skills::run();
}