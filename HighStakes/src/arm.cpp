#include "vex.h"
using namespace vex;

void armMovement()
{
    armMotors.setMaxTorque(100, percent);
    armMotorA.setBrake(brake);
    armMotorB.setBrake(brake);
    while (true)
    {
        armMotors.setVelocity(30, percent);

        if (Controller.ButtonUp.pressing())
        {
            armMotors.spin(forward);
            armMotorA.setBrake(hold);
            armMotorB.setBrake(hold);
        }
        else if (Controller.ButtonDown.pressing())
        {
            armMotors.spin(reverse);
            armMotorA.setBrake(brake);
            armMotorB.setBrake(brake);
        }
        else if (Controller.ButtonLeft.pressing() || Controller.ButtonRight.pressing())
        {
            armMotorA.setBrake(brake);
            armMotorB.setBrake(brake);
            armMotors.setVelocity(60, percent);
            armMotors.spinFor(vex::directionType::rev, 350, msec, 60.0, vex::velocityUnits::pct);
        }
        else 
        {
            armMotors.stop();
        }
        wait(5, msec);
    }
}