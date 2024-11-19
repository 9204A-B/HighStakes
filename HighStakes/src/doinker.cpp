#include "vex.h"
using namespace vex;

void doink()
{
    while (true)
    {
        bool down = false;

        while (!Controller.ButtonY.pressing())
        {
            wait(5, msec);
        }

        down = !down;
        Doinker.set(down);

        while (Controller.ButtonY.pressing())
        {
            wait(5, msec);
        }

        wait(10, msec);
    }
}