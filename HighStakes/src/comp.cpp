#include "vex.h"
#include "drive.h"

using namespace vex;
using namespace Autons;

void drive(void)
{
    antiJamEnable = false;
    colorSortEnable = true;
    Drivetrain.setDriveVelocity(100, percent);
    Drivetrain.setStopping(brake);
    thread timeThread = thread(startTimer);
    thread doinkerThread = thread(doink);
    while (true)
    {
        setDriveExpo(vex::directionType::fwd, (Controller.Axis3.position() + Controller.Axis1.position()), Side::LEFT);
        setDriveExpo(vex::directionType::fwd, (Controller.Axis3.position() - Controller.Axis1.position()), Side::RIGHT);
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
            Autons::RedAlliance::run(Autons::Route::neg_3p1_Ladder);
            break;
        }
        case 2:
        {
            Autons::RedAlliance::run(Autons::Route::neg_4r_Ladder);
            break;
        }
        case 3:
        {
            Autons::RedAlliance::run(Autons::Route::pos_1p1_Ladder);
            break;
        }
        case 4:
        {
            Autons::RedAlliance::run(Autons::Route::pos_2r_Ladder);
            break;
        }
        case 5:
        {
            Autons::RedAlliance::run(Autons::Route::neg_3p1_Elim);
            break;
        }
        case 6:
        {
            Autons::RedAlliance::run(Autons::Route::neg_4r_Elim);
            break;
        }
        case 7:
        {
            Autons::RedAlliance::run(Autons::Route::pos_1p1_Elim);
            break;
        }
        case 8:
        {
            Autons::RedAlliance::run(Autons::Route::pos_2r_Elim);
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
            Autons::BlueAlliance::run(Autons::Route::neg_3p1_Ladder);
            break;
        }
        case 2:
        {
            Autons::BlueAlliance::run(Autons::Route::neg_4r_Ladder);
            break;
        }
        case 3:
        {
            Autons::BlueAlliance::run(Autons::Route::pos_1p1_Ladder);
            break;
        }
        case 4:
        {
            Autons::BlueAlliance::run(Autons::Route::pos_2r_Ladder);
            break;
        }
        case 5:
        {
            Autons::BlueAlliance::run(Autons::Route::neg_3p1_Elim);
            break;
        }
        case 6:
        {
            Autons::BlueAlliance::run(Autons::Route::neg_4r_Elim);
            break;
        }
        case 7:
        {
            Autons::BlueAlliance::run(Autons::Route::pos_1p1_Elim);
            break;
        }
        case 8:
        {
            Autons::BlueAlliance::run(Autons::Route::pos_2r_Elim);
            break;
        }
        }
    }
}