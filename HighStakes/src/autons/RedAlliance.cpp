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

            float startX = 11;
            float startY = 9.5;
            float scoreRot = -72.5;

            // goal point is the distance to the right of the goal where the robot stops before turning towards the goal
            float goalHeading = (-90 + (atan((48 - startY) / (24 - startX))) * (180 / 3.141));
            float goalDist = -1 * (sqrt(pow(24 - startX, 2) + pow(48 - startY, 2)));

            pidDrivetrain.drive_max_voltage = 6;
            pidDrivetrain.turn_max_voltage = 8;

            //ladybrown to score preload onto alliance
            pidDrivetrain.turn_ki = 0;
            pidDrivetrain.turn_kd = 0;
            pidDrivetrain.turn_settle_error = 3;
            pidDrivetrain.set_heading(-90);
            pidDrivetrain.turn_to_angle(scoreRot);
            ladybrownScoring();
            ladybrownReset();
            wait(250, msec);

            pidDrivetrain.turn_max_voltage = 12;

            // drive to goal and clamp
            pidDrivetrain.turn_ki = 0.03;
            pidDrivetrain.turn_kd = 3;
            pidDrivetrain.turn_settle_error = 1;
            pidDrivetrain.turn_to_angle(goalHeading);
            pidDrivetrain.drive_distance(goalDist + 7);
            mobileGoalLock.set(true);

            // turn and drive for rings 2 and 3
            intakeMotors.setVelocity(intakeSpeed, percent);
            pidDrivetrain.drive_max_voltage = 8;
            wait(250, msec);
            
            pidDrivetrain.turn_to_angle(90 + 45);
            intakeMotors.spin(forward);
            pidDrivetrain.drive_distance(31.6 - 5); // tweak until the robot picks up ring and doesn't cross
            wait(500, msec);

            // SERIOUSLY TEST THE FOLLOWING ROUTE
            pidDrivetrain.right_swing_to_angle(90);
            wait(500, msec);
            pidDrivetrain.drive_distance(3);

            pidDrivetrain.turn_to_angle(10);
            pidDrivetrain.drive_distance(16);

            break;
        }
        case Autons::Route::ClusterStart:
        {
            // starting position variables
            // only tweak startX, startY, startRot, and goalPoint please and thank you
            // startX and Y are measured from the center of the robot, so add 7.5" as needed when measuring
            // startX is number of inches to the LEFT of the center line / alliance stake
            // startY is number of inches from the wall
            // startRot is the angle it starts at relative to 0 degrees being the intake pointing into the field
            float startX = 10;
            float startY = 9.5;
            float scoreRot = -70;

            // goal point is the distance to the right of the goal where the robot stops before turning towards the goal
            float goalHeading = (-90 + (atan((48 - startY) / (24 - startX))) * (180 / 3.141));
            float goalDist = -1 * (sqrt(pow(24 - startX, 2) + pow(48 - startY, 2)));

            pidDrivetrain.drive_max_voltage = 6;
            pidDrivetrain.turn_max_voltage = 8;

            //ladybrown to score preload onto alliance
            pidDrivetrain.turn_ki = 0;
            pidDrivetrain.turn_kd = 0;
            pidDrivetrain.turn_settle_error = 3;
            pidDrivetrain.set_heading(-90);
            pidDrivetrain.turn_to_angle(scoreRot);
            ladybrownScoring();
            ladybrownReset();
            wait(250, msec);

            pidDrivetrain.turn_max_voltage = 12;

            // drive to goal and clamp
            pidDrivetrain.turn_ki = 0.03;
            pidDrivetrain.turn_kd = 3;
            pidDrivetrain.turn_settle_error = 1;
            pidDrivetrain.turn_to_angle(goalHeading);
            pidDrivetrain.drive_distance(goalDist + 7);
            mobileGoalLock.set(true);

            // turn and drive for rings 2 and 3
            intakeMotors.setVelocity(intakeSpeed, percent);
            pidDrivetrain.drive_max_voltage = 8;
            wait(250, msec);
            
            pidDrivetrain.turn_to_angle(90 + 45);
            intakeMotors.spin(forward);
            pidDrivetrain.drive_distance(31.6 - 7); // tweak until the robot picks up ring and doesn't cross
            pidDrivetrain.drive_distance(-5);
            wait(250, msec);

            // SERIOUSLY TEST THE FOLLOWING ROUTE
            pidDrivetrain.turn_to_angle(115);
            wait(250, msec);
            pidDrivetrain.drive_distance(8.5);

            pidDrivetrain.turn_to_angle(10)
            pidDrivetrain.drive_distance(13);
            wait(500, msec);

            break;
        }
        case Autons::Route::soloAWP:
        {
            // starting on the left
            // gets 3 rings onto a mobile goal + 1 alliance
            // SOLO AWP :D

            RedAlliance::run(Autons::Route::ClusterStart);

            // ladder touch
            pidDrivetrain.turn_to_angle(-110);
            intakeMotors.stop();
            pidDrivetrain.drive_max_voltage = 11;
            pidDrivetrain.drive_distance(28);

            break;
        }
        case Autons::Route::fourRing_Corner:
        {
            // starting on the left
            // gets 3 rings onto a mobile goal + alliance
            // nearer to positive corner

            RedAlliance::run(Autons::Route::ClusterStart);

            // drive to corner
            pidDrivetrain.turn_to_angle(270 + 26.6);
            pidDrivetrain.drive_distance(53.7);

            break;
        }
        case Autons::Route::mogoSide_Corner:
        {
            // starting on the right of the mobile goal
            // scores 2 rings on 1 mobile goal
            // finishes in the corner

            // get mogo and drop match load
            pidDrivetrain.turn_to_angle(330);
            pidDrivetrain.drive_distance(-41.6);
            mobileGoalLock.set(true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(1000, msec);
            pidDrivetrain.turn_to_angle(270);
            pidDrivetrain.drive_distance(24);
            wait(2000, msec);
            intakeMotors.stop();

            // intake ring 2 and driving into the corner
            pidDrivetrain.drive_distance(12);
            pidDrivetrain.turn_to_angle(0);
            pidDrivetrain.drive_distance(12);

            break;
        }
        case Autons::Route::mogoSide_Ladder:
        {
            // starting on the right of the mobile goal
            // scores 2 rings on 1 mobile goal
            // finishes touching the ladder

            // get mogo and drop match load
            pidDrivetrain.drive_distance(-36);
            pidDrivetrain.turn_to_angle(270);
            pidDrivetrain.drive_distance(-12);
            mobileGoalLock.set(true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500, msec);

            // intake ring 2 and driving into the ladder
            pidDrivetrain.drive_distance(24);
            pidDrivetrain.turn_to_angle(90);
            pidDrivetrain.drive_distance(48 - 5); // tweak this until the robot just touches the ladder

            break;
        }
        }
    }
}