#include "vex.h"
#include <math.h>
using namespace vex;

// in JAR template, positive angles -> clockwise, negative -> counter-clockwise
// if we want the robot to start with the clamp already pointed at the goal, subtract 30 from all .turn_to_angle() functions.
// i might just do that after changing out all the turning functions, its a pretty easy fix.

// these are values for grabbing the two rings on the auton line.
float clusterTarget = 3.5; // this is currently aimed right at the center of the ring. increase to make it further from where the two rings touch.
// 3.5 aims for dead-center on the ring. tweak this until the other ring doesn't get knocked too badly

float clusterAngleRad = atan(clusterTarget / 24); 
float clusterAngle = clusterAngleRad * (360 / 3.141); // this is in degrees, c++ trig uses radians

float clusterDist = (clusterTarget / sin(clusterAngleRad)) - 0; // tweak this until the robot doesn't go over the auton line
// you should only be tweaking clusterTarget and clusterDist

// this is literally just the red alliance auton except its 360 - (the angle)

namespace Autons
{
    void RedAlliance::run(Autons::Route route)
    {
        default_constants();
        switch (route)
        {
        case Autons::Route::fourRingMogo_Corner:
        {
            // starting on the right
            // gets 4 rings onto a mobile goal
            // ends in positive corner

            // back into the mobile goal and drop match load ring
            pidDrivetrain.turn_to_angle(360 - 30);
            pidDrivetrain.drive_distance(-41.6 + 0); // tweak this depending on where the robot starts on the line
            mobileGoalLock.set(true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500);

            // turn and drive forwards for ring 2
            pidDrivetrain.turn_to_angle(360 - 90);
            pidDrivetrain.drive_distance(24);
            wait(500);

            // update: i've decided to just turn and drive towards the ring from the previous ring's position.
            // it's painfully slow, but that's the best i can do without access to the robot

            // turn and drive into ring 3 on the line
            pidDrivetrain.turn_to_angle(360 - clusterAngle);
            pidDrivetrain.drive_distance(clusterDist); 
            wait(500);

            // turn and drive into ring 4
            pidDrivetrain.drive_distance(-1 * clusterDist);
            pidDrivetrain.turn_to_angle(360 + clusterAngle);
            pidDrivetrain.drive_distance(clusterDist);
            wait(500);
            pidDrivetrain.drive_distance(-1 * clusterDist);
            intakeMotors.stop();

            // turning and driving into the corner
            pidDrivetrain.turn_to_angle(360 - 291.8);
            pidDrivetrain.drive_distance(129.2 - 15); // tweak this until the robot doesn't completely ram into the corner
            // this auton ends with the intake facing the corner. can be easily changed.

            break;
        }
        case Autons::Route::fourRingMogo_Ladder:
        {
            // starting on the right
            // gets 4 rings onto a mobile goal
            // ends touching ladder

            // back into the mobile goal and drop match load ring
            pidDrivetrain.turn_to_angle(360 - 30);
            pidDrivetrain.drive_distance(-41.6 + 0); // tweak this depending on where the robot starts on the line
            mobileGoalLock.set(true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500);

            // turn and drive forwards for ring 2
            pidDrivetrain.turn_to_angle(360 - 90);
            pidDrivetrain.drive_distance(24);
            wait(500);

            // update: i've decided to just turn and drive towards the ring from the previous ring's position.
            // it's painfully slow, but that's the best i can do without access to the robot

            // turn and drive into ring 3 on the line
            pidDrivetrain.turn_to_angle(360 - clusterAngle);
            pidDrivetrain.drive_distance(clusterDist); 
            wait(500);

            // turn and drive into ring 4
            pidDrivetrain.drive_distance(-1 * clusterDist);
            pidDrivetrain.turn_to_angle(360 + clusterAngle);
            pidDrivetrain.drive_distance(clusterDist);
            wait(500);
            pidDrivetrain.drive_distance(-1 * clusterDist);
            intakeMotors.stop();

            // turn and drive into the ladder
            pidDrivetrain.turn_to_angle(360 - 270);
            pidDrivetrain.drive_distance(24 - 5) // tweak until the robot doesn't break itself on the ladder
        }
        case Autons::Route::mogoSide_Corner:
        {
            // starting on the right
            // gets two mobile goals
            // scores 2 rings
            // ends in the positive corner

            // back into mogo 1 and drop match load
            pidDrivetrain.turn_to_angle(360 - 330);
            pidDrivetrain.drive_distance(-41.6);
            mobileGoalLock.set(true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500);

            // putting the first mogo close to the corner
            pidDrivetrain.turn_to_angle(360 - 22.8);
            pidDrivetrain.drive_distance(-26 - 10); // tweak this until the robot can drop the goal and completely drive away
            intakeMotors.stop();
            mobileGoalLock.set(false);

            // grabbing the second mobile goal
            pidDrivetrain.drive_distance(10);
            pidDrivetrain.turn_to_angle(360 - 330);
            pidDrivetrain.drive_distance(-27.7); // this will have to be tweaked to make sure the bot doesn't go over the line
            mobileGoalLock.set(true);
            intakeMotors.spin(forward);

            // intaking the second ring
            pidDrivetrain.turn_to_angle(0); // same with this angle (see above)
            pidDrivetrain.drive_distance(24); // and possibly this
            wait(500);
            intakeMotors.stop();

            // driving into the corner
            pidDrivetrain.turn_to_angle(360 - 153.4);
            pidDrivetrain.drive_distance(53.7 - 5); // tweak until the robot stops completely ramming into the corner

            break;
        }
        case Autons::Route::mogoSide_Ladder:
        {
            // starting on the right
            // gets two mobile goals
            // scores 2 rings
            // ends touching the ladder

            // back into mogo 1 and drop match load
            pidDrivetrain.turn_to_angle(360 - 330);
            pidDrivetrain.drive_distance(-41.6);
            mobileGoalLock.set(true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500);

            // putting the first mogo close to the corner
            pidDrivetrain.turn_to_angle(360 - 22.8);
            pidDrivetrain.drive_distance(-26 - 10); // tweak this until the robot can drop the goal and completely drive away
            intakeMotors.stop();
            mobileGoalLock.set(false);

            // grabbing the second mobile goal
            pidDrivetrain.drive_distance(10);
            pidDrivetrain.turn_to_angle(360 - 330);
            pidDrivetrain.drive_distance(-27.7); // this will have to be tweaked to make sure the bot doesn't go over the line
            mobileGoalLock.set(true);
            intakeMotors.spin(forward);

            // intaking the second ring
            pidDrivetrain.turn_to_angle(0); // same with this angle (see above)
            pidDrivetrain.drive_distance(24); // and possibly this
            wait(500);
            intakeMotors.stop();

            // driving into the ladder
            pidDrivetrain.turn_to_angle(360 - 90);
            pidDrivetrain.drive_distance(48 - 5); // tweak until the robot doesn't break itself on the ladder

            break;
        }
        }
    }
}