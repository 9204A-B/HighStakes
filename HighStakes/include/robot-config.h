#include "pid.h"

using namespace vex;

extern brain Brain;
extern controller Controller;

extern motor leftMotorA;
extern motor leftMotorB;
extern motor rightMotorA;
extern motor rightMotorB;

extern inertial Inertial;
extern motor_group leftMotors;
extern motor_group rightMotors;
extern smartdrive Drivetrain;

extern digital_out mobileGoalLock;
extern distance goalDetect;
extern bool goal;
extern bool locked;


extern motor firstStageIntake;
extern motor secondStageIntake;
extern motor_group intakeMotors;
extern int intakeSpeed;
extern bool intakeForward;
extern bool intakeReverse;

extern motor armMotorA;
extern motor armMotorB;
extern motor_group armMotors;

extern competition Competition;
extern digital_in button;
extern int autonSelect;

void vexcodeInit(void);