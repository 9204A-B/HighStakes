#ifndef AUTONS_H
#define AUTONS_H

namespace Autons
{
    extern pid piddrive;
    extern pid pidturn;
    
    class LeftSide
    {
        public:
            static void run();
    };

    class RightSide
    {
        public:
            static void run();
    };

    class Skills
    {
        public:
            static void run();
    };
}
#endif