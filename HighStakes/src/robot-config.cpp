#include "vex.h"
#include "pid.h"

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
motor_group leftMotors = motor_group(leftMotorA, leftMotorB);
motor_group rightMotors = motor_group(rightMotorA, rightMotorB);
smartdrive Drivetrain = smartdrive(leftMotors, rightMotors, Inertial, 82.55, 387.35, 304.8, mm, 1);

digital_out mobileGoalLock = digital_out(Brain.ThreeWirePort.A);
distance goalDetect = distance(PORT2);
bool locked = false;
int clampDistance = 80;

motor intakeMotors = motor(PORT21, ratio6_1);
int intakeSpeed = 93;
bool intakeForward = false;
bool intakeReverse = false;

competition Competition;
digital_in button = digital_in(Brain.ThreeWirePort.B);
int autonSelect = 0;

void vexcodeInit(void)
{
    //Vex requires this to compile   
}
