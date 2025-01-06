#include "vex.h"
using namespace vex;

void selector(void)
{
    Brain.Screen.clearScreen();
    wait(5, msec);
    if (allianceSelect == 0)
    {
        Brain.Screen.setPenColor(vex::color::purple);
        Brain.Screen.print("Programming Skills");
    }
    else if (allianceSelect == 1)
    {
        Brain.Screen.setPenColor(vex::color::red);
        Brain.Screen.print("Red Alliance selected");
        Brain.Screen.setCursor(2, 1);

        if (autonSelect == 1)
        {
            Brain.Screen.print("Left Side Solo AWP");
        }
        else if (autonSelect == 2)
        {
            Brain.Screen.print("Left Side, 1 Alliance + 3 Mogo + Corner End");
        }
        else if (autonSelect == 3)
        {
            Brain.Screen.print("Right side 2-ring mobile goal + Corner End");
        }
        else if (autonSelect == 4)
        {
            Brain.Screen.print("Right side 2-ring mobile goal + Ladder Touch");
        }
        else if (autonSelect == 0)
        {
            Brain.Screen.print("Red test slot");
        }
    }
    else if (allianceSelect == 2)
    {
        Brain.Screen.setPenColor(vex::color::cyan);
        Brain.Screen.print("Blue Alliance selected");
        Brain.Screen.setCursor(2, 1);

        if (autonSelect == 1)
        {
            Brain.Screen.print("Right Side Solo AWP");
        }
        else if (autonSelect == 2)
        {
            Brain.Screen.print("Right Side, 1 Alliance + 3 Mogo + Corner End");
        }
        else if (autonSelect == 3)
        {
            Brain.Screen.print("Left side  2-ring mobile goal + Corner End");
        }
        else if (autonSelect == 4)
        {
            Brain.Screen.print("Left side  2-ring mobile goal + Ladder Touch");
        }
        else if (autonSelect == 0)
        {
            Brain.Screen.print("Blue test slot");
        }
    }
}

void allianceUpdate(void)
{
    if (allianceSelect == 2)
    {
        allianceSelect = 0;
        return;
    }
    allianceSelect++;
    selector();
}

void autonUpdate(void)
{
    if (autonSelect == 6)
    {
        autonSelect = 0;
        return;
    }
    autonSelect++;
    selector();
}