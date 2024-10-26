#include "vex.h"
using namespace vex;

    void selector(void)
    {
        while (true)
        {
            Brain.Screen.setCursor(1, 1);
            if (autonSelect < 4 && button.HIGH)
            {
                autonSelect++;
                wait(200, msec);
            }
            else if (button.HIGH)
            {
                autonSelect = 0;
                wait(200, msec);
            }
            wait(5, msec);
            if (autonSelect == 0)
            {
                Brain.Screen.setPenColor(vex::color::red);
                Brain.Screen.print("Red left side selected");
            }
            else if (autonSelect == 1)
            {
                Brain.Screen.setPenColor(vex::color::red);
                Brain.Screen.print("Red right side selected");
            }
            else if (autonSelect == 2)
            {
                Brain.Screen.setPenColor(vex::color::cyan);
                Brain.Screen.print("Blue left side selected");
            }
            else if (autonSelect == 3)
            {
                Brain.Screen.setPenColor(vex::color::cyan);
                Brain.Screen.print("Blue right side selected");
            }
            else if (autonSelect == 4)
            {
                Brain.Screen.setPenColor(vex::color::white);   
                Brain.Screen.print("Skills selected");
            }
            wait(10, msec);
        }
    }