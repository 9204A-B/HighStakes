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

extern motor intakeA;
extern motor intakeB;
extern motor_group intake;

extern distance Distance;
// Update name to be clearer

extern inertial Inertial;

extern competition Competition;

void vexcodeInit(void);