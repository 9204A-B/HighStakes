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
        pos_1p1_Elim,
        pos_2r_Elim,
        negAllianceStake,
        posAllianceStake,
        neg_Route,
        pos_Route,
        neg_Ladder_End,
        pos_Ladder_End,
        neg_Corner_End,
        pos_Screen_End,
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