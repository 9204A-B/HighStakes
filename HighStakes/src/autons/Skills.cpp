#include "vex.h"
#include <math.h>
using namespace vex;

namespace Autons
{
    void Skills::run()
    {
        default_constants();

        // start in a position where running the intake scores onto the alliance stake

        float maxSpeed = 12;
        float medSpeed = 8;
        float lowSpeed = 6;

        pidDrivetrain.turn_settle_error = 1;
        pidDrivetrain.drive_ki = .03;
        pidDrivetrain.turn_timeout = 3000;
        pidDrivetrain.drive_timeout = 2000;

        pidDrivetrain.drive_max_voltage = medSpeed;
        pidDrivetrain.turn_max_voltage = medSpeed;
        intakeMotors.setVelocity(intakeSpeed, percent);
        pidDrivetrain.set_heading(180);

        // score alliance stake and align for first goal
        antiJamEnable = false;
        intakeMotors.spin(forward);
        wait(300, msec);
        intakeMotors.stop();
        intakeMotors.spin(reverse);
        wait(300, msec);
        intakeMotors.stop();
        pidDrivetrain.drive_distance(12);
        antiJamEnable = true;

        // clamp goal 1
        pidDrivetrain.turn_to_angle(-90);
        // check here for proper alignment :)

        pidDrivetrain.drive_max_voltage = lowSpeed;
        pidDrivetrain.drive_distance(-22);
        mobileGoalLock.set(true);
        wait(500, msec);

        // 2 rings further away on the left
        pidDrivetrain.drive_max_voltage = medSpeed;
        pidDrivetrain.turn_to_angle(180);
        intakeMotors.spin(forward);
        pidDrivetrain.drive_distance(24);
        wait(750, msec);
        pidDrivetrain.turn_to_angle(90);
        pidDrivetrain.drive_distance(24);

        // 3 rings on left corner
        pidDrivetrain.drive_max_voltage = lowSpeed;

        pidDrivetrain.turn_to_angle(0);
        pidDrivetrain.drive_distance(21);
        pidDrivetrain.drive_distance(8);
        wait(500, msec);
        pidDrivetrain.drive_distance(-9);
        pidDrivetrain.turn_to_angle(90);
        pidDrivetrain.drive_distance(10);
        wait(500, msec);
        pidDrivetrain.drive_distance(-12);

        pidDrivetrain.turn_to_angle(180 + 45);
        intakeMotors.stop();

        // // drop first goal
        pidDrivetrain.drive_max_voltage = medSpeed;
        pidDrivetrain.turn_max_voltage = medSpeed;

        float goalDropDist1 = 33.9 - 7.5 - 10 - 0.5; // 7.5 is half the length of the robot, 10 is the length of the goal. tweak more if needed.
        pidDrivetrain.drive_distance(-1 * goalDropDist1);
        mobileGoalLock.set(false);
        wait(250, msec);
        pidDrivetrain.drive_distance(goalDropDist1 - 7);

        //Require higher turning accuracy to get 2nd goal

        // // clamp second goal
        pidDrivetrain.drive_timeout = 3000;
        pidDrivetrain.turn_to_angle(90);
        pidDrivetrain.drive_distance(-1 * (72 - 24));
        pidDrivetrain.drive_timeout = 2000;

        pidDrivetrain.drive_max_voltage = lowSpeed;
        pidDrivetrain.drive_distance(-24);
        
        mobileGoalLock.set(true);
        wait(350, msec);

        // 2 rings further away on the right
        pidDrivetrain.drive_max_voltage = medSpeed;
        intakeMotors.spin(forward);

        pidDrivetrain.turn_to_angle(180);
        pidDrivetrain.drive_distance(24);
        pidDrivetrain.turn_to_angle(270);
        pidDrivetrain.drive_distance(26);

        // 3 rings on right corner
        pidDrivetrain.drive_max_voltage = lowSpeed;

        pidDrivetrain.turn_to_angle(0);
        pidDrivetrain.drive_distance(21);
        pidDrivetrain.drive_distance(8);
        wait(500, msec);
        pidDrivetrain.drive_distance(-9);
        pidDrivetrain.turn_to_angle(270);
        pidDrivetrain.drive_distance(10);
        wait(500, msec);
        pidDrivetrain.drive_distance(-12);

        pidDrivetrain.turn_to_angle(90 + 45);
        intakeMotors.stop();

        wait(250, msec);

        // drop second goal
        pidDrivetrain.drive_max_voltage = medSpeed;
        pidDrivetrain.turn_max_voltage = medSpeed;

        intakeMotors.stop();
        pidDrivetrain.drive_distance(-1 * (goalDropDist1 - 1.5));
        mobileGoalLock.set(false);
        wait(250, msec);
        pidDrivetrain.drive_distance(goalDropDist1 + 14 - 1.5);

        // drive to right blue goal
        pidDrivetrain.turn_to_angle(180);

        pidDrivetrain.drive_timeout = 5000;

        pidDrivetrain.drive_distance(60);
        pidDrivetrain.drive_timeout = 3000;
        pidDrivetrain.turn_to_angle(90 + 45);
        pidDrivetrain.drive_distance(15);

        pidDrivetrain.drive_max_voltage = lowSpeed;

        pidDrivetrain.turn_to_angle(0);
        pidDrivetrain.drive_distance(-16);
        wait(250, msec);
        mobileGoalLock.set(true);

        pidDrivetrain.drive_max_voltage = medSpeed;

        // shove right blue goal into corner
        pidDrivetrain.turn_to_angle(80);
        mobileGoalLock.set(false);
        wait(500, msec);
        float goalDropDist2 = 48 - 7.5 - 10 - 2;
        pidDrivetrain.drive_max_voltage = maxSpeed;
        pidDrivetrain.drive_distance(-1 * goalDropDist2);
        wait(250, msec);

        // shove left blue goal into corner
        pidDrivetrain.drive_timeout = 3000;
        pidDrivetrain.drive_distance(goalDropDist2 + 10);
        pidDrivetrain.turn_to_angle(180 + 80);
        pidDrivetrain.drive_distance(-1 * (goalDropDist2 + 28));
        mobileGoalLock.set(true);
        pidDrivetrain.turn_to_angle(-30);
        mobileGoalLock.set(false);
        pidDrivetrain.drive_distance(-48);
        pidDrivetrain.drive_distance(48);
    }
}