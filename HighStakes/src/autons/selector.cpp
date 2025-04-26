#include "vex.h"
using namespace vex;

void selector(void)
{
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 3);
    wait(5, msec);
    if (allianceSelect == 0)
    {
        Brain.Screen.clearScreen(vex::color::purple);
        Brain.Screen.print("Programming Skills");
    }
    else if (allianceSelect > 0)
    {
        if (allianceSelect == 1)
        {
            Brain.Screen.clearScreen(vex::color::red);
            Brain.Screen.print("Red Alliance selected");
        }
        else if (allianceSelect == 2)
        {
            Brain.Screen.clearScreen(vex::color::cyan);
            Brain.Screen.print("Blue Alliance selected");
        }
        Brain.Screen.newLine();

        switch (autonSelect)
        {
            case 1 {
                Brain.Screen.print("Negative 3 + 1 - Ladder Touch");
            }
            case 2 {
                Brain.Screen.print("Negative 3 + 1 - Corner End");
            }
            case 3 {
                Brain.Screen.print("Negative 4-ring - Ladder Touch");
            }
            case 4 {
                Brain.Screen.print("Negative 4-ring - Corner End");
            }
            case 5 {
                Brain.Screen.print("Positive 1 + 1 - Ladder Touch");
            }
            case 6 {
                Brain.Screen.print("Positive 1 + 1 - Screening");
            }
            case 7 {
                Brain.Screen.print("Positive 2-ring - Ladder Touch");
            }
            case 8 {
                Brain.Screen.print("Positive 2-ring - Screening");
            }
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
    if (autonSelect == 8)
    {
        autonSelect = 0;
        return;
    }
    autonSelect++;
    selector();
}