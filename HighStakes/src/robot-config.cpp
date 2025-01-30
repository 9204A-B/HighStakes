#include "vex.h"

using namespace vex;

brain Brain;
controller Controller;

motor leftMotorA = motor(PORT11, ratio6_1);
motor leftMotorB = motor(PORT12, ratio6_1, true);
motor leftMotorC = motor(PORT13, ratio6_1, true);
motor rightMotorA = motor(PORT18, ratio6_1, true);
motor rightMotorB = motor(PORT19, ratio6_1);
motor rightMotorC = motor(PORT20, ratio6_1);

inertial Inertial = inertial(PORT1);
motor_group leftMotors = motor_group(leftMotorA, leftMotorB, leftMotorC);
motor_group rightMotors = motor_group(rightMotorA, rightMotorB, rightMotorC);
smartdrive Drivetrain = smartdrive(leftMotors, rightMotors, Inertial, 82.55, 387.35, 304.8, mm, .6);
Drive pidDrivetrain(ZERO_TRACKER_NO_ODOM, leftMotors, rightMotors, PORT1, 3.25, .6, 360, PORT1, -PORT2, PORT3, -PORT4, 3, 2.75, -2, 1, -2.75, 5.5);
float turnExp = 1.5; // MUST BE >= 1

digital_out mobileGoalLock = digital_out(Brain.ThreeWirePort.A);
distance goalDetect = distance(PORT2);
bool locked = false;
int clampDistance = 60;

motor intakeMotors = motor(PORT4, ratio6_1, true);
int intakeSpeed = 93;
bool intakeForward = false;
bool intakeReverse = false;
bool antiJamEnable = true;

motor lb = motor(PORT3, ratio36_1, true);
distance lbDistance = distance(PORT5);
int lbSelect = 0;

digital_out Doinker = digital_out(Brain.ThreeWirePort.C);

competition Competition;
digital_in button = digital_in(Brain.ThreeWirePort.B);
int allianceSelect = 0;
int autonSelect = 0;

void vexcodeInit(void)
{
    // Vex requires this to compile
}
