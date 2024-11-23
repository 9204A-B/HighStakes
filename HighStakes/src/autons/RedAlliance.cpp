#include "vex.h";
using namespace vex;

namespace Autons
{
    void RedAlliance::run(Autons::Route route)
    {
        default_constants();
        switch (route)
        {
        case Autons::Route::fourRingMogo_Corner:
        {
            // starting on the left
            // gets 4 rings onto a mobile goal
            // ends in positive corner

            // back into the mobile goal and drop match load ring
            pidDrivetrain.drive_distance(-41.6);
            mobileGoalLock.set(true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500);

            // turn and drive forwards for ring 2
            pidDrivetrain.right_swing_to_angle(60);
            pidDrivetrain.drive_distance(24 + (7 / 5));
            wait(500);

            // turn and drive into ring 3 on the line
            pidDrivetrain.right_swing_to_angle(90);
            pidDrivetrain.drive_distance(24 - (15 / 2)); // tweak this until the robot doesn't go over the auton line
            wait(500);

            // turn and drive into ring 4
            pidDrivetrain.drive_distance(-12);
            pidDrivetrain.left_swing_to_angle(30);
            pidDrivetrain.drive_distance(14);
            wait(500);
            pidDrivetrain.drive_distance(-14);
            intakeMotors.stop();

            // turning and driving into the corner
            pidDrivetrain.right_swing_to_angle(180 - 64);
            pidDrivetrain.drive_distance(-130)

                break;
        }
        case Autons::Route::fourRingMogo_Ladder:
        {
            // starting on the left
            // gets 4 rings onto a mobile goal
            // ends touching ladder

            // back into the mobile goal and drop match load ring
            pidDrivetrain.drive_distance(-41.6); // this number can be made smaller if the robot doesn't start in the middle of the line
            mobileGoalLock.set(true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500);

            // turn and drive forwards for ring 2
            pidDrivetrain.right_swing_to_angle(60);
            pidDrivetrain.drive_distance(24 + (7 / 5));
            wait(500);

            // turn and drive into ring 3 on the line
            pidDrivetrain.right_swing_to_angle(90);
            pidDrivetrain.drive_distance(24 - (15 / 2)); // tweak this until the robot doesn't go over the auton line
            wait(500);

            // turn and drive into ring 4
            pidDrivetrain.drive_distance(-12);
            pidDrivetrain.left_swing_to_angle(30);
            pidDrivetrain.drive_distance(14);
            wait(500);
            pidDrivetrain.drive_distance(-14);
            intakeMotors.stop();

            // turn towards ladder and touch
            pidDrivetrain.swing_right_to_angle(180 - 77);
            pidDrivetrain.drive_distance(53);

            break;
        }
        case Autons::Route::mogoSide_Corner:
        {
            // starting on the left

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

            // turn and drive into the corner head-first
            pidDrivetrain.right_swing_to_angle(90);
            pidDrivetrain.drive_distance(70);
        }
        case Autons::Route::mogoSide_Ladder:
        {
            // starting on the left

            // back into the mobile goal and drop match load ring
            pidDrivetrain.drive_distance(-41.6);
            mobileGoalLock.set(true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500);

            // turn and drive forwards for ring 2
            pidDrivetrain.right_swing_to_angle(60);
            pidDrivetrain.drive_distance(36);
            wait(500);
            intakeMotors.stop();

            // turn and drive head-first into ladder
            pidDrivetrain.right_swing_to_angle(180);
            pidDrivetrain.drive_distance(60);
        }
        }
    }
}