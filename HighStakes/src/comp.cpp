#include "vex.h"

using namespace vex;
using namespace Autons;

void drive(void)
{
    thread lockThread = thread(lock);
    thread intakeThread = thread(intake);
    thread lbThread = thread(ladybrown);
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
    if (allianceSelect == 0)
    {
        if (autonSelect == 0)
        {
            Autons::RedAlliance::run(Autons::Route::fourRingMogo_Corner);
        }
        else if (autonSelect == 1)
        {
            Autons::RedAlliance::run(Autons::Route::fourRingMogo_Ladder);
        }
        else if (autonSelect == 2)
        {
            Autons::RedAlliance::run(Autons::Route::mogoSide_Corner);
        }
        else if (autonSelect == 3)
        {
            Autons::RedAlliance::run(Autons::Route::mogoSide_Ladder);
        }
        else if (autonSelect == 4)
        {
            Autons::RedAlliance::run(Autons::Route::mogoSide_GoalRush);
        }
        else if (autonSelect == 5)
        {
            Autons::RedAlliance::run(Autons::Route::test);
        }
    }
    else if (allianceSelect == 1)
    {
        if (autonSelect == 0)
        {
            Autons::BlueAlliance::run(Autons::Route::fourRingMogo_Corner);
        }
        else if (autonSelect == 1)
        {
            Autons::BlueAlliance::run(Autons::Route::fourRingMogo_Ladder);
        }
        else if (autonSelect == 2)
        {
            Autons::BlueAlliance::run(Autons::Route::mogoSide_Corner);
        }
        else if (autonSelect == 3)
        {
            Autons::BlueAlliance::run(Autons::Route::mogoSide_Ladder);
        }
        else if (autonSelect == 4)
        {
            Autons::BlueAlliance::run(Autons::Route::mogoSide_GoalRush);
        }
        else if (autonSelect == 5)
        {
            Autons::BlueAlliance::run(Autons::Route::test);
        }
    }
    else
    {
        Autons::Skills::run();
    }

    // old auton runner code
    // if (autonSelect == 0)
    // {
    //     Autons::LeftSide::run(Autons::Color::red);
    // }
    // else if (autonSelect == 1)
    // {
    //     Autons::RightSide::run(Autons::Color::red);
    // }
    // else if (autonSelect == 2)
    // {
    //     Autons::LeftSide::run(Autons::Color::blue);
    // }
    // else if (autonSelect == 3)
    // {
    //     Autons::RightSide::run(Autons::Color::blue);
    // }
    // else
    // {
    //     Autons::Skills::run();
    // }
}