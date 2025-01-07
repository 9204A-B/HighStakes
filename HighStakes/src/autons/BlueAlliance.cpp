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
            float startX = 12;
            float startY = 12;
            float startRot = 30;

            // goal point is the distance to the right of the goal where the robot stops before turning towards the goal
            float goalPoint = 12;

            float goalNodeHeading = atan((24 - goalPoint - startX) / (48 - goalPoint * 1.73 - startY)) * (180 / 3.14);
            float goalNodeDist = sqrt(pow(24 - goalPoint - startX, 2) + pow(48 - goalPoint * 1.73 - startY, 2));
            float nodeToGoal = 0.5 / goalPoint;

            pidDrivetrain.drive_max_voltage = 12;
            pidDrivetrain.turn_max_voltage = 12;
            intakeMotors.setVelocity(intakeSpeed, percent);

            // ladybrown to score preload onto alliance
            pidDrivetrain.set_heading(startRot);
            // [ladybrown scoring position]
            // [ladybrown resting position]

            // drive to goal node
            pidDrivetrain.turn_to_angle(goalNodeHeading);
            pidDrivetrain.drive_distance(-1 * goalNodeDist);

            // drive to goal and clamp
            pidDrivetrain.turn_to_angle(30);
            pidDrivetrain.drive_max_voltage(6);
            pidDrivetrain.drive_distance(-1 * nodeToGoal);
            mobileGoalLock.set(true);

            // turn and drive forwards for ring 2
            pidDrivetrain.drive_max_voltage = 12;
            intakeMotors.spin(forward);
            pidDrivetrain.turn_to_angle(-90);
            pidDrivetrain.drive_distance(24 + 3.5);
            wait(1500, msec);

            // getting ring 3
            pidDrivetrain.turn_to_angle(180);
            float clusterTrim1 = 7.5;
            pidDrivetrain.drive_distance(24 - clusterTrim1);
            pidDrivetrain.drive_distance(-1 * (12 - clusterTrim1));

            // getting ring 4
            pidDrivetrain.turn_to_angle(-30);
            float clusterTrim2 = 5;
            pidDrivetrain.drive_distance(13.9 - clusterTrim2);
            pidDrivetrain.drive_distance(-1 * (13.9 - clusterTrim2));
            intakeMotors.stop();
        }
        case Autons::Route::soloAWP:
        {
            // starting on the right
            // gets 3 rings onto a mobile goal + 1 alliance
            // SOLO AWP :D

            BlueAlliance::run(Autons::Route::ClusterStart);

            // ladder touch
            // [ladybrown scoring position]
            pidDrivetrain.drive_distance(36);

            break;
        }
        case Autons::Route::fourRing_Corner:
        {
            // starting on the right
            // gets 3 rings onto a mobile goal + alliance
            // nearer to positive corner

            BlueeAlliance::run(Autons::Route::ClusterStart);

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