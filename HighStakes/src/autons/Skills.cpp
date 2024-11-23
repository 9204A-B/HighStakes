#include "vex.h"
using namespace vex;

namespace Autons
{
    void Skills::run()
    {
        // starting on the far left
        // should immediately clamp the left mobile goal
        // this doesn't do wall or alliance stakes yet

        // clamp mobile goal and drop pre-load
        pidDrivetrain.drive_distance(-13.9);
        mobileGoalLock.set(true);
        intakeMotors.setVelocity(intakeSpeed, percent);
        intakeMotors.spin(forward);
        wait(500);

        // intaking first 2 rings
        pidDrivetrain.right_swing_to_angle(180 - 30);
        pidDrivetrain.drive_distance(24);
        pidDrivetrain.left_swing_to_angle(90);
        pidDrivetrain.drive_distance(24);

        // intaking near-left corner rings
        pidDrivetrain.left_swing_to_angle(180 - 63.4); // 63.4 = arctan(24 / 12)
        pidDrivetrain.drive_distance(26.8);            // 26.8 = sqrt(12^2 + 24^2)
        pidDrivetrain.left_swing_to_angle(90 + 26.6);  // 26.6 = 90 - 63.4
        pidDrivetrain.drive_distance(12);
        pidDrivetrain.right_swing_to_angle(90);
        pidDrivetrain.drive_distance(12);

        // dropping goal 1 into the corner
        pidDrivetrain.left_swing_to_angle(90 + 26.6);
        intakeMotors.stop();
        float goalDropDist = 26.8 - (10 + 7.5); // tweak this until the goal is in the corner
        pidDriveTrain.drive_distance(-1 * goalDropDist);
        mobileGoalLock.set(false);

        // drive towards goal 2 and clamp
        pidDriveTrain.drive_distance(goalDropDist + 26.8); // this should get the robot to the original position of goal 1
        pidDrivetrain.left_swing_to_angle(180 - 26.6);
        pidDrivetrain.drive_distance(-48);
        mobileGoalLock.set(true);

        // intake 3 rings in front of near-right corner
        pidDrivetrain.right_swing_to_angle(90);
        intakeMotors.spin(forward);
        pidDrivetrain.drive_distance(24);
        pidDrivetrain.right_swing_to_angle(56.3);             // 56.3 = arctan(36 / 24)
        pidDrivetrain.drive_distance(43.3);                   // 43.3 = sqrt(24^2 + 36^2)
        pidDrivetrain.right_swing_to_angle(33.7 + 90 + 26.6); // 33.7 (parallel to double line), 90 (perpendicular), 26.6 (pointing to the ring)
        pidDrivetrain.drive_distance(26.8);                   // 26.8 = sqrt(12^2 + 24^2)

        // intake near-right corner rings
        pidDrivetrain.left_swing_to_angle(26.6);
        pidDrivetrain.drive_distance(36);
        pidDrivetrain.left_swing_to_angle(45);
        pidDrivetrain.drive_distance(17);

        // dropping goal 2 into the corner
        pidDrivetrain.left_swing_to_angle(45 + 26.6);
        intakeMotors.stop();
        pidDrivetrain.drive_distance(-1 * goalDropDist);
        mobileGoalLock.set(false);

        // drive towards goal 3 and clamp
        pidDrivetrain.drive_distance(goalDropDist);
        pidDrivetrain.right_swing_to_angle(26.6 - 20.6); // 20.6 = arctan(36 / 96). Heading before this turn is 26.6.
        pidDrivetrain.drive_distance(102.5);
        pidDrivetrain.right_swing_to_angle(20.6 + 90);
        pidDrivetrain.drive_distance(-24);
        mobileGoalLock.set(true);

        // intaking 5 spread out rings
        // (will need to add code that stops the intake when driving under the ladder)
        pidDrivetrain.right_swing_to_angle(45);
        pidDrivetrain.drive_distance(33.9);
        pidDrivetrain.right_swing_to_angle(90);
        pidDrivetrain.drive_distance(33.9);
        pidDrivetrain.left_swing_to_angle(90);
        pidDrivetrain.drive_distance(33.9);
        pidDrivetrain.left_swing_to_angle(45);
        pidDrivetrain.drive_distance(24);
        pidDrivetrain.right_swing_to_angle(63.4);
        pidDrivetrain.drive_distance(26.8);
        pidDrivetrain.left_swing_to_angle(26.8 + 90);
        pidDrivetrain.drive_distance(48);

        // dropping goal 3
        pidDrivetrain.left_swing_to_angle(180 - 26.6);
        pidDrivetrain.drive_distance(-1 * goalDropDist);
        mobileGoalLock.set(false);

        // grabbing goal 4
        pidDrivetrain.drive_distance(goalDropDist + 26.8);
        pidDrivetrain.right_swing_to_angle(26.6 + 69.4);
        pidDrivetrain.drive_distance(-102.5);
        mobileGoalLock.set(true);

        // dropping goal 4 into corner 4
        pidDrivetrain.right_swing_to_angle(76 - 69.4);
        float goal4DropDist = 49.5 - 1;
        pidDrivetrain.drive_distance(-1 * goal4DropDist); // tweak this until the goal is in the corner properly
        mobileGoalLock.set(false);
        pidDrivetrain.drive_distance(goal4DropDist);
    }
}