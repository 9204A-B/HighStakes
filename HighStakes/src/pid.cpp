#include "vex.h"

using namespace vex;

double kp = 0.25;
double ki = 0.000000005;
double kd = 0.22;
double integral = 0.0;

double turnKp = 0.25;
double turnKi = 0.000000005;
double turnKd = 0.22;
double turnIntegral = 0.0;

double integralThreshold = 10.0;

bool PIDenable = true;
bool resetSensor = false;

void PIDdrive(int desiredValue, int desiredTurnValue)
{
    int error;
    int previousError = 0;
    int derivitive;

    int turnError;
    int turnPreviousError = 0;
    int turnDerivitive;

    PIDenable = true;
    resetSensor = true;

    while (PIDenable)
    {
        if (resetSensor)
        {
          //Inertial.calibrate(0);
            resetSensor = false;
            leftMotors.setPosition(0, degrees);
            rightMotors.setPosition(0, degrees);
        }
      //int position = Inertial.gyroRate(xaxis, dps);
        int leftPosition = leftMotors.position(degrees);
        int rightPosition = rightMotors.position(degrees);
        int averagePosition = (leftPosition + rightPosition) / 2;

        previousError = error;
        error = desiredValue - averagePosition;
      //error = desiredVaule - position;
        
        if (abs(error) < integralThreshold)
        {
            integral += error;
        }
        else
        {
            integral = 0;
        }

        derivitive = error - previousError;

        double driveMotorPower = kp * error + ki * integral + kd * derivitive;
      //int turnDifference = Inertial.rotation(degrees);
        int turnDifference = leftPosition - rightPosition;

        turnPreviousError = turnError;
        turnError = desiredTurnValue - turnDifference;

        if (abs(turnError) < integralThreshold)
        {
            turnIntegral += turnError;
        }
        else
        {
            turnIntegral = 0;
        }

        turnDerivitive = turnError - turnPreviousError;

        double turnMotorPower = turnKp * turnError + turnKi * turnIntegral + turnKd * turnDerivitive;

        leftMotors.spin(forward, (driveMotorPower + turnMotorPower), volt);
        rightMotors.spin(forward, (driveMotorPower - turnMotorPower), volt);

        if (averagePosition >= desiredValue && averagePosition >= desiredTurnValue)
        {
            PIDenable = false;
        }
    
        wait(15, msec);
    }
}