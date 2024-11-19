#include "vex.h"
using namespace vex;

namespace Autons
{
    void LeftSide::run(Autons::Color color)
    {   
        default_constants();
        switch (color)
        {
            case Autons::Color::red:
            {     
                pidDrivetrain.drive_distance(10);
                break;
            }
            case Autons::Color::blue:
            {
                break;
            }
        }    
        // if (color == Autons::Color::red)
        // {
        //     Drivetrain.setDriveVelocity(45, percent);
        //     Drivetrain.setTurnVelocity(18, percent);
        //     Drivetrain.setStopping(brake);                    
        //     Drivetrain.driveFor(1.25, inches, true);
        //     Drivetrain.drive(reverse);
        //     waitUntil(goalDetect.objectDistance(mm) < clampDistance);
        //     mobileGoalLock.set(true);
        //     Drivetrain.stop();
        //     intakeMotors.setVelocity(intakeSpeed, percent);
        //     intakeMotors.spin(forward);
        //     wait(.65, sec);
        //     intakeMotors.stop();
        //     piddrive.move(4, reverse);
        //     Drivetrain.turnFor(50, degrees, true);
        //     intakeMotors.setVelocity(intakeSpeed, percent);
        //     intakeMotors.spin(forward);
        //     piddrive.move(47.5, forward);
        //     intakeMotors.stop();
        //     Drivetrain.turnFor(180, degrees, true);
        //     piddrive.move(200, forward);
        //     wait(.5, sec);
        //     intakeMotors.stop();
        // }
        // else
        // {
        //     Drivetrain.setDriveVelocity(45, percent);
        //     Drivetrain.setTurnVelocity(18, percent);
        //     Drivetrain.setStopping(brake);
            
        //     pid piddrive = pid(leftMotors, rightMotors, 3.25, 1.145, 0.065, 0.15, 2.25);
        //     pid pidturn = pid(Inertial, leftMotors, rightMotors, 3.25, 0.08, 0.045, 0.02, 2.25);
        //     Drivetrain.driveFor(1.25, inches, true);
        //     Drivetrain.drive(reverse);
        //     waitUntil(goalDetect.objectDistance(mm) < clampDistance);
        //     mobileGoalLock.set(true);
        //     Drivetrain.stop();
        //     intakeMotors.setVelocity(intakeSpeed, percent);
        //     intakeMotors.spin(forward);
        //     wait(.65, sec);
        //     intakeMotors.stop();
        //     piddrive.move(4, reverse);
        //     Drivetrain.turnFor(50, degrees, true);
        //     intakeMotors.setVelocity(intakeSpeed, percent);
        //     intakeMotors.spin(forward);
        //     piddrive.move(47.5, forward);
        //     intakeMotors.stop();
        //     Drivetrain.turnFor(95, degrees, true);
        //     piddrive.move(100, forward);
        // }
    }
}