#include "vex.h"
#include <math.h>
using namespace vex;

namespace Autons
{
    void Skills::run()
    {
        // start in a position where running the intake scores onto the alliance stake

        pidDrivetrain.drive_max_voltage = 12;
        pidDrivetrain.turn_max_voltage = 12;
        intakeMotors.setVelocity(intakeSpeed, percent);

        // score alliance stake and align for first goal
        pidDrivetrain.set_heading(180);
        intakeMotors.spin(forward);
        wait(1000, msec);

        intakeMotors.spin(reverse);
        wait(500, msec);
        intakeMotors.stop();
        pidDrivetrain.drive_distance(12); // tweak this number until the robot is perfectly centered on the start line

        // clamp goal 1
        pidDrivetrain.turn_to_angle(-90);
        pidDrivetrain.drive_max_voltage = 6;
        pidDrivetrain.drive_distance(-24);
        mobileGoalLock.set(true);

        // 3 rings further away on the left
        pidDrivetrain.drive_max_voltage = 12;
        pidDrivetrain.turn_to_angle(180);
        intakeMotors.spin(forward);
        pidDrivetrain.drive_distance(24);
        pidDrivetrain.turn_to_angle(90);
        pidDrivetrain.drive_distance(24);
        pidDrivetrain.turn_to_angle(90 + 26.6);
        pidDrivetrain.drive_distance(26.8);

        // 3 rings on left corner
        pidDrivetrain.turn_to_angle(0);
        pidDrivetrain.drive_distance(48);

        pidDrivetrain.drive_max_voltage = 8;
        pidDrivetrain.turn_max_voltage = 8;

        pidDrivetrain.turn_to_angle(-45);
        pidDrivetrain.drive_distance(17);
        pidDrivetrain.turn_to_angle(180);
        pidDrivetrain.drive_distance(12);
        wait(1000, msec);
        intakeMotors.stop();

        // drop first goal
        pidDrivetrain.drive_max_voltage = 12;
        pidDrivetrain.turn_max_voltage = 12;

        float goalDropDist1 = (33.9 - 7.5 - 10 - 3); // 7.5 is half the lenth of the robot, 10 is the length of the goal. tweak more if needed.
        pidDrivetrain.turn_to_angle(180 + 45);
        pidDrivetrain.drive_distance(-1 * goalDropDist1);
        mobileGoalLock.set(false);
        wait(500);
        pidDrivetrain.drive_distance(goalDropDist1);

        // clamp second goal
        pidDrivetrain.turn_to_angle(90);
        pidDrivetrain.drive_distance(-60);

        pidDrivetrain.drive_max_voltage = 6; // dropping the speed so that the goal doesn't get knocked away

        pidDrivetrain.drive_distance(-12);
        mobileGoalLock.set(true);

        // 3 rings further away on the right
        pidDrivetrain.drive_max_voltage = 12;

        pidDrivetrain.turn_to_angle(180);
        pidDrivetrain.drive_distance(24);
        pidDrivetrain.turn_to_angle(-90);
        pidDrivetrain.drive_distance(24);
        pidDrivetrain.turn_to_angle(180 + 26.6);
        pidDrivetrain.drive_distance(26.8);

        // 3 rings on right corner
        pidDrivetrain.turn_to_angle(0);
        pidDrivetrain.drive_distance(48);

        pidDrivetrain.drive_max_voltage = 8;
        pidDrivetrain.turn_max_voltage = 8;

        pidDrivetrain.turn_to_angle(45);
        pidDrivetrain.drive_distance(17);
        pidDrivetrain.turn_to_angle(180);
        pidDrivetrain.drive_distance(12);
        wait(1000, msec);
        intakeMotors.stop();

        // drop second goal
        pidDrivetrain.drive_max_voltage = 12;
        pidDrivetrain.turn_max_voltage = 12;

        pidDrivetrain.turn_to_angle(90 + 45);
        pidDrivetrain.drive_distance(-1 * goalDropDist1);
        mobileGoalLock.set(false);
        wait(500);
        pidDrivetrain.drive_distance(goalDropDist1);
    }
}