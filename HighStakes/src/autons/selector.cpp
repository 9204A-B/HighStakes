#include "vex.h"
using namespace vex;

void selector(void)
{
    while (true)
    {
        Brain.Screen.setCursor(1, 1);
        if (autonSelect < 5 && button.HIGH)
        {
            autonSelect++;
            wait(200, msec);
        }
        else if (button.HIGH)
        {
            autonSelect = 0;
            wait(200, msec);
        }

        if (allianceSelect < 2 && brainScreen)
        {
            allianceSelect++;
            wait(200, msec);
        }
        else if (brainScreen)
        {
            allianceSelect = 0;
            wait(200, msec);
        }

        if (allianceSelect == 2)
        {
            autonSelect = 0;
        }

        wait(5, msec);
        if (allianceSelect == 0)
        {
            Brain.Screen.setPenColor(vex::color::red);
            Brain.Screen.print("Red Alliance selected");
            Brain.Screen.setCursor(1, 2);

            if (autonSelect == 0)
            {
                Brain.Screen.print("Left 4-ring mobile goal + Corner End");
            }
            else if (autonSelect == 1)
            {
                Brain.Screen.print("Left 4-ring mobile goal + Ladder Touch");
            }
            else if (autonSelect == 2)
            {
                Brain.Screen.print("Right 2-ring mobile goal + Corner End");
            }
            else if (autonSelect == 3)
            {
                Brain.Screen.print("Right 2-ring mobile goal + Ladder Touch");
            }
            else if (autonSelect == 4)
            {
                Brain.Screen.print("2-ring goal rush");
            }
            else if (autonSelect == 5)
            {
                Brain.Screen.print("Red test slot");
            }
        }
        else if (allianceSelect == 1)
        {
            Brain.Screen.setPenColor(vex::color::cyan);
            Brain.Screen.print("Blue Alliance selected");
            Brain.Screen.setCursor(1, 2);

            if (autonSelect == 0)
            {
                Brain.Screen.print("Right 4-ring mobile goal + Corner End");
            }
            else if (autonSelect == 1)
            {
                Brain.Screen.print("Right 4-ring mobile goal + Ladder Touch");
            }
            else if (autonSelect == 2)
            {
                Brain.Screen.print("Left 2-ring mobile goal + Corner End");
            }
            else if (autonSelect == 3)
            {
                Brain.Screen.print("Left 2-ring mobile goal + Ladder Touch");
            }
            else if (autonSelect == 4)
            {
                Brain.Screen.print("2-ring goal rush");
            }
            else if (autonSelect == 5)
            {
                Brain.Screen.print("Blue test slot");
            }
        }
        else if (allianceSelect == 2)
        {
            Brain.Screen.setPenColor(vex::color::purple);
            Brain.Screen.clearLine(2);
            Brain.Screen.print("Programming Skills");
        }
        wait(10, msec);
    }
}