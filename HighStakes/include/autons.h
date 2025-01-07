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
        ClusterStart,
        soloAWP,
        fourRing_Corner,
        mogoSide_Corner,
        mogoSide_Ladder,
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