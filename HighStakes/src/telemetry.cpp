// #include "vex.h"
// using namespace vex;

// void screen(void)
// {
//     while (true)
//     {
//         int index = 0;
//         if (teleControl.ButtonLeft.pressing())
//         {
//             index++;
//         }
//         else if (teleControl.ButtonRight.pressing())
//         {
//             index--;
//         }

//         switch (index)
//         {
//             case 0:
//                 {
//                     temp();
//                     break;
//                 }
//         }

//         wait(25, msec);
//     }
// }

// void temp(void)
// {
//     motor* motors[] = {&leftMotorA, &leftMotorB, &leftMotorC,
//          &rightMotorA, &rightMotorB, &rightMotorC, &intakeMotors, &lb};
//     int ports[] = {11, 12, 13, 18, 19, 20, 4, 3};
//     int index = 0;
//     if (teleControl.ButtonA.pressing())
//     {
//         index++;
//     }
//     if (index > 7)
//     {
//         index = 0;
//     }
                 
//     teleControl.Screen.clearLine(2);
//     teleControl.Screen.clearLine(3);
//     teleControl.Screen.setCursor(2, 1);
//     teleControl.Screen.print("Motor port: %d", ports[index]);
//     teleControl.Screen.print(", temp: %f", motors[index]->temperature(celsius));
//     teleControl.Screen.setCursor(3,1);
//     teleControl.Screen.print("RPM: %f", motors[index]->velocity(velocityUnits::rpm));
        
//     wait(250, msec);  
// }      
    


// void colorStatus(void)
// {


// }

// void clampStatus(void)
// {

// }

// void alert(void)
// {
    
// }