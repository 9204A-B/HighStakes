#include "vex.h"
#include <math.h>

using namespace vex;

namespace Autons
{
    void RedAlliance::run(Autons::Route route)
    {
        // in JAR template, positive angles -> clockwise, negative -> counter-clockwise
        default_constants();
        switch (route)
        {
        case Autons::Route::test:
        {
            // red test slot
            break;
        }
        case Autons::Route::allianceStake:
        {
            // drives forward
            // scores alliance stake
            // drives back to start position

            pidDrivetrain.drive_distance(3);
            Drive::MotorTurn(lbRotation, lb, 200, 12, 0, 300, 750, .16, 0, .75, 25);
            pidDrivetrain.drive_max_voltage = 8;
            pidDrivetrain.drive_distance(-36);

            mobileGoalLock.set(true);
            Drive::MotorTurn(lbRotation, lb, 0, 12, 5, 300, 750, .16, 0, .75, 25);
            break;
        }
        case Autons::Route::neg_Ladder_End:
        {
            // touches the ladder for AWP

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

            break;
        }
        case Autons::Route::neg_3p1_Ladder:
        {
            // negative side 3 + 1 with ladder touch (quals)

            Autons::RedAlliance::run(Autons::Route::allianceStake);
            Autons::RedAlliance::run(Autons::Route::neg_Route);
            Autons::RedAlliance::run(Autons::Route::neg_Ladder_End);

            break;
        }
        case Autons::Route::neg_3p1_Elim:
        {
            // negative side 3 + 1 ending near positive corner (elims)

            Autons::RedAlliance::run(Autons::Route::allianceStake);
            Autons::RedAlliance::run(Autons::Route::neg_Route);
            Autons::RedAlliance::run(Autons::Route::neg_Ladder_End);

            break;
        }
        case Autons::Route::neg_4r_Ladder:
        {
            // negative side 4-ring with ladder touch (quals)

            Autons::RedAlliance::run(Autons::Route::neg_Route);
            Autons::RedAlliance::run(Autons::Route::neg_Ladder_End);

            break;
        }
        case Autons::Route::neg_4r_Elim:
        {
            // negative side 4-ring ending near positive corner (elims)

            Autons::RedAlliance::run(Autons::Route::neg_Route);
            Autons::RedAlliance::run(Autons::Route::neg_Corner_End);

            break;
        }
        case Autons::Route::pos_1p1_Ladder:
        {
            // positive side 1 + 1 with ladder touch (quals)

            Autons::RedAlliance::run(Autons::Route::allianceStake);
            Autons::RedAlliance::run(Autons::Route::pos_Route);
            Autons::RedAlliance::run(Autons::Route::pos_Ladder_End);

            break;
        }
        case Autons::Route::pos_1p1_Elim:
        {
            // positive side 1 + 1 screening ready (elims)

            Autons::RedAlliance::run(Autons::Route::allianceStake);
            Autons::RedAlliance::run(Autons::Route::pos_Route);
            Autons::RedAlliance::run(Autons::Route::pos_Screen_End);

            break;
        }
        case Autons::Route::pos_2r_Ladder:
        {
            // positive side 2-ring with ladder touch (quals)

            Autons::RedAlliance::run(Autons::Route::pos_Route);
            Autons::RedAlliance::run(Autons::Route::pos_Ladder_End);

            break;
        }
        case Autons::Route::pos_2r_Elim:
        {
            // positive side 2-ring screening ready (elims)

            Autons::RedAlliance::run(Autons::Route::pos_Route);
            Autons::RedAlliance::run(Autons::Route::pos_Screen_End);

            break;
        }
        }
    }
}