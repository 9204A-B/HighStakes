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
        4ringmogo_corner,
        4ringmogo_ladder
    };

    class LeftSide
    {
    public:
        static void run(Autons::Color Color);
    };

    class RightSide
    {
    public:
        static void run(Autons::Color Color);
    };

    class RedAlliance
    {
    public:
        static void run(Autons::Route Route);
    }

    class Skills
    {
    public:
        static void run();
    };
}
#endif