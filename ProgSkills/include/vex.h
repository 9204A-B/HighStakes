#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream> 
#include <algorithm>


#include "v5.h"
#include "v5_vcs.h"
#include "robot-config.h"
#include "methods.h"
#include "JAR-Template/odom.h"
#include "JAR-Template/drive.h"
#include "JAR-Template/util.h"
#include "JAR-Template/PID.h"
#include "autons.h"


#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++);