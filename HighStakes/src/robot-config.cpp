#include "vex.h"
using namespace vex;

brain Brain;
controller Controller;

motor leftMotorA = motor(11, ratio6_1);
motor leftMotorB = motor(12, ratio6_1);
motor rightMotorA = motor(19, ratio6_1, true);
motor rightMotorB = motor(20, ratio6_1, true);

motor_group leftMotors = motor_group(leftMotorA, leftMotorB);
motor_group rightMotors = motor_group(rightMotorA, rightMotorB);
drivetrain Drivetrain = drivetrain(leftMotors, rightMotors, 320, 320, 320, mm, 1.5);

digital_out mobileGoalLock = digital_out(Brain.ThreeWirePort.A);

motor intakeA = motor(1, ratio6_1);
motor intakeB = motor(2, ratio6_1);
motor_group intake = motor_group(intakeA, intakeB);

distance Distance = distance(3);
// Update name to be clearer

inertial Inertial = inertial(4);

competition Competition;

void vexcodeInit(void)
{
    Inertial.calibrate();
    //Vex requires this to compile
}
