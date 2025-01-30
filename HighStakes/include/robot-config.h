#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H
using namespace vex;

extern brain Brain;
extern controller Controller;

extern motor leftMotorA;
extern motor leftMotorB;
extern motor leftMotorC;
extern motor rightMotorA;
extern motor rightMotorB;
extern motor rightMotorC;

extern inertial Inertial;
extern motor_group leftMotors;
extern motor_group rightMotors;
extern smartdrive Drivetrain;
extern float turnExp;

extern digital_out mobileGoalLock;
extern distance goalDetect;
extern bool goal;
extern bool locked;
extern int clampDistance;

extern motor intakeMotors;
extern int intakeSpeed;
extern bool intakeForward;
extern bool intakeReverse;
extern bool antiJamEnable;

extern motor lb;
extern distance lbDistance;
extern int lbSelect;

extern digital_out Doinker;

extern competition Competition;
extern digital_in button;
extern int allianceSelect;
extern int autonSelect;

void vexcodeInit(void);
#endif