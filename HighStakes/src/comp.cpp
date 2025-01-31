#include "vex.h"

using namespace vex;
using namespace Autons;

void drive(void)
{
    Drivetrain.setDriveVelocity(100, percent);
    Drivetrain.setStopping(brake);
    thread lockThread = thread(lock);
    // thread intakeThread = thread(intake);
    thread timeThread = thread(startTimer);
    thread doinkerThread = thread(doink);
    while (true)
    {
<<<<<<< Updated upstream
        leftMotors.setVelocity(Controller.Axis3.position() + (pow(Controller.Axis1.position() / 100, turnExp) * 100 * turnScale), percent);
        rightMotors.setVelocity(Controller.Axis3.position() - (pow(Controller.Axis1.position() / 100, turnExp) * 100 * turnScale), percent);
=======
        leftMotors.setVelocity(Controller.Axis3.position() + Controller.Axis1.position() * 0.80, percent);
        rightMotors.setVelocity(Controller.Axis3.position() - Controller.Axis1.position() * 0.80, percent);
>>>>>>> Stashed changes
        leftMotors.spin(forward);
        rightMotors.spin(forward);
        wait(10, msec);
    }
}

void auton(void)
{
    if (allianceSelect == 0)
    {
        Autons::Skills::run();
    }
    else if (allianceSelect == 1)
    {
        switch (autonSelect)
        {
        case 0:
        {
            Autons::RedAlliance::run(Autons::Route::test);
        }
        case 1:
        {
            Autons::RedAlliance::run(Autons::Route::soloAWP);
            break;
        }
        case 2:
        {
            Autons::RedAlliance::run(Autons::Route::fourRing_Corner);
            break;
        }
        case 3:
        {
            Autons::RedAlliance::run(Autons::Route::mogoSide_Corner);
            break;
        }
        case 4:
        {
            Autons::RedAlliance::run(Autons::Route::mogoSide_Ladder);
            break;
        }
        }
    }
    else if (allianceSelect == 2)
    {
        switch (autonSelect)
        {
        case 0:
        {
            Autons::BlueAlliance::run(Autons::Route::test);
            break;
        }
        case 1:
        {
            Autons::BlueAlliance::run(Autons::Route::soloAWP);
            break;
        }
        case 2:
        {
            Autons::BlueAlliance::run(Autons::Route::fourRing_Corner);
            break;
        }
        case 3:
        {
            Autons::BlueAlliance::run(Autons::Route::mogoSide_Corner);
            break;
        }
        case 4:
        {
            Autons::BlueAlliance::run(Autons::Route::mogoSide_Ladder);
            break;
        }
        }
    }
}