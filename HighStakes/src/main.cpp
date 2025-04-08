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
        Brain.Screen.print("Calibrating inertial + TEST ");
        wait(150, msec);
    }
    wait(25, msec);
    Brain.Screen.print("Calibrated!");
    Brain.Screen.clearScreen();

    Competition.autonomous(auton);
    Competition.drivercontrol(drive);

    Controller.ButtonR1.pressed(R1Press);
    Controller.ButtonR2.pressed(R2Press);
    Controller.ButtonRight.pressed(lbLoadButton);
    Controller.ButtonY.pressed(lbScoreButton);
    Controller.ButtonB.pressed(YPress);
    Controller.ButtonX.pressed(sortToggle);
    Controller.ButtonL1.pressed(driverLock);
    button.high(autonUpdate);
    Brain.Screen.pressed(allianceUpdate);
    // Need to tune this
    // colorSensor.objectDetectThreshold();
    colorSensor.objectDetected(colorSort);

    thread antiJamThread = thread(antiJam);
    thread tempThread = thread(warning);
    
    selector();
    wait(15, msec);
}
