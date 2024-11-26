#include "vex.h";
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

// this is literally just the red alliance auton except its 180 - (the angle)

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
            pidDrivetrain.turn_to_angle(180 - 30);
            pidDrivetrain.drive_distance(-41.6);
            mobileGoalLock.set(true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500);

            // turn and drive forwards for ring 2
            pidDrivetrain.turn_to_angle(180 - 90);
            pidDrivetrain.drive_distance(24);
            wait(500);

            // update: i've decided to just turn and drive towards the ring from the previous ring's position.
            // it's painfully slow, but that's the best i can do without access to the robot

            // turn and drive into ring 3 on the line
            pidDrivetrain.turn_to_angle(180 - clusterAngle);
            pidDrivetrain.drive_distance(clusterDist); 
            wait(500);

            // turn and drive into ring 4
            pidDrivetrain.drive_distance(-1 * clusterDist);
            pidDrivetrain.turn_to_angle(180 + clusterAngle);
            pidDrivetrain.drive_distance(clusterDist);
            wait(500);
            pidDrivetrain.drive_distance(-1 * clusterDist);
            intakeMotors.stop();

            // turning and driving into the corner
            pidDrivetrain.turn_to_angle(180 - 270);
            pidDrivetrain.drive_distance(24) // tweak until the robot doesn't break itself on the ladder

            break;
        }
        case Autons::Route::fourRingMogo_Ladder:
        {
            // starting on the right
            // gets 4 rings onto a mobile goal
            // ends touching ladder

            // back into the mobile goal and drop match load ring
            pidDrivetrain.turn_to_angle(180 - 30);
            pidDrivetrain.drive_distance(-41.6);
            mobileGoalLock.set(true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500);

            // turn and drive forwards for ring 2
            pidDrivetrain.turn_to_angle(180 - 90);
            pidDrivetrain.drive_distance(24);
            wait(500);

            // update: i've decided to just turn and drive towards the ring from the previous ring's position.
            // it's painfully slow, but that's the best i can do without access to the robot

            // turn and drive into ring 3 on the line
            pidDrivetrain.turn_to_angle(180 - clusterAngle);
            pidDrivetrain.drive_distance(clusterDist); 
            wait(500);

            // turn and drive into ring 4
            pidDrivetrain.drive_distance(-1 * clusterDist);
            pidDrivetrain.turn_to_angle(180 + clusterAngle);
            pidDrivetrain.drive_distance(clusterDist);
            wait(500);
            pidDrivetrain.drive_distance(-1 * clusterDist);
            intakeMotors.stop();

            // turn and drive into the corner head-first
            pidDrivetrain.left_swing_to_angle(180 - 90);
            pidDrivetrain.drive_distance(70);
        }
        case Autons::Route::mogoSide_Ladder:
        {
            // starting on the right

            // back into the mobile goal and drop match load ring
            pidDrivetrain.drive_distance(-41.6);
            mobileGoalLock.set(true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500);

            // turn and drive forwards for ring 2
            pidDrivetrain.left_swing_to_angle(60);
            pidDrivetrain.drive_distance(36);
            wait(500);
            intakeMotors.stop();

            // turn and drive head-first into ladder
            pidDrivetrain.left_swing_to_angle(180);
            pidDrivetrain.drive_distance(60);
        }
        }
    }
}