#include "vex.h"

pid piddrive = pid(leftMotors, rightMotors, 3.25, 1.145, 0.065, 0.15, 2.25);
pid pidturn = pid(Inertial, leftMotors, rightMotors, 3.25, 0.15, 0.0, 0.0, 2.25);