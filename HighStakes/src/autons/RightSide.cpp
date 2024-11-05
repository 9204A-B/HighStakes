#include "vex.h"
using namespace vex;

namespace Autons
{
    void RightSide::run(Autons::Color color)
    {
        pid piddrive = pid(leftMotors, rightMotors, 3.25, 1.145, 0.065, 0.15, 2.25);
        pid pidturn = pid(Inertial, leftMotors, rightMotors, 3.25, 0.08, 0.045, 0.02, 2.25);
        if (color == Autons::Color::red)
        {
            Drivetrain.setDriveVelocity(45, percent);
            Drivetrain.setTurnVelocity(18, percent);
            Drivetrain.setStopping(brake);
            
            pid piddrive = pid(leftMotors, rightMotors, 3.25, 1.145, 0.065, 0.15, 2.25);
            pid pidturn = pid(Inertial, leftMotors, rightMotors, 3.25, 0.08, 0.045, 0.02, 2.25);
            Drivetrain.driveFor(1.25, inches, true);
            Drivetrain.drive(reverse);
            waitUntil(goalDetect.objectDistance(mm) < 55);
            mobileGoalLock.set(true);
            Drivetrain.stop();
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(.65, sec);
            intakeMotors.stop();
            piddrive.move(4, reverse);
            Drivetrain.turnFor(left, 50, degrees, true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            piddrive.move(47.5, forward);
            intakeMotors.stop();
            Drivetrain.turnFor(180, degrees, true);
            piddrive.move(200, forward);
        }
        else
        {
            Drivetrain.setDriveVelocity(45, percent);
            Drivetrain.setTurnVelocity(18, percent);
            Drivetrain.setStopping(brake);
            
            pid piddrive = pid(leftMotors, rightMotors, 3.25, 1.145, 0.065, 0.15, 2.25);
            pid pidturn = pid(Inertial, leftMotors, rightMotors, 3.25, 0.08, 0.045, 0.02, 2.25);
            Drivetrain.driveFor(1.25, inches, true);
            Drivetrain.drive(reverse);
            waitUntil(goalDetect.objectDistance(mm) < 55);
            mobileGoalLock.set(true);
            Drivetrain.stop();
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(.65, sec);
            intakeMotors.stop();
            piddrive.move(4, reverse);
            Drivetrain.turnFor(left, 50, degrees, true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            piddrive.move(47.5, forward);
            intakeMotors.stop();
            Drivetrain.turnFor(180, degrees, true);
            piddrive.move(200, forward);
            wait(.5, sec);
            intakeMotors.stop();
        }
    }
}