#include "vex.h"
using namespace vex;

int blueHue = 210;
int redHue = 5;
int error = 40;

void colorSort() // i tried to make this cleaner
{                // 'Tis cleaner
    printf("ring detected");
    if (
        (allianceSelect <= 1 &&
        colorSortEnable && 
        intakeMotors.voltage() > 0 &&
        fabs(colorSensor.hue() - blueHue) < error) ||

        (allianceSelect == 2 &&
        colorSortEnable && 
        intakeMotors.voltage() > 0 &&
        fabs(colorSensor.hue() - redHue) < error)
    )
    {
        printf("color sort");
        
        wait(30, msec); // delay for the ring to travel further up the intake
        intakeMotors.spin(reverse);
        wait(165, msec); // amount of time the intake stops for
        intakeMotors.spin(forward);
    }
}

void sortToggle()
{
    colorSortEnable = !colorSortEnable;
}