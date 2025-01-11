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
            // red alliance test slot

            // PID drift testing

            // change max voltage here
            pidDrivetrain.drive_max_voltage = 12;
            pidDrivetrain.turn_max_voltage = 12;

            // and timeouts
            pidDrivetrain.drive_timeout = 3000;
            pidDrivetrain.turn_timeout = 3000;

            // does 2 laps around the ladder
            pidDrivetrain.drive_distance(96);
            pidDrivetrain.turn_to_angle(90);
            pidDrivetrain.drive_distance(96);
            pidDrivetrain.turn_to_angle(180);
            pidDrivetrain.drive_distance(96);
            pidDrivetrain.turn_to_angle(270);
            pidDrivetrain.drive_distance(96);
            pidDrivetrain.turn_to_angle(0);

            pidDrivetrain.drive_distance(96);
            pidDrivetrain.turn_to_angle(90);
            pidDrivetrain.drive_distance(96);
            pidDrivetrain.turn_to_angle(180);
            pidDrivetrain.drive_distance(96);
            pidDrivetrain.turn_to_angle(270);
            pidDrivetrain.drive_distance(96);
            pidDrivetrain.turn_to_angle(0);

            // complete 2 laps, and then measure distance from original location
        }
        case Autons::Route::ClusterStart:
        {
            // starting position variables
            // only tweak startX, startY, startRot, and goalPoint please and thank you
            // startX and Y are measured from the center of the robot, so add 7.5" as needed when measuring
            // startX is number of inches to the LEFT of the center line / alliance stake
            // startY is number of inches from the wall
            // startRot is the angle it starts at relative to 0 degrees being the intake pointing into the field
            float startX = 8;
            float startY = 11;
            float startRot = -73;

            // goal point is the distance to the right of the goal where the robot stops before turning towards the goal
            float goalPoint = 12;
            float goalNodeHeading = -1 * atan((24 - goalPoint - startX) / (48 - goalPoint * 1.73 - startY) * (180 / 3.14));
            float goalNodeDist = sqrt(pow(24 - goalPoint - startX, 2) + pow(48 - goalPoint * 1.73 - startY, 2));
            float nodeToGoal = 2 * goalPoint;

            pidDrivetrain.drive_max_voltage = 12;
            pidDrivetrain.turn_max_voltage = 12;

            // ladybrown to score preload onto alliance
            pidDrivetrain.set_heading(startRot);
            ladybrownScoring();
            // wait(100, msec);
            ladybrownReset();

            // drive to goal node
            pidDrivetrain.turn_to_angle(goalNodeHeading);
            pidDrivetrain.drive_distance(-1 * goalNodeDist);

            // drive to goal and clamp
            pidDrivetrain.turn_to_angle(-30);
            pidDrivetrain.drive_max_voltage = 8;
            pidDrivetrain.drive_distance(-1 * nodeToGoal);
            mobileGoalLock.set(true);

            // turn and drive forwards for ring 2
            pidDrivetrain.drive_max_voltage = 12;
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            pidDrivetrain.turn_to_angle(90);
            pidDrivetrain.drive_distance(23 + 3.5);
            // wait(500, msec);

            // getting ring 3
            pidDrivetrain.turn_to_angle(180);
            float clusterTrim1 = 10;
            pidDrivetrain.drive_distance(24 - clusterTrim1);
            pidDrivetrain.drive_distance(-1 * (14 - clusterTrim1));

            // getting ring 4
            pidDrivetrain.turn_to_angle(180 + 30);
            float clusterTrim2 = 8.5;
            pidDrivetrain.drive_distance(13.9 - clusterTrim2);
            pidDrivetrain.drive_distance(-1 * (13.9 - clusterTrim2));

            break;
        }
        case Autons::Route::soloAWP:
        {
            // starting on the left
            // gets 3 rings onto a mobile goal + 1 alliance
            // SOLO AWP :D

            RedAlliance::run(Autons::Route::ClusterStart);

            // ladder touch
            pidDrivetrain.turn_to_angle(-90);
            intakeMotors.stop();
            pidDrivetrain.drive_max_voltage = 12;
            pidDrivetrain.drive_distance(31);

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