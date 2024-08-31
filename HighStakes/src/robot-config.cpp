#include "vex.h"
#include "pid.h"

using namespace vex;

brain Brain;
controller Controller;

motor leftMotorA = motor(PORT13, ratio6_1, true);
motor leftMotorB = motor(PORT12, ratio6_1);
motor rightMotorA = motor(PORT19, ratio6_1, true);
motor rightMotorB = motor(PORT20, ratio6_1);

motor_group leftMotors = motor_group(leftMotorA, leftMotorB);
motor_group rightMotors = motor_group(rightMotorA, rightMotorB);
drivetrain Drivetrain = drivetrain(leftMotors, rightMotors, 82.55, 387.35, 304.8, mm, 1);

digital_out mobileGoalLock = digital_out(Brain.ThreeWirePort.A);
distance goalDetect = distance(PORT2);

inertial Inertial = inertial(PORT1);

competition Competition;

void vexcodeInit(void)
{
    //Vex requires this to compile    
}
