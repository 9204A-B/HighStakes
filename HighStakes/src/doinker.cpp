#include "vex.h"
using namespace vex;

void doink()
{
    bool down = false;
    while (true)
    {
        while (!Controller.ButtonL2.pressing())
        {
            wait(5, msec);
        }

        down = !down;
        Doinker.set(down);

        while (Controller.ButtonL2.pressing())
        {
            wait(5, msec);
        }

        wait(10, msec);
    }
}