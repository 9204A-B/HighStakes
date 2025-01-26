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
            // only tweak startX, startY, startRot, and goalPoint please and thank you
            // startX and Y are measured from the center of the robot, so add 7.5" as needed when measuring
            // startX is number of inches to the RIGHT of the center line / alliance stake
            // startY is number of inches from the wall
            // startRot is the angle it starts at relative to 0 degrees being the intake pointing into the field
            float startX = 11;
            float startY = 10;
            float scoreRot = 72.5;

            // goal point is the distance to the right of the goal where the robot stops before turning towards the goal
            float goalHeading = (90 - (atan((48 - startY) / (24 - startX))) * (180 / 3.141));
            float goalDist = -1 * (sqrt(pow(24 - startX, 2) + pow(48 - startY, 2)));

            pidDrivetrain.drive_max_voltage = 6;
            pidDrivetrain.turn_max_voltage = 12;

            // ladybrown to score preload onto alliance
            pidDrivetrain.set_heading(90);
            pidDrivetrain.turn_to_angle(scoreRot);
            ladybrownScoring();
            ladybrownReset();

            // drive to goal and clamp
            pidDrivetrain.turn_to_angle(goalHeading);
            pidDrivetrain.drive_distance(goalDist + 7);
            mobileGoalLock.set(true);
            // turn and drive forwards for ring 2
            intakeMotors.setVelocity(intakeSpeed, percent);
            wait(100, msec);
            pidDrivetrain.turn_to_angle(-90);

            // make sure the robot is perfectly aligned before running anything after this

            intakeMotors.spin(forward);
            pidDrivetrain.drive_max_voltage = 8;
            pidDrivetrain.drive_distance(24 - 2);
            wait(250, msec);

            // getting ring 3
            pidDrivetrain.turn_to_angle(-180);
            pidDrivetrain.drive_distance(16);
            wait(250, msec);

            // getting ring 4
            pidDrivetrain.drive_distance(-6);
            pidDrivetrain.turn_to_angle((180 - 30) * -1);
            pidDrivetrain.drive_distance(6);
            wait(250, msec);
            pidDrivetrain.drive_distance(-6);

            break;
        }
        case Autons::Route::soloAWP:
        {
            // starting on the right
            // gets 3 rings onto a mobile goal + 1 alliance
            // SOLO AWP :D

            BlueAlliance::run(Autons::Route::ClusterStart);

            // ladder touch
            pidDrivetrain.turn_to_angle(90);
            intakeMotors.stop();
            pidDrivetrain.drive_max_voltage = 12;
            pidDrivetrain.drive_distance(30);

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
        case Autons::Route::mogoSide_Corner:
        {
            // starting on the left of the mobile goal
            // scores 2 rings on 1 mobile goal
            // finishes in the corner

            // get mogo and drop match load
            pidDrivetrain.drive_distance(-36);
            pidDrivetrain.turn_to_angle(360 - 270);
            pidDrivetrain.drive_distance(-12);
            mobileGoalLock.set(true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500, msec);

            // intake ring 2 and driving into the corner
            pidDrivetrain.drive_distance(36);
            pidDrivetrain.turn_to_angle(0);
            pidDrivetrain.drive_distance(24);

            break;
        }
        case Autons::Route::mogoSide_Ladder:
        {
            // starting on the left of the mobile goal
            // scores 2 rings on 1 mobile goal
            // finishes touching the ladder

            // get mogo and drop match load
            pidDrivetrain.drive_distance(-36);
            pidDrivetrain.turn_to_angle(360 - 270);
            pidDrivetrain.drive_distance(-12);
            mobileGoalLock.set(true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500, msec);

            // intake ring 2 and driving into the ladder
            pidDrivetrain.drive_distance(24);
            pidDrivetrain.turn_to_angle(360 - 90);
            pidDrivetrain.drive_distance(48 - 5); // tweak this until the robot just touches the ladder

            break;
        }
        }
    }
}