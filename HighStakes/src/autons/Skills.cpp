#include "vex.h"
#include <math.h>
using namespace vex;

// these are values for dodging the ladder towards the end.
float dodgeAngle = 15.0; // tweak this value until the robot misses the ladder

float dodgeAngleRad = dodgeAngle * (3.141 / 360);
float dodgeDriveDistance = 24 / cos(dodgeAngleRad);

namespace Autons
{
    void Skills::run()
    {
        // starting on the left close to the alliance stake
        // should immediately clamp the left mobile goal
        // this doesn't do wall or alliance stakes yet

        // clamp mobile goal and drop pre-load
        pidDrivetrain.turn_to_angle(330);
        pidDrivetrain.drive_distance(-13.9);
        mobileGoalLock.set(true);
        intakeMotors.setVelocity(intakeSpeed, percent);
        intakeMotors.spin(forward);
        wait(500, msec);

        // intaking first 2 rings
        pidDrivetrain.turn_to_angle(180);
        pidDrivetrain.drive_distance(24);
        pidDrivetrain.turn_to_angle(90);
        pidDrivetrain.drive_distance(24);

        // intaking near-left corner rings
        pidDrivetrain.turn_to_angle(26.6);  // 26.6 = arctan(12 / 24)
        pidDrivetrain.drive_distance(26.8); // 26.8 = sqrt(12^2 + 24^2)
        pidDrivetrain.turn_to_angle(270);
        pidDrivetrain.drive_distance(12);
        pidDrivetrain.turn_to_angle(0);
        pidDrivetrain.drive_distance(12);

        // dropping goal 1 into the corner
        pidDrivetrain.turn_to_angle(180 + 63.4); // 63.4 = arctan(24 / 12)
        intakeMotors.stop();
        float goalDropDist = 26.8 - 15; // tweak this until the goal is in the corner properly
        pidDrivetrain.drive_distance(-1 * goalDropDist);
        mobileGoalLock.set(false);

        // drive towards goal 2 and clamp
        pidDrivetrain.drive_distance(goalDropDist + 26.8); // this should get the robot to the original position of goal 1
        pidDrivetrain.turn_to_angle(90);
        pidDrivetrain.drive_distance(-48);
        mobileGoalLock.set(true);

        // intake 3 rings in front of near-right corner
        pidDrivetrain.turn_to_angle(180);
        intakeMotors.spin(forward);
        pidDrivetrain.drive_distance(24);
        pidDrivetrain.turn_to_angle(180 + 56.3); // 56.3 = arctan(36 / 24)
        pidDrivetrain.drive_distance(43.3);      // 43.3 = sqrt(24^2 + 36^2)
        pidDrivetrain.turn_to_angle(26.6);       // 26.6 = arctan(12 / 24)
        pidDrivetrain.drive_distance(26.8);      // 26.8 = sqrt(12^2 + 24^2)

        // intake near-right corner rings
        pidDrivetrain.turn_to_angle(0);
        pidDrivetrain.drive_distance(36);
        pidDrivetrain.turn_to_angle(180 + 45);
        pidDrivetrain.drive_distance(17);

        // dropping goal 2 into the corner
        pidDrivetrain.turn_to_angle(180 - 26.6);
        intakeMotors.stop();
        pidDrivetrain.drive_distance(-1 * goalDropDist);
        mobileGoalLock.set(false);

        // drive towards goal 3 and clamp
        pidDrivetrain.drive_distance(goalDropDist);
        pidDrivetrain.turn_to_angle(180 - 20.6); // 20.6 = arctan(36 / 96).
        pidDrivetrain.drive_distance(102.5);     // 102.5 = sqrt(36^2 + 96^2)
        pidDrivetrain.turn_to_angle(270);
        pidDrivetrain.drive_distance(-24);
        mobileGoalLock.set(true);
        intakeMotors.spin(forward);

        // intaking 2 rings next to ladder and dodging it.
        pidDrivetrain.turn_to_angle(360 - 45);
        pidDrivetrain.drive_distance(33.9);
        pidDrivetrain.turn_to_angle(90 + dodgeAngle);
        pidDrivetrain.drive_distance(dodgeDriveDistance);
        pidDrivetrain.turn_to_angle(90 - dodgeAngle);
        pidDrivetrain.drive_distance(dodgeDriveDistance);

        // intaking 2 rings on the top left corner + 2 in front of it
        pidDrivetrain.turn_to_angle(90 + 45);
        pidDrivetrain.drive_distance(33.9);
        pidDrivetrain.turn_to_angle(0);
        pidDrivetrain.drive_distance(24);
        pidDrivetrain.turn_to_angle(26.6); // 26.6 = arctan(12 / 24)
        pidDrivetrain.drive_distance(26.8);
        pidDrivetrain.turn_to_angle(180);
        pidDrivetrain.drive_distance(24);

        // dropping goal 3
        pidDrivetrain.turn_to_angle(180 - 26.6);
        intakeMotors.stop();
        pidDrivetrain.drive_distance(-1 * goalDropDist);
        mobileGoalLock.set(false);

        // grabbing goal 4
        pidDrivetrain.drive_distance(goalDropDist + 26.8);
        pidDrivetrain.turn_to_angle(63.4);   // 63.4 = arctan(72 / 36)
        pidDrivetrain.drive_distance(-80.5); // 80.5 = sqrt(72^2 + 36^2)
        mobileGoalLock.set(true);

        // dropping goal 4 into corner 4
        pidDrivetrain.turn_to_angle(76); // 76 = arctan(48 / 12)
        float goal4DropDist = 49.5 - 10; // tweak this until the goal is in the corner properly
        pidDrivetrain.drive_distance(-1 * goal4DropDist);
        mobileGoalLock.set(false);
        pidDrivetrain.drive_distance(goal4DropDist);

        // if nothing goes wrong, this should get us a 44 point programming skills run :D
    }
}