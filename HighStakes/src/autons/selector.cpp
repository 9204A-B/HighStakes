#include "vex.h"
using namespace vex;

void selector(void)
{
    while (true)
    {
        Brain.Screen.setCursor(1, 1);
        if (autonSelect < 6 && button.HIGH)
        {
            autonSelect++;
            wait(200, msec);
        }
        else if (button.HIGH)
        {
            autonSelect = 0;
            wait(200, msec);
        }
                        //Was brainScreen supposed to be this?
        if (allianceSelect < 2 && Brain.Screen.pressing())
        {
            allianceSelect++;
            wait(200, msec);
        }
        else if (Brain.Screen.pressing())
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

            if (autonSelect == 1)
            {
                Brain.Screen.print("Left side 4-ring mobile goal + Corner End");
            }
            else if (autonSelect == 2)
            {
                Brain.Screen.print("Left side 4-ring mobile goal + Ladder Touch");
            }
            else if (autonSelect == 3)
            {
                Brain.Screen.print("Right side 2-ring mobile goal + Corner End");
            }
            else if (autonSelect == 4)
            {
                Brain.Screen.print("Right side 2-ring mobile goal + Ladder Touch");
            }
            else if (autonSelect == 5)
            {
                Brain.Screen.print("Right side goal rush + Corner End");
            }
            else if (autonSelect == 6)
            {
                Brain.Screen.print("Right side goal rush + Ladder Touch");
            }
            else if (autonSelect == 0)
            {
                Brain.Screen.print("Red test slot");
            }
        }
        else if (allianceSelect == 1)
        {
            Brain.Screen.setPenColor(vex::color::cyan);
            Brain.Screen.print("Blue Alliance selected");
            Brain.Screen.setCursor(1, 2);

            if (autonSelect == 1)
            {
                Brain.Screen.print("Right side  4-ring mobile goal + Corner End");
            }
            else if (autonSelect == 2)
            {
                Brain.Screen.print("Right side  4-ring mobile goal + Ladder Touch");
            }
            else if (autonSelect == 3)
            {
                Brain.Screen.print("Left side  2-ring mobile goal + Corner End");
            }
            else if (autonSelect == 4)
            {
                Brain.Screen.print("Left side  2-ring mobile goal + Ladder Touch");
            }
            else if (autonSelect == 5)
            {
                Brain.Screen.print("Left side goal rush + Corner End");
            }
            else if (autonSelect == 6)
            {
                Brain.Screen.print("Left side goal rush + Corner End");
            }
            else if (autonSelect == 0)
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

        // old selector code
        // Brain.Screen.setCursor(1, 1);
        // if (autonSelect < 4 && button.HIGH)
        // {
        //     autonSelect++;
        //     wait(200, msec);
        // }
        // else if (button.HIGH)
        // {
        //     autonSelect = 0;
        //     wait(200, msec);
        // }
        // wait(5, msec);
        // if (autonSelect == 0)
        // {
        //     Brain.Screen.setPenColor(vex::color::red);
        //     Brain.Screen.print("Red left side selected");
        // }
        // else if (autonSelect == 1)
        // {
        //     Brain.Screen.setPenColor(vex::color::red);
        //     Brain.Screen.print("Red right side selected");
        // }
        // else if (autonSelect == 2)
        // {
        //     Brain.Screen.setPenColor(vex::color::cyan);
        //     Brain.Screen.print("Blue left side selected");
        // }
        // else if (autonSelect == 3)
        // {
        //     Brain.Screen.setPenColor(vex::color::cyan);
        //     Brain.Screen.print("Blue right side selected");
        // }
        // else if (autonSelect == 4)
        // {
        //     Brain.Screen.setPenColor(vex::color::white);
        //     Brain.Screen.print("Skills selected");
        // }
        wait(10, msec);
    }
}