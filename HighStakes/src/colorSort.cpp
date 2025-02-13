#include "vex.h"
using namespace vex;

int blueHue = 200;
int redHue = 5;
int error = 20;
   
void colorSort() // i tried to make this cleaner
{
    colorSensor.setLightPower(50, percent);
    while (true)
    {
        if (
            (allianceSelect <= 1 &&
            colorSortEnable && 
            intakeMotors.voltage() > 0 &&
            abs(colorSensor.hue() - blueHue) < error) ||
            (allianceSelect == 2 &&
            colorSortEnable && 
            intakeMotors.voltage() > 0 &&
            abs(colorSensor.hue() - redHue) < error)
        )
        {
            wait(100, msec); // delay for the ring to travel further up the intake
            intakeMotors.stop(brake);
            wait(100, msec); // amount of time the intake stops for
            intakeMotors.spin(forward);
        }
    }
}

void sortToggle()
{
    colorSortEnable = !colorSortEnable;
}