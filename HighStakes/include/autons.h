#ifndef AUTONS_H
#define AUTONS_H

#include "JAR-Template/drive.h"

class Drive;

extern Drive pidDrivetrain;
void default_constants();

namespace Autons
{
    enum Color
    {
        red,
        blue
    };

    enum Route
    {
        fourRingMogo_Corner,
        fourRingMogo_Ladder,
        mogoSide_Corner,
        mogoSide_Ladder,
        mogoSide_GoalRush_Corner,
        mogoSide_GoalRush_Ladder,
        test
    };

    class RedAlliance
    {
    public:
        static void run(Autons::Route Route);
    };

    class BlueAlliance
    {
    public:
        static void run(Autons::Route Route);
    };

    class Skills
    {
    public:
        static void run();
    };
}
#endif