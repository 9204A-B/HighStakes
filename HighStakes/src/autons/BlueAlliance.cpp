#include "vex.h"
#include <math.h>

// to convert from RedAlliance to BlueAlliance, negate all angles (multiply by -1)

using namespace vex;

namespace Autons
{
    void BlueAlliance::run(Autons::Route route)
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
        case Autons::Route::negAllianceStake:
        {
            // drives forward
            // scores alliance stake
            // drives back to start position

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

            Autons::BlueAlliance::run(Autons::Route::negAllianceStake);
            Autons::BlueAlliance::run(Autons::Route::neg_Route);
            Autons::BlueAlliance::run(Autons::Route::neg_Ladder_End);

            break;
        }
        case Autons::Route::neg_3p1_Elim:
        {
            // negative side 3 + 1 ending near positive corner (elims)

            Autons::BlueAlliance::run(Autons::Route::negAllianceStake);
            Autons::BlueAlliance::run(Autons::Route::neg_Route);
            Autons::BlueAlliance::run(Autons::Route::neg_Ladder_End);

            break;
        }
        case Autons::Route::neg_4r_Ladder:
        {
            // negative side 4-ring with ladder touch (quals)

            Autons::BlueAlliance::run(Autons::Route::neg_Route);
            Autons::BlueAlliance::run(Autons::Route::neg_Ladder_End);

            break;
        }
        case Autons::Route::neg_4r_Elim:
        {
            // negative side 4-ring ending near positive corner (elims)

            Autons::BlueAlliance::run(Autons::Route::neg_Route);
            Autons::BlueAlliance::run(Autons::Route::neg_Corner_End);

            break;
        }
        case Autons::Route::pos_1p1_Ladder:
        {
            // positive side 1 + 1 with ladder touch (quals)

            Autons::BlueAlliance::run(Autons::Route::posAllianceStake);
            Autons::BlueAlliance::run(Autons::Route::pos_Route);
            Autons::BlueAlliance::run(Autons::Route::pos_Ladder_End);

            break;
        }
        case Autons::Route::pos_1p1_Elim:
        {
            // positive side 1 + 1 screening ready (elims)

            Autons::BlueAlliance::run(Autons::Route::posAllianceStake);
            Autons::BlueAlliance::run(Autons::Route::pos_Route);
            Autons::BlueAlliance::run(Autons::Route::pos_Screen_End);

            break;
        }
        case Autons::Route::pos_2r_Ladder:
        {
            // positive side 2-ring with ladder touch (quals)

            Autons::BlueAlliance::run(Autons::Route::pos_Route);
            Autons::BlueAlliance::run(Autons::Route::pos_Ladder_End);

            break;
        }
        case Autons::Route::pos_2r_Elim:
        {
            // positive side 2-ring screening ready (elims)

            Autons::BlueAlliance::run(Autons::Route::pos_Route);
            Autons::BlueAlliance::run(Autons::Route::pos_Screen_End);

            break;
        }
        }
    }
}