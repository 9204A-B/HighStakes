#include "vex.h"
#include <math.h>
using namespace vex;

namespace Autons
{
    void RedAlliance::run(Autons::Route route)
    {
        // in JAR template, positive angles -> clockwise, negative -> counter-clockwise
        // if we want the robot to start with the clamp already pointed at the goal, **ADD** 30 from all .turn_to_angle() functions.
        // i might just do that after changing out all the turning functions, its a pretty easy fix.

        // these are values for grabbing the two rings on the auton line.
        float clusterTarget = 3.2; // this is currently aimed right at the center of the ring. increase to make it further from where the two rings touch.
        // 3.5 aims for dead-center on the ring. tweak this until the other ring doesn't get knocked too badly

        float clusterAngleRad = atan(clusterTarget / 24);
        float clusterAngle = clusterAngleRad * (360 / 3.141); // this is in degrees now

        float clusterDist = (clusterTarget / sin(clusterAngleRad)) - 11.5; // tweak this until the robot doesn't go over the auton line
        // you should only be tweaking clusterTarget and clusterDist
        default_constants();
        switch (route)
        {
        case Autons::Route::test:
        {
            // red alliance test slot
        }
        case Autons::Route::soloAWP:
        {
            // starting on the left
            // gets 4 rings onto a mobile goal
            // ends in positive corner

            pidDrivetrain.drive_max_voltage = 12;
            pidDrivetrain.turn_max_voltage = 9;

            // ladybrown to score preload onto alliance
            pidDrivetrain.set_heading(-30);
            // [ladybrown scoring position]

            // clamp mobile goal
            pidDrivetrain.turn_to_angle(0);
            pidDrivetrain.drive_distance(36 - 20.78);
            pidDrivetrain.turn_to_angle(30);
            // [ladybrown resting position]
            pidDrivetrain.drive_distance(-24);
            mobileGoalLock.set(true);

            // turn and drive forwards for ring 2
            pidDrivetrain.turn_to_angle(90);
            pidDrivetrain.drive_distance(24 + 3.5);
            // waitUntil(pidDrivetrain.is_settled());
            wait(1500, msec);

            // getting ring 3
            pidDrivetrain.turn_to_angle(180);
            float clusterTrim1 = 7.5;
            pidDrivetrain.drive_distance(24 - clusterTrim1);
            pidDrivetrain.drive_distance(-1 * (12 - clusterTrim1));

            // getting ring 4
            pidDrivetrain.turn_to_angle(30);
            float clusterTrim2 = 5;
            pidDrivetrain.drive_distance(13.89 - clusterTrim2);
            pidDrivetrain.drive_distance(-1 * (13.89 - clusterTrim2));
            intakeMotors.stop();

            // ladder touch
            // [ladybrown scoring position]
            pidDrivetrain.drive_distance(36);

            break;
        }
        case Autons::Route::fourRingMogo_Ladder:
        {
            // starting on the left
            // gets 4 rings onto a mobile goal
            // ends touching ladder

            // back into the mobile goal and drop match load ring
            pidDrivetrain.turn_to_angle(30);
            pidDrivetrain.drive_distance(-41.6 + 0); // tweak this depending on where the robot starts on the line
            mobileGoalLock.set(true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500, msec);

            // turn and drive forwards for ring 2
            pidDrivetrain.turn_to_angle(90);
            pidDrivetrain.drive_distance(24);
            wait(500, msec);

            // update: i've decided to just turn and drive towards the ring from the previous ring's position.
            // it's painfully slow, but that's the best i can do without access to the robot

            // turn and drive into ring 3 on the line
            pidDrivetrain.turn_to_angle(180 + clusterAngle);
            pidDrivetrain.drive_distance(clusterDist);
            wait(500, msec);

            // turn and drive into ring 4
            pidDrivetrain.drive_distance(-1 * clusterDist);
            pidDrivetrain.turn_to_angle(180 - clusterAngle);
            pidDrivetrain.drive_distance(clusterDist);
            wait(500, msec);
            pidDrivetrain.drive_distance(-1 * clusterDist);
            intakeMotors.stop();

            // turning and driving into the ladder
            pidDrivetrain.turn_to_angle(270);
            pidDrivetrain.drive_distance(48 - 5); // tweak until the robot doesn't break itself on the ladder

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
        case Autons::Route::mogoSide_GoalRush_Corner:
        {
            // starting between the nearer and further mobile goal
            // scores 1 ring on each goal
            // finishes in the corner

            // goal rush
            pidDrivetrain.drive_distance(-1 * (36 + (24 - 20.8))); // 20.8 = 12 / tan(30)
            pidDrivetrain.turn_to_angle(30);
            float goalGrabDist = 24 - 0; // tweak this until the robot doesn't go over the line
            pidDrivetrain.drive_distance(-1 * goalGrabDist);
            mobileGoalLock.set(true);
            pidDrivetrain.drive_distance(goalGrabDist);

            // scoring preload onto goal rushed goal
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500, msec);

            // putting away the goal rushed goal
            pidDrivetrain.turn_to_angle(0);
            pidDrivetrain.drive_distance(-1 * ((24 - 20.8) + 24));
            intakeMotors.stop();
            mobileGoalLock.set(false);

            // clamping the second goal
            pidDrivetrain.drive_distance(24);
            pidDrivetrain.turn_to_angle(270);
            pidDrivetrain.drive_distance(-12);
            mobileGoalLock.set(true);

            // intaking a second ring and driving into the corner
            intakeMotors.spin(forward);
            pidDrivetrain.drive_distance(36);
            pidDrivetrain.turn_to_angle(0);
            pidDrivetrain.drive_distance(24);

            break;
        }
        case Autons::Route::mogoSide_GoalRush_Ladder:
        {
            // starting between the nearer and further mobile goal
            // scores 1 ring on each goal
            // finishes touching the ladder

            // goal rush
            pidDrivetrain.drive_distance(-1 * (36 + (24 - 20.8))); // 20.8 = 12 / tan(30)
            pidDrivetrain.turn_to_angle(30);
            float goalGrabDist = 24 - 0; // tweak this until the robot doesn't go over the line
            pidDrivetrain.drive_distance(-1 * goalGrabDist);
            mobileGoalLock.set(true);
            pidDrivetrain.drive_distance(goalGrabDist);

            // scoring preload onto goal rushed goal
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500, msec);

            // putting away the goal rushed goal
            pidDrivetrain.turn_to_angle(0);
            pidDrivetrain.drive_distance(-1 * ((24 - 20.8) + 24));
            intakeMotors.stop();
            mobileGoalLock.set(false);

            // clamping the second goal
            pidDrivetrain.drive_distance(24);
            pidDrivetrain.turn_to_angle(270);
            pidDrivetrain.drive_distance(-12);
            mobileGoalLock.set(true);

            // intaking a second ring and driving into the corner
            intakeMotors.spin(forward);
            pidDrivetrain.drive_distance(24);
            pidDrivetrain.turn_to_angle(90);
            pidDrivetrain.drive_distance(48 - 5); // tweak this until the robot just touches the ladder

            break;
        }
        }
    }
}