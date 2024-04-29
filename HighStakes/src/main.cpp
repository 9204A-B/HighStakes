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
    Competition.autonomous(auton);
    Competition.drivercontrol(drive);
}
