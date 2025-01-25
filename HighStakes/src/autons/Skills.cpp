#include "vex.h"
#include <math.h>
using namespace vex;

namespace Autons
{
    void Skills::run()
    {
        default_constants();

        // start in a position where running the intake scores onto the alliance stake

        float maxSpeed = 10;
        float medSpeed = 8;
        float lowSpeed = 6;

        pidDrivetrain.drive_max_voltage = medSpeed;
        pidDrivetrain.turn_max_voltage = medSpeed;
        intakeMotors.setVelocity(intakeSpeed, percent);
        pidDrivetrain.set_heading(180);

        // score alliance stake and align for first goal
        antiJamEnable = false;
        intakeMotors.spin(forward);
        wait(750, msec);
        intakeMotors.stop();
        intakeMotors.spin(reverse);
        wait(500, msec);
        intakeMotors.stop();
        pidDrivetrain.drive_distance(12.5);
        antiJamEnable = true;

        // clamp goal 1
        pidDrivetrain.turn_to_angle(-90);
        // check here for proper alignment :)

        pidDrivetrain.drive_max_voltage = lowSpeed;
        pidDrivetrain.drive_distance(-24);
        mobileGoalLock.set(true);
        wait(500, msec);

        // 2 rings further away on the left
        pidDrivetrain.drive_max_voltage = medSpeed;
        pidDrivetrain.turn_to_angle(180);
        intakeMotors.spin(forward);
        pidDrivetrain.drive_distance(18);
        pidDrivetrain.turn_to_angle(90);
        pidDrivetrain.drive_distance(24);

        // 2 rings on left corner
        pidDrivetrain.drive_max_voltage = lowSpeed;

        pidDrivetrain.turn_to_angle(0);
        pidDrivetrain.drive_distance(24);

        wait(500, msec);
        pidDrivetrain.turn_to_angle(180 + 45);
        intakeMotors.stop();

        // // drop first goal
        pidDrivetrain.drive_max_voltage = medSpeed;
        pidDrivetrain.turn_max_voltage = medSpeed;

        float goalDropDist1 = 33.9 - 7.5 - 10 - 3; // 7.5 is half the length of the robot, 10 is the length of the goal. tweak more if needed.
        pidDrivetrain.drive_distance(-1 * goalDropDist1);
        mobileGoalLock.set(false);
        wait(100, msec);
        pidDrivetrain.drive_distance(goalDropDist1);

        // // clamp second goal
        pidDrivetrain.turn_to_angle(90);
        pidDrivetrain.drive_distance(-60);
        wait(250, msec);
        mobileGoalLock.set(true);

        // 2 rings further away on the right
        pidDrivetrain.drive_max_voltage = medSpeed;

        pidDrivetrain.turn_to_angle(180);
        pidDrivetrain.drive_distance(24);
        pidDrivetrain.turn_to_angle(-90);
        pidDrivetrain.drive_distance(18);

        // 2 rings on right corner
        pidDrivetrain.drive_max_voltage = lowSpeed;

        pidDrivetrain.turn_to_angle(0);
        pidDrivetrain.drive_distance(24);

        wait(500, msec);
        pidDrivetrain.turn_to_angle(180 + 45);
        intakeMotors.stop();

        // drop second goal
        pidDrivetrain.drive_max_voltage = medSpeed;
        pidDrivetrain.turn_max_voltage = medSpeed;

        pidDrivetrain.turn_to_angle(90 + 45);
        pidDrivetrain.drive_distance(-1 * goalDropDist1);
        mobileGoalLock.set(false);
        wait(250, msec);
        pidDrivetrain.drive_distance(goalDropDist1);

        // drive to right blue goal
        pidDrivetrain.turn_to_angle(12.5);
        pidDrivetrain.drive_distance(110.6 + 5); // robot should be as close to the wall as possible WHILE STILL BEING ABLE TO TURN
        mobileGoalLock.set(true);
        wait(250, msec);

        // shove right blue goal into corner
        pidDrivetrain.turn_to_angle(90);
        float goalDropDist2 = 48 - 7.5 - 10 - 0;
        pidDrivetrain.drive_max_voltage = maxSpeed;
        pidDrivetrain.drive_distance(-1 * goalDropDist2);
        mobileGoalLock.set(false);
        wait(250, msec);

        // shove left blue goal into corner
        pidDrivetrain.drive_timeout = 5000;
        pidDrivetrain.drive_distance(goalDropDist2 + 48 + goalDropDist2);
        pidDrivetrain.drive_timeout = 3000;
        pidDrivetrain.drive_distance(-48);
    }
}