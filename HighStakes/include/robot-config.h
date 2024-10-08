#include "pid.h"

using namespace vex;

extern brain Brain;
extern controller Controller;

extern motor leftMotorA;
extern motor leftMotorB;
extern motor rightMotorA;
extern motor rightMotorB;

extern motor_group leftMotors;
extern motor_group rightMotors;
extern drivetrain Drivetrain;

extern digital_out mobileGoalLock;
extern distance goalDetect;
extern bool goal;

extern inertial Inertial;
extern motor firstStageIntake;
extern motor secondStageIntake;
extern motor_group intakeMotors;
extern int intakeSpeed;
extern bool intakeForward;
extern bool intakeReverse;

extern motor armMotor;

extern competition Competition;

void vexcodeInit(void);