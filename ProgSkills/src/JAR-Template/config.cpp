#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  // TESTED
  // Constants are not causing the PID issue
  pidDrivetrain.set_drive_constants(12, 1.6, 0, 0, 0);
  pidDrivetrain.set_heading_constants(6, .4, 0, 1, 0);
  pidDrivetrain.set_turn_constants(12, .4, .03, 3, 15);
  pidDrivetrain.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  pidDrivetrain.set_drive_exit_conditions(1, 300, 3000);
  pidDrivetrain.set_turn_exit_conditions(5, 300, 3000);
  pidDrivetrain.set_swing_exit_conditions(5, 300, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  pidDrivetrain.heading_max_voltage = 10;
  pidDrivetrain.drive_max_voltage = 8;
  pidDrivetrain.drive_settle_error = 3;
  pidDrivetrain.boomerang_lead = .5;
  pidDrivetrain.drive_min_voltage = 0;
}
