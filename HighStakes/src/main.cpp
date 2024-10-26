/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       logan                                                     */
/*    Created:      4/29/2024, 8:36:32 AM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "autons.h"

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
    wait(25, msec);
    Brain.Screen.print("Calibrated!");
    Brain.Screen.clearScreen();
    
    Competition.autonomous(auton);
    Competition.drivercontrol(drive);

    Controller.ButtonR1.pressed(R1Press);
    Controller.ButtonR2.pressed(R2Press);
    thread tempThread = thread(warning);
    thread selectThread = thread(selector);
    wait(15, msec);
}
