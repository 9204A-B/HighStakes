#include "vex.h"

using namespace vex;
using namespace Autons;

void drive(void)
{
    antiJamEnable = false;
    colorSortEnable = false;
    Drivetrain.setDriveVelocity(100, percent);
    Drivetrain.setStopping(brake);
    // thread lockThread = thread(lock);
    thread timeThread = thread(startTimer);
    thread doinkerThread = thread(doink);
    while (true)
    {
        leftMotors.setVelocity(Controller.Axis3.position() + Controller.Axis1.position() * 0.80, percent);
        rightMotors.setVelocity(Controller.Axis3.position() - Controller.Axis1.position() * 0.80, percent);
        leftMotors.spin(forward);
        rightMotors.spin(forward);
        wait(10, msec);
    }
}

void auton(void)
{
    colorSortEnable = true;
    if (allianceSelect == 0)
    {
        Autons::Skills::run();
        // Autons::RedAlliance::run(Autons::Route::soloAWP);
    }
    else if (allianceSelect == 1)
    {
        switch (autonSelect)
        {
        case 0:
        {
            Autons::RedAlliance::run(Autons::Route::test);
            break;
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