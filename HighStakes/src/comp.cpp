#include "vex.h"
#include "pid.h"

using namespace vex;

void drive(void)
{
    thread lock = thread(lock);

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
    pid piddrive = pid(leftMotors, rightMotors, 3.25, 1.145, 0.065, 0.15, 2.25);
    pid pidturn = pid(Inertial, leftMotors, rightMotors, 3.25, 0.15, 0.0, 0.0, 2.25);
    piddrive.enable = true;
    //piddrive.move(5, forward);
    piddrive.turn(90, left);
}