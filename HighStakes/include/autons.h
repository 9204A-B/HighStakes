#ifndef AUTONS_H
#define AUTONS_H

namespace Autons
{
    enum Color
    {
        red,
        blue
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

    class Skills
    {
        public:
            static void run();
    };
}
#endif