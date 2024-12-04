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
    if (allianceSelect == 0)
    {        
        switch (autonSelect)
        {        
            case 1:
            {                                
                Autons::RedAlliance::run(Autons::Route::fourRingMogo_Corner);
                break;
            }
            case 2:
            {
                Autons::RedAlliance::run(Autons::Route::fourRingMogo_Ladder);
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
            case 5:
            {
                Autons::RedAlliance::run(Autons::Route::mogoSide_GoalRush_Corner);
                break;
            }
            case 6:
            {
                Autons::RedAlliance::run(Autons::Route::mogoSide_GoalRush_Ladder);
                break;
            }
            default:
            {
                Autons::RedAlliance::run(Autons::Route::test);
                break;
            }
        }   
    }
    else if (allianceSelect == 1)
    {
        switch (autonSelect)
        {
            case 1:
            {
                Autons::BlueAlliance::run(Autons::Route::fourRingMogo_Corner);
                break;
            }
            case 2:
            {
                Autons::BlueAlliance::run(Autons::Route::fourRingMogo_Ladder);
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
            case 5:
            {
                Autons::BlueAlliance::run(Autons::Route::mogoSide_GoalRush_Corner);
                break;
            }
            case 6:
            {
                Autons::BlueAlliance::run(Autons::Route::mogoSide_GoalRush_Ladder);
                break;
            }
            default:
            {
                Autons::BlueAlliance::run(Autons::Route::test);
                break;
            }
        }
    }
    else
    {
        Autons::Skills::run();
    }
}