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
        neg_3p1_Ladder,
        neg_4r_Ladder,
        neg_3p1_Elim,
        neg_4r_Elim,
        pos_1p1_Ladder,
        pos_2r_Ladder,
        pos_3p1_Elim,
        pos_2r_Elim,
        AllianceStake,
        neg_Route,
        pos_Route,
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