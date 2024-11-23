#include "vex.h";
using namespace ves;

namespace Autons;
{
    void RedAlliance::run(Autons::Route route)
    {
        default_constants();
        switch (route)
        {
        case Autons::Route::4ringmogo_corner:
        {
            // starting on the left
            // gets 4 rings onto a mobile goal
            // ends in positive corner

            // back into the mobile goal and drop match load ring
            pidDrivetrain.drive_distance(-(24 * sqrt(2)));
            mobileGoalLock.set(true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500);

            // turn and drive forwards for ring 2
            pidDrivetrain.left_swing_to_angle(45);
            pidDrivetrain.drive_distance(24 + (7 / 5));
            wait(500);

            // turn and drive into ring 3 on the line
            pidDrivetrain.left_swing_to_angle(90);
            pidDrivetrain.drive_distance(24 - (15 / 2)); // tweak this until the robot doesn't go over the auton line
            wait(500);

            // turn and drive into ring 4
            pidDrivetrain.drive_distance(-12);
            pidDrivetrain.right_swing_to_angle(30);
            pidDrivetrain.drive_distance(14);
            wait(500);
            pidDrivetrain.drive_distance(-14);
            intakeMotors.stop();

            // turning and driving into the corner
            pidDrivetrain.left_swing_to_angle(180 - 64);
            pidDrivetrain.drive_distance(-130);

            break;
        }
        case Autons::Route::4ringmogo_ladder:
        {
            // starting on the left
            // gets 4 rings onto a mobile goal
            // ends touching ladder

            // back into the mobile goal and drop match load ring
            pidDrivetrain.drive_distance(-(24 * sqrt(2)));
            mobileGoalLock.set(true);
            intakeMotors.setVelocity(intakeSpeed, percent);
            intakeMotors.spin(forward);
            wait(500);

            // turn and drive forwards for ring 2
            pidDrivetrain.left_swing_to_angle(45);
            pidDrivetrain.drive_distance(24 + (7 / 5));
            wait(500);

            // turn and drive into ring 3 on the line
            pidDrivetrain.left_swing_to_angle(90);
            pidDrivetrain.drive_distance(24 - (15 / 2)); // tweak this until the robot doesn't go over the auton line
            wait(500);

            // turn and drive into ring 4
            pidDrivetrain.drive_distance(-12);
            pidDrivetrain.right_swing_to_angle(30);
            pidDrivetrain.drive_distance(14);
            wait(500);
            pidDrivetrain.drive_distance(-14);
            intakeMotors.stop();

            // turn towards ladder and touch
            pidDrivetrain.left_swing_to_angle(180 - 77);
            pidDrivetrain.drive_distance(53);

            break;
        }
        }
    }
}