#include "vex.h"
#include "pid.h"

using namespace vex;

brain Brain;
controller Controller;

motor leftMotorA = motor(PORT11, ratio6_1, true);
motor leftMotorB = motor(PORT12, ratio6_1);
motor rightMotorA = motor(PORT19, ratio6_1, true);
motor rightMotorB = motor(PORT20, ratio6_1);

inertial Inertial = inertial(PORT1);
motor_group leftMotors = motor_group(leftMotorA, leftMotorB);
motor_group rightMotors = motor_group(rightMotorA, rightMotorB);
smartdrive Drivetrain = smartdrive(leftMotors, rightMotors, Inertial, 82.55, 387.35, 304.8, mm, 1);

digital_out mobileGoalLock = digital_out(Brain.ThreeWirePort.A);
distance goalDetect = distance(PORT2);
bool locked = false;



motor firstStageIntake = motor(PORT13, ratio18_1);
motor secondStageIntake = motor(PORT21, ratio6_1, true);
motor_group intakeMotors = motor_group(firstStageIntake, secondStageIntake);
int intakeSpeed = 93;
bool intakeForward = false;
bool intakeReverse = false;

motor armMotorA = motor(PORT4, ratio36_1, true);
motor armMotorB = motor(PORT5, ratio36_1);
motor_group armMotors = motor_group(armMotorA, armMotorB);

competition Competition;
digital_in button = digital_in(Brain.ThreeWirePort.B);
int autonSelect = 0;

void vexcodeInit(void)
{
    //Vex requires this to compile   
}
