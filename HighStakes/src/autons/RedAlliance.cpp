#include "vex.h"
#include <math.h>

using namespace vex;

namespace Autons
{
    void RedAlliance::run(Autons::Route route)
    {
        // in JAR template, positive angles -> clockwise, negative -> counter-clockwise
        default_constants();

        float startX = 10;
        float startY = 9;
        float negScoreRot = -55;

        float posScoreRot = -negScoreRot;
        float negGoalHeading = (-90 + (atan((48 - startY) / (24 - startX))) * (180 / 3.141));
        float posGoalHeading = -negGoalHeading;
        float goalDist = -1 * (sqrt(pow(24 - startX, 2) + pow(48 - startY, 2)));

        intakeMotors.setVelocity(70, percent);
        pidDrivetrain.drive_max_voltage = 9;
        pidDrivetrain.turn_max_voltage = 12;

        switch (route)
        {
        case Autons::Route::test:
        {
            // red test slot

            pidDrivetrain.set_heading(-90);
            Autons::RedAlliance::run(Autons::Route::neg_Route);

            break;
        }
        case Autons::Route::negAllianceStake:
        {
            // drives forward
            // scores alliance stake
            // drives back to start position

            pidDrivetrain.set_heading(-90);
            pidDrivetrain.set_coordinates(72 - 10, 8.5, -90);

            pidDrivetrain.turn_to_angle(negScoreRot - 5);
            Drive::MotorTurn(lbRotation, lb, 180, 12, 5, 300, 650, .16, 0, .6, 25);
            Drive::MotorTurn(lbRotation, lb, 0, 12, 5, 300, 650, .16, 0, .6, 25);

            pidDrivetrain.turn_to_angle(negGoalHeading + 5);
            pidDrivetrain.drive_distance(goalDist + 18);
            pidDrivetrain.drive_max_voltage = 5;
            pidDrivetrain.drive_distance(-13);

            break;
        }
        case Autons::Route::posAllianceStake:
        {
            // scores alliance stake starting from positive side

            pidDrivetrain.set_heading(90);
            pidDrivetrain.turn_to_angle(posScoreRot);
            Drive::MotorTurn(lbRotation, lb, 180, 12, 5, 300, 700, .16, 0, .6, 25);
            Drive::MotorTurn(lbRotation, lb, 0, 12, 5, 300, 700, .16, 0, .6, 25);

            pidDrivetrain.turn_to_angle(posGoalHeading);
            pidDrivetrain.drive_distance(goalDist + 18);
            pidDrivetrain.drive_max_voltage = 5;
            pidDrivetrain.drive_distance(-13);

            break;
        }
        case Autons::Route::noAlliance:
        {
            pidDrivetrain.set_heading(0);

            // distance from line to goal = 12 + 24 = 36
            // subrtract 7.5, half length of robot ; 28.5"
            pidDrivetrain.drive_distance(-28.5 + 12);
            pidDrivetrain.drive_max_voltage = 5;
            pidDrivetrain.drive_distance(-12);
        }
        case Autons::Route::neg_Ladder_End:
        {
            // touches the ladder for AWP

            pidDrivetrain.turn_to_angle(-90 - 18.4);
            intakeMotors.stop();
            pidDrivetrain.drive_distance(32.5);
            pidDrivetrain.drive_stop(brake);
            break;
        }
        case Autons::Route::neg_Corner_End:
        {
            // drives towards positive corner

            pidDrivetrain.drive_max_voltage = 12;
            pidDrivetrain.turn_to_angle(-90 + 14);
            pidDrivetrain.drive_distance(50);
            pidDrivetrain.drive_stop(brake);

            break;
        }
        case Autons::Route::neg_Route:
        {
            // clamps mogo and runs intake
            // scores 2 rings in center stack
            // scores 1 more ring

            mobileGoalLock.set(true);
            wait(250, msec);
            intakeMotors.spin(forward);

            pidDrivetrain.drive_max_voltage = 12;
            pidDrivetrain.turn_to_angle(180 - 45);
            pidDrivetrain.drive_distance(33.9 - 15);
            wait(100, msec);
            pidDrivetrain.drive_max_voltage = 9; // value subtracted from 17 should be the same as the value subtracted on the previous line

            pidDrivetrain.turn_to_angle(90);
            pidDrivetrain.drive_distance(36); // should put the robot on a line AND intaking a ring
            wait(100, msec);
            pidDrivetrain.drive_max_voltage = 9;
            pidDrivetrain.drive_distance(-24);

            pidDrivetrain.turn_to_angle(0);
            pidDrivetrain.drive_distance(24 - 6.6); // should put them right on top of a ring
            wait(750, msec);

            break;
        }
        case Autons::Route::pos_Ladder_End:
        {
            // touches the ladder for AWP

            pidDrivetrain.turn_to_angle(90 + 18.4);
            pidDrivetrain.drive_distance(32.5);
            pidDrivetrain.drive_stop(brake);

            break;
        }
        case Autons::Route::pos_Screen_End:
        {
            // positions robot for screening/3rd goal rush

            pidDrivetrain.drive_distance(8);
            pidDrivetrain.turn_to_angle(45);

            break;
        }
        case Autons::Route::pos_Route:
        {
            // clamps mogo and runs intake
            // scores 1 ring

            mobileGoalLock.set(true);
            intakeMotors.spin(forward);
            pidDrivetrain.drive_max_voltage = 9;
            wait(250, msec);

            pidDrivetrain.drive_timeout = 1100;
            pidDrivetrain.turn_to_angle(-90);
            pidDrivetrain.drive_distance(24);

            pidDrivetrain.turn_to_angle(90 + 60);
            pidDrivetrain.drive_distance(-10);
            mobileGoalLock.set(false);
            intakeMotors.stop();
            pidDrivetrain.drive_distance(10);

            break;
        }
        case Autons::Route::neg_3p1_Ladder:
        {
            // negative side 3 + 1 with ladder touch (quals)

            Autons::RedAlliance::run(Autons::Route::negAllianceStake);
            Autons::RedAlliance::run(Autons::Route::neg_Route);
            Autons::RedAlliance::run(Autons::Route::neg_Ladder_End);

            break;
        }
        case Autons::Route::neg_3p1_Elim:
        {
            // negative side 3 + 1 ending near positive corner (elims)

            Autons::RedAlliance::run(Autons::Route::negAllianceStake);
            Autons::RedAlliance::run(Autons::Route::neg_Route);
            Autons::RedAlliance::run(Autons::Route::neg_Ladder_End);

            break;
        }
        case Autons::Route::neg_4r_Ladder:
        {
            // negative side 4-ring with ladder touch (quals)

            Autons::RedAlliance::run(Autons::Route::noAlliance);
            Autons::RedAlliance::run(Autons::Route::neg_Route);
            Autons::RedAlliance::run(Autons::Route::neg_Ladder_End);

            break;
        }
        case Autons::Route::neg_4r_Elim:
        {
            // negative side 4-ring ending near positive corner (elims)

            Autons::RedAlliance::run(Autons::Route::noAlliance);
            Autons::RedAlliance::run(Autons::Route::neg_Route);
            Autons::RedAlliance::run(Autons::Route::neg_Corner_End);

            break;
        }
        case Autons::Route::pos_1p1_Ladder:
        {
            // positive side 1 + 1 with ladder touch (quals)

            Autons::RedAlliance::run(Autons::Route::posAllianceStake);
            Autons::RedAlliance::run(Autons::Route::pos_Route);
            Autons::RedAlliance::run(Autons::Route::pos_Ladder_End);

            break;
        }
        case Autons::Route::pos_1p1_Elim:
        {
            // positive side 1 + 1 screening ready (elims)

            Autons::RedAlliance::run(Autons::Route::posAllianceStake);
            Autons::RedAlliance::run(Autons::Route::pos_Route);
            Autons::RedAlliance::run(Autons::Route::pos_Screen_End);

            break;
        }
        case Autons::Route::pos_2r_Ladder:
        {
            // positive side 2-ring with ladder touch (quals)

            Autons::RedAlliance::run(Autons::Route::noAlliance);
            Autons::RedAlliance::run(Autons::Route::pos_Route);
            Autons::RedAlliance::run(Autons::Route::pos_Ladder_End);

            break;
        }
        case Autons::Route::pos_2r_Elim:
        {
            // positive side 2-ring screening ready (elims)

            Autons::RedAlliance::run(Autons::Route::noAlliance);
            Autons::RedAlliance::run(Autons::Route::pos_Route);
            Autons::RedAlliance::run(Autons::Route::pos_Screen_End);

            break;
        }
        }
    }
}