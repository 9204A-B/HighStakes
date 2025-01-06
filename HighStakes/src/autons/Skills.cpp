#include "vex.h"
#include <math.h>
using namespace vex;

namespace Autons
{
    void Skills::run()
    {
        // start in a position where running the intake scores onto the alliance stake

        pidDrivetrain.set_heading(180);
        intakeMotors.setVelocity(intakeSpeed, percent);
        intakeMotors.spin(forward);
        wait(1000, msec);

        intakeMotors.spin(reverse);
        wait(500, msec);
        pidDrivetrain.drive_distance(12); // tweak this number until the robot is perfectly centered on the start line
    }
}