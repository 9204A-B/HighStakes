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
        float startY = 9.5;
        float negScoreRot = -70;

        float posScoreRot = -negScoreRot;
        float negGoalHeading = (-90 + (atan((48 - startY) / (24 - startX))) * (180 / 3.141));
        float posGoalHeading = -negGoalHeading;
        float goalDist = -1 * (sqrt(pow(24 - startX, 2) + pow(48 - startY, 2)));

        intakeMotors.setVelocity(intakeSpeed, percent);
        pidDrivetrain.drive_max_voltage = 9;
        pidDrivetrain.turn_max_voltage = 10;

        switch (route)
        {
        case Autons::Route::test:
        {
            // red test slot
            break;
        }
        case Autons::Route::negAllianceStake:
        {
            // drives forward
            // scores alliance stake
            // drives back to start position

            pidDrivetrain.set_heading(-90);

            pidDrivetrain.turn_to_angle(negScoreRot);
            Drive::MotorTurn(lbRotation, lb, 180, 10, 5, 300, 750, .16, 0, .6, 25);
            Drive::MotorTurn(lbRotation, lb, 0, 12, 5, 300, 750, .16, 0, .6, 25);

            pidDrivetrain.turn_to_angle(negGoalHeading);
            pidDrivetrain.drive_distance(goalDist + 17);
            pidDrivetrain.drive_max_voltage = 6;
            pidDrivetrain.drive_distance(-10);
            
            break;
        }
        case Autons::Route::posAllianceStake:
        {
            // scores alliance stake starting from positive side

            pidDrivetrain.set_heading(posScoreRot);
            Drive::MotorTurn(lbRotation, lb, 180, 10, 5, 300, 750, .16, 0, .6, 25);
            Drive::MotorTurn(lbRotation, lb, 0, 12, 5, 300, 750, .16, 0, .6, 25);

            pidDrivetrain.turn_to_angle(posGoalHeading);
            pidDrivetrain.drive_distance(goalDist + 17);
            pidDrivetrain.drive_max_voltage = 6;
            pidDrivetrain.drive_distance(-10);
        }
        case Autons::Route::neg_Ladder_End:
        {
            // touches the ladder for AWP

            pidDrivetrain.turn_to_angle(-90 - 18.4);
            intakeMotors.stop();
            pidDrivetrain.drive_distance(38);
            break;
        }
        case Autons::Route::neg_Corner_End:
        {
            // drives towards positive corner

            break;
        }
        case Autons::Route::neg_Route:
        {
            // clamps mogo and runs intake
            // scores 2 rings in center stack
            // scores 1 more ring

            mobileGoalLock.set(true);
            wait(500, msec);
            intakeMotors.spin(forward);

            pidDrivetrain.drive_max_voltage = 9;
            pidDrivetrain.turn_to_angle(180 - 45);
            pidDrivetrain.drive_distance(33.9 - 9.5);
            wait(100, msec);
            pidDrivetrain.drive_distance(-1 * (17 - 9.5)); // value subtracted from 17 should be the same as the value subtracted on the previous line

            pidDrivetrain.turn_to_angle(180 - 61.3); // 61.3 = arctan([12 + 3.5] / [12 - 3.5])
            pidDrivetrain.drive_distance(11);      // should put the robot on a line AND intaking a ring
            wait(100, msec);

            pidDrivetrain.turn_to_angle(0);
            pidDrivetrain.drive_distance(24 - 6.6); // should put them right on top of a ring
            wait(750, msec);

            break;
        }
        case Autons::Route::pos_Ladder_End:
        {
            // touches the ladder for AWP

            break;
        }
        case Autons::Route::pos_Screen_End:
        {
            // positions robot for screening/3rd goal rush

            break;
        }
        case Autons::Route::pos_Route:
        {
            // clamps mogo and runs intake
            // scores 1 ring

            mobileGoalLock.set(true);
            intakeMotors.spin(forward);

            pidDrivetrain.turn_to_angle(-90);
            pidDrivetrain.drive_distance(24);

            pidDrivetrain.turn_to_angle(63.4);
            pidDrivetrain.drive_distance(53.7 + 7);
            wait(1000, msec);
            pidDrivetrain.drive_distance(-7);

            break;
        }
        case Autons::Route::neg_3p1_Ladder:
        {
            // negative side 3 + 1 with ladder touch (quals)

            pidDrivetrain.set_heading(neg_StartAngle);

            Autons::RedAlliance::run(Autons::Route::allianceStake);
            Autons::RedAlliance::run(Autons::Route::neg_Route);
            Autons::RedAlliance::run(Autons::Route::neg_Ladder_End);

            break;
        }
        case Autons::Route::neg_3p1_Elim:
        {
            // negative side 3 + 1 ending near positive corner (elims)

            pidDrivetrain.set_heading(neg_StartAngle);

            Autons::RedAlliance::run(Autons::Route::allianceStake);
            Autons::RedAlliance::run(Autons::Route::neg_Route);
            Autons::RedAlliance::run(Autons::Route::neg_Ladder_End);

            break;
        }
        case Autons::Route::neg_4r_Ladder:
        {
            // negative side 4-ring with ladder touch (quals)

            pidDrivetrain.set_heading(neg_StartAngle);

            Autons::RedAlliance::run(Autons::Route::neg_Route);
            Autons::RedAlliance::run(Autons::Route::neg_Ladder_End);

            break;
        }
        case Autons::Route::neg_4r_Elim:
        {
            // negative side 4-ring ending near positive corner (elims)

            pidDrivetrain.set_heading(neg_StartAngle);

            Autons::RedAlliance::run(Autons::Route::neg_Route);
            Autons::RedAlliance::run(Autons::Route::neg_Corner_End);

            break;
        }
        case Autons::Route::pos_1p1_Ladder:
        {
            // positive side 1 + 1 with ladder touch (quals)

            pidDrivetrain.set_heading(pos_StartAngle);

            Autons::RedAlliance::run(Autons::Route::allianceStake);
            Autons::RedAlliance::run(Autons::Route::pos_Route);
            Autons::RedAlliance::run(Autons::Route::pos_Ladder_End);

            break;
        }
        case Autons::Route::pos_1p1_Elim:
        {
            // positive side 1 + 1 screening ready (elims)

            pidDrivetrain.set_heading(pos_StartAngle);

            Autons::RedAlliance::run(Autons::Route::allianceStake);
            Autons::RedAlliance::run(Autons::Route::pos_Route);
            Autons::RedAlliance::run(Autons::Route::pos_Screen_End);

            break;
        }
        case Autons::Route::pos_2r_Ladder:
        {
            // positive side 2-ring with ladder touch (quals)

            pidDrivetrain.set_heading(pos_StartAngle);

            Autons::RedAlliance::run(Autons::Route::pos_Route);
            Autons::RedAlliance::run(Autons::Route::pos_Ladder_End);

            break;
        }
        case Autons::Route::pos_2r_Elim:
        {
            // positive side 2-ring screening ready (elims)

            pidDrivetrain.set_heading(pos_StartAngle);

            Autons::RedAlliance::run(Autons::Route::pos_Route);
            Autons::RedAlliance::run(Autons::Route::pos_Screen_End);

            break;
        }
        }
    }
}