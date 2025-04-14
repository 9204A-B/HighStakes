#include "vex.h"
enum Side
{
    LEFT,
    RIGHT
};

void setDriveExpo(vex::directionType direction, float percent, Side side);