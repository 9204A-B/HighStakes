#include "vex.h"

using namespace vex;

brain Brain;
controller Controller = controller(primary);
controller teleControl = controller(partner);

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
Drive pidDrivetrain(ZERO_TRACKER_ODOM, leftMotors, rightMotors, PORT1, 3.25, .6, 360, PORT1, -PORT2, PORT3, -PORT4, PORT19, 3.25, 5.5, 0, 0, 0);
float turnExp = 1; // MUST BE >= 1
float turnScale = 0.8;

digital_out mobileGoalLock = digital_out(Brain.ThreeWirePort.D);
distance goalDetect = distance(PORT2);
int clampDistance = 100;
bool locked = false;

motor intakeMotors = motor(PORT4, ratio6_1, true);
int intakeSpeed = 85;
bool intakeForward = false;
bool intakeReverse = false;
bool antiJamEnable = true;

motor lb = motor(PORT3, ratio36_1);
rotation lbRotation = rotation(PORT5);
int lbSelect = 0;
bool lbShift = false;

digital_out Doinker = digital_out(Brain.ThreeWirePort.C);

competition Competition;
digital_in button = digital_in(Brain.ThreeWirePort.B);
int allianceSelect = 0;
int autonSelect = 0;

optical colorSensor = optical(PORT6);
distance colorDistance = distance(PORT14);
bool colorSortEnable = true;

void vexcodeInit(void)
{
    // Vex requires this to compile
}
