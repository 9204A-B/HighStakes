#include "vex.h"
using namespace vex;

void startTimer()
{
    timer Timer = timer();
    while (Timer.time(sec) != 75){}
    Controller.Screen.clearScreen();
    Controller.Screen.setCursor(1, 1);
    Controller.Screen.print("30 Seconds Left");
    Controller.rumble("..");
    while (Timer.time(sec) != 105){}
    Controller.Screen.clearScreen();
    Controller.Screen.setCursor(1, 1);
    Controller.Screen.print("10 Seconds Left");
    Controller.rumble("..--");
}