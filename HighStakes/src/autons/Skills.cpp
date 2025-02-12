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
        float medSpeed = 9.5;
        float lowSpeed = 7;

        pidDrivetrain.turn_settle_error = 1;
        pidDrivetrain.drive_ki = .03;
        pidDrivetrain.turn_timeout = 1500;
        pidDrivetrain.drive_timeout = 1750;
        pidDrivetrain.set_coordinates(72, 9.5, 0);

        pidDrivetrain.drive_max_voltage = medSpeed;
        pidDrivetrain.turn_max_voltage = medSpeed;
        intakeMotors.setVelocity(intakeSpeed, percent);
        pidDrivetrain.set_heading(180);

        // score alliance stake and align for first goal
        antiJamEnable = false;
        intakeMotors.spin(forward);
        wait(450, msec);
        intakeMotors.stop();
        intakeMotors.spin(reverse);
        wait(450, msec);
        intakeMotors.stop();
        pidDrivetrain.drive_distance(12);
        antiJamEnable = true;

        // clamp goal 1
        pidDrivetrain.turn_to_angle(-90);
        // check here for proper alignment :)

        pidDrivetrain.drive_max_voltage = lowSpeed;
        pidDrivetrain.drive_timeout = 3000;
        pidDrivetrain.drive_distance(-24);
        wait(100, msec);
        mobileGoalLock.set(true);
        wait(100, msec);

        // 2 rings further away on the left
        pidDrivetrain.drive_max_voltage = medSpeed;
        pidDrivetrain.drive_timeout = 2000;
        pidDrivetrain.turn_to_angle(180);
        intakeMotors.spin(forward);
        pidDrivetrain.drive_distance(24);
        pidDrivetrain.turn_to_angle(90);
        pidDrivetrain.drive_distance(23);

        // 3 rings on left corner
        pidDrivetrain.drive_max_voltage = lowSpeed;

        pidDrivetrain.turn_to_angle(0);
        pidDrivetrain.drive_distance(21);
        pidDrivetrain.drive_distance(8);
        pidDrivetrain.drive_distance(-8.5);
        pidDrivetrain.turn_to_angle(90);
        pidDrivetrain.drive_distance(10);
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
        pidDrivetrain.drive_distance(goalDropDist1 - 6);

        // // clamp second goal
        pidDrivetrain.drive_timeout = 3000;
        pidDrivetrain.turn_to_angle(90);
        pidDrivetrain.drive_distance(-48);     

        pidDrivetrain.drive_max_voltage = lowSpeed;
        pidDrivetrain.drive_distance(-23);
        wait(100, msec);
        mobileGoalLock.set(true);
        wait(100, msec);

        // 2 rings further away on the right
        pidDrivetrain.drive_max_voltage = medSpeed;
        pidDrivetrain.drive_timeout = 2000;

        pidDrivetrain.turn_to_angle(180);
        intakeMotors.spin(forward);
        pidDrivetrain.drive_distance(24);
        pidDrivetrain.turn_to_angle(270);
        pidDrivetrain.drive_distance(24);

        // 3 rings on right corner
        pidDrivetrain.drive_max_voltage = lowSpeed;

        pidDrivetrain.turn_to_angle(0);
        pidDrivetrain.drive_distance(21);
        pidDrivetrain.drive_distance(9);
        pidDrivetrain.drive_distance(-10);
        pidDrivetrain.turn_to_angle(270);
        pidDrivetrain.drive_distance(10);
        pidDrivetrain.drive_distance(-11);

        pidDrivetrain.turn_to_angle(90 + 45);
        intakeMotors.stop();

        wait(250, msec);

        // drop second goal
        pidDrivetrain.drive_max_voltage = maxSpeed;
        pidDrivetrain.turn_max_voltage = maxSpeed;

        intakeMotors.stop();
        pidDrivetrain.drive_distance(-1 * (goalDropDist1));
        mobileGoalLock.set(false);
        wait(250, msec);
        pidDrivetrain.drive_distance(goalDropDist1 + 11);

        // drive to right blue goal
        pidDrivetrain.turn_to_angle(180);

        pidDrivetrain.drive_timeout = 4500;

        pidDrivetrain.drive_distance(60);
        pidDrivetrain.drive_timeout = 2000;
        pidDrivetrain.turn_to_angle(90 + 45);
        pidDrivetrain.drive_distance(17.25);

        pidDrivetrain.drive_max_voltage = lowSpeed;

        pidDrivetrain.turn_to_angle(0);
        pidDrivetrain.drive_distance(-17);
        wait(100, msec);
        mobileGoalLock.set(true);
        wait(100, msec);

        pidDrivetrain.drive_max_voltage = maxSpeed;
        pidDrivetrain.drive_distance(7.5);

        // shove right blue goal into corner
        pidDrivetrain.turn_to_angle(70);
        mobileGoalLock.set(false);
        wait(250, msec);
        float goalDropDist2 = 48 - 7.5 - 10 - 2;

        // shove left blue goal into corner
        pidDrivetrain.drive_max_voltage = maxSpeed;
        pidDrivetrain.drive_distance(-1 * goalDropDist2);
        wait(250, msec);
        
        // drive to empty goal
        pidDrivetrain.drive_distance(goalDropDist2);
        pidDrivetrain.turn_to_angle(180 + 80);
        pidDrivetrain.drive_max_voltage = medSpeed;
        pidDrivetrain.drive_distance(-28);
        pidDrivetrain.drive_max_voltage = lowSpeed;
        mobileGoalLock.set(true);
        pidDrivetrain.drive_distance(-12);

        // score empty goal
        pidDrivetrain.drive_max_voltage = maxSpeed;
        pidDrivetrain.turn_to_angle(-65);
        intakeMotors.spin(forward);
        pidDrivetrain.drive_distance(24);

        // shove empty goal
        mobileGoalLock.set(false);
        wait(250, msec);
        pidDrivetrain.drive_distance(-48 - 24);
        pidDrivetrain.drive_distance(48);
    }
}