/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       logan                                                     */
/*    Created:      4/29/2024, 8:36:32 AM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

int main() 
{
    vexcodeInit();    
    Inertial.calibrate(0);
     
    while (Inertial.isCalibrating())
    {
        Brain.Screen.print("Calibrating inertial ");
        wait(150, msec);
    }
    wait(250, msec);
    Brain.Screen.print("Calibrated!");
    Brain.Screen.clearScreen();
    Competition.autonomous(auton);
    Competition.drivercontrol(drive);
}
