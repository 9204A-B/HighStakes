#include "vex.h"
#include <math.h>
using namespace vex;

namespace Autons
{
    void Skills::run()
    {
        default_constants();

        // start in a position where running the intake scores onto the alliance stake

        pidDrivetrain.drive_max_voltage = 12;
        pidDrivetrain.turn_max_voltage = 12;
        intakeMotors.setVelocity(intakeSpeed, percent);

        // score alliance stake and align for first goal
        pidDrivetrain.set_heading(180);
        intakeMotors.spin(forward);
        wait(750, msec);
        intakeMotors.stop();
        intakeMotors.spin(reverse);
        wait(500, msec);
        intakeMotors.stop();
        pidDrivetrain.drive_distance(13.25);

        // clamp goal 1
        pidDrivetrain.turn_to_angle(-90);
        // check here for proper alignment :)

        pidDrivetrain.drive_max_voltage = 6;
        pidDrivetrain.drive_distance(-24);
        mobileGoalLock.set(true);
        wait(500, msec);

        // 2 rings further away on the left
        pidDrivetrain.drive_max_voltage = 12;
        pidDrivetrain.turn_to_angle(180);
        intakeMotors.spin(forward);
        pidDrivetrain.drive_distance(24);
        pidDrivetrain.turn_to_angle(90);
        pidDrivetrain.drive_distance(24);

        // 2 rings on left corner
        pidDrivetrain.turn_to_angle(0);
        pidDrivetrain.drive_distance(24);

        pidDrivetrain.drive_max_voltage = 8;
        pidDrivetrain.turn_max_voltage = 8;

        pidDrivetrain.drive_distance(12);
        wait(500, msec);
        pidDrivetrain.drive_distance(-12);
        pidDrivetrain.turn_to_angle(180 + 45);
        intakeMotors.stop();

        // // drop first goal
        // pidDrivetrain.drive_max_voltage = 12;
        // pidDrivetrain.turn_max_voltage = 12;

        // float goalDropDist1 = 33.9 - 7.5 - 10 - 3; // 7.5 is half the length of the robot, 10 is the length of the goal. tweak more if needed.
        // pidDrivetrain.drive_distance(-1 * goalDropDist1);
        // mobileGoalLock.set(false);
        // wait(250, msec);
        // pidDrivetrain.drive_distance(goalDropDist1);

        // // clamp second goal
        // pidDrivetrain.turn_to_angle(90);
        // pidDrivetrain.drive_distance(-60);

        // pidDrivetrain.drive_max_voltage = 6; // dropping the speed so that the goal doesn't get knocked away

        // pidDrivetrain.drive_distance(-12);
        // mobileGoalLock.set(true);

        // // 2 rings further away on the right
        // pidDrivetrain.drive_max_voltage = 12;

        // pidDrivetrain.turn_to_angle(180);
        // pidDrivetrain.drive_distance(24);
        // pidDrivetrain.turn_to_angle(-90);
        // pidDrivetrain.drive_distance(24);

        // // 2 rings on right corner
        // pidDrivetrain.turn_to_angle(0);
        // pidDrivetrain.drive_distance(24);

        // pidDrivetrain.drive_max_voltage = 8;
        // pidDrivetrain.turn_max_voltage = 8;

        // pidDrivetrain.drive_distance(12);
        // wait(500, msec);
        // pidDrivetrain.drive_distance(-12);
        // pidDrivetrain.turn_to_angle(180 + 45);
        // intakeMotors.stop();

        // // drop second goal
        // pidDrivetrain.drive_max_voltage = 12;
        // pidDrivetrain.turn_max_voltage = 12;

        // pidDrivetrain.turn_to_angle(90 + 45);
        // pidDrivetrain.drive_distance(-1 * goalDropDist1);
        // mobileGoalLock.set(false);
        // wait(250, msec);
        // pidDrivetrain.drive_distance(goalDropDist1);

        // // clamp third goal
        // pidDrivetrain.turn_to_angle(180 - 14);
        // pidDrivetrain.drive_distance(99);
        // pidDrivetrain.turn_to_angle(-90);

        // pidDrivetrain.drive_max_voltage = 6;

        // pidDrivetrain.drive_distance(-24);
        // mobileGoalLock.set(true);

        // // 2 rings before going to corner
        // pidDrivetrain.drive_max_voltage = 12;

        // pidDrivetrain.turn_to_angle(-45);
        // intakeMotors.spin(forward);
        // pidDrivetrain.drive_distance(33.9);
        // pidDrivetrain.drive_distance(33.9);
        // pidDrivetrain.turn_to_angle(45);
        // pidDrivetrain.drive_distance(33.9);
        // pidDrivetrain.turn_to_angle(90);
        // pidDrivetrain.drive_distance(24);

        // // 2 in corner
        // pidDrivetrain.turn_to_angle(180);
        // pidDrivetrain.drive_distance(24);
        // wait(500, msec);
        // pidDrivetrain.turn_to_angle(90);
        // pidDrivetrain.drive_distance(12);
        // pidDrivetrain.drive_distance(-12);

        // // drop third goal
        // pidDrivetrain.turn_to_angle(-45);
        // pidDrivetrain.drive_distance(-1 * goalDropDist1);
        // mobileGoalLock.set(false);
        // wait(250, msec);
        // pidDrivetrain.drive_distance(goalDropDist1);

        // // clamp final goal
        // pidDrivetrain.drive_distance(48 + (24 - 6.9));
        // pidDrivetrain.turn_to_angle(30);

        // pidDrivetrain.drive_max_voltage = 6;

        // pidDrivetrain.drive_distance(-13.9);
        // mobileGoalLock.set(true);

        // // drop final goal in corner
        // pidDrivetrain.drive_max_voltage = 12;

        // pidDrivetrain.turn_to_angle(90);
        // pidDrivetrain.drive_distance(-1 * (24 - 10)); // tweak this value so that the robot isnt completely shoved into the wall
        // mobileGoalLock.set(false);
        // wait(250, msec);
        // pidDrivetrain.drive_distance(24);
    }
}