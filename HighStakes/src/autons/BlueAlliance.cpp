#include "vex.h"
#include <math.h>
using namespace vex;

namespace Autons
{
    void BlueAlliance::run(Autons::Route route)
    {
        // in JAR template, positive angles -> clockwise, negative -> counter-clockwise
        // this is basically the code from RedAlliance except all angles are multiplied by -1

        // this is literally just the red alliance auton except its 360 - (the angle)

        default_constants();
        switch (route)
        {
        case Autons::Route::test:
        {
            // blue testing slot
            break;
        }
        case Autons::Route::ClusterStart:
        {
            // starting position variables
            float startX = 10;
            float startY = 9.5;
            float scoreRot = 70;

            float goalHeading = (90 - (atan((48 - startY) / (24 - startX))) * (180 / 3.141));
            float goalDist = -1 * (sqrt(pow(24 - startX, 2) + pow(48 - startY, 2)));

            pidDrivetrain.drive_max_voltage = 7;
            pidDrivetrain.turn_max_voltage = 10;

            //ladybrown to score preload onto alliance
            pidDrivetrain.turn_ki = 0;
            pidDrivetrain.turn_kd = 0;
            pidDrivetrain.turn_settle_error = 5;
            pidDrivetrain.turn_timeout = 450;
            pidDrivetrain.set_heading(90);
            pidDrivetrain.turn_to_angle(scoreRot);
            ladybrownScoring();
            ladybrownReset();

            // drive to goal and clamp
            pidDrivetrain.turn_ki = 0.03;
            pidDrivetrain.turn_kd = 3;
            pidDrivetrain.turn_settle_error = 1;
            pidDrivetrain.turn_timeout = 800;
            pidDrivetrain.turn_to_angle(goalHeading);
            pidDrivetrain.drive_distance(goalDist + 7);
            mobileGoalLock.set(true);

            // turn and drive for rings 2 and 3
            intakeMotors.setVelocity(intakeSpeed, percent);
            pidDrivetrain.drive_max_voltage = 12;
            wait(250, msec);
            
            pidDrivetrain.turn_to_angle(-1 * (90 + 40));
            intakeMotors.spin(forward);
            pidDrivetrain.drive_distance(31.6 - 7.25); // tweak until the robot picks up ring and doesn't cross
            pidDrivetrain.drive_timeout = 800;
            pidDrivetrain.drive_distance(-5);

            // SERIOUSLY TEST THE FOLLOWING ROUTE
            pidDrivetrain.turn_to_angle(-115);
            pidDrivetrain.drive_distance(10);
            pidDrivetrain.drive_distance(-11);
            wait(250, msec);

            pidDrivetrain.turn_to_angle(-45);
            pidDrivetrain.drive_timeout = 1200;
            pidDrivetrain.drive_distance(13);
            wait(250, msec);

            break;
        }
        case Autons::Route::soloAWP:
        {
            // starting on the right
            // gets 3 rings onto a mobile goal + 1 alliance
            // SOLO AWP :D

            BlueAlliance::run(Autons::Route::ClusterStart);

            // ladder touch
            pidDrivetrain.turn_to_angle(110);
            intakeMotors.stop();
            pidDrivetrain.drive_max_voltage = 12;
            pidDrivetrain.drive_distance(28);

            break;
        }
        case Autons::Route::fourRing_Corner:
        {
            // starting on the right
            // gets 3 rings onto a mobile goal + alliance
            // nearer to positive corner

            BlueAlliance::run(Autons::Route::ClusterStart);

            // drive to corner
            pidDrivetrain.turn_to_angle(-1 * (270 + 26.6));
            pidDrivetrain.drive_distance(53.7);
            break;
        }
        case Autons::Route::MogoStart:
        {
            // starting position variables
            float startX = 10;
            float startY = 9.5;
            float scoreRot = -70;

            float goalHeading = (-90 + (atan((48 - startY) / (24 - startX))) * (180 / 3.141));
            float goalDist = -1 * (sqrt(pow(24 - startX, 2) + pow(48 - startY, 2)));

            pidDrivetrain.drive_max_voltage = 7;
            pidDrivetrain.turn_max_voltage = 10;

            //ladybrown to score preload onto alliance
            pidDrivetrain.turn_ki = 0;
            pidDrivetrain.turn_kd = 0;
            pidDrivetrain.turn_settle_error = 5;
            pidDrivetrain.turn_timeout = 450;
            pidDrivetrain.set_heading(-90);
            pidDrivetrain.turn_to_angle(scoreRot);
            ladybrownScoring();
            ladybrownReset();

            // drive to goal and clamp
            pidDrivetrain.turn_ki = 0.03;
            pidDrivetrain.turn_kd = 3;
            pidDrivetrain.turn_settle_error = 1;
            pidDrivetrain.turn_timeout = 800;
            pidDrivetrain.turn_to_angle(goalHeading);
            pidDrivetrain.drive_distance(goalDist + 7);
            mobileGoalLock.set(true);

            // intake ring 2
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(250, msec);
            pidDrivetrain.turn_to_angle(90);
            pidDrivetrain.drive_distance(24);

            break;
        }
        case Autons::Route::mogoSide_Corner:
        {
            BlueAlliance::run(Autons::Route::MogoStart);

            // driving into the corner
            pidDrivetrain.turn_to_angle(180 - 30);
            intakeMotors.stop();
            pidDrivetrain.drive_distance(-24);
            mobileGoalLock.set(false);
            wait(250, msec);

            pidDrivetrain.drive_distance(24);
            pidDrivetrain.turn_to_angle(0);

            break;
        }
        case Autons::Route::mogoSide_Ladder:
        {
            BlueAlliance::run(Autons::Route::MogoStart);

            // driving to ladder
            pidDrivetrain.turn_to_angle(90 + 18.4);
            intakeMotors.stop();
            pidDrivetrain.drive_distance(37);

            break;
        }
        }
    }
}