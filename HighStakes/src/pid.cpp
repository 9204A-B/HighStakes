#include "vex.h"
#include <math.h>

using namespace vex;

    void pid::move(double desiredValue, directionType direction)
    {
        double position = 0.0;
        double previousPosition = 0.0;
        double time = Brain.timer(msec);
        double previousTime = 0.0;
        double error = 0.0;
        double previousError = 0.0;
        double derivitive = 0.0;
        double integral = 0.0;
        
        while (enable)
        {
            if (MotorsA != NULL)
            {
                position = ((MotorsA->position(degrees) + MotorsB->position(degrees)) / 2.0) / 360.0 * wheelSize * M_PI;
            }
            else if (MotorA != NULL)
            {
                position = ((MotorA->position(degrees) + MotorB->position(degrees)) / 2.0) / 360.0 * wheelSize * M_PI;
            }
            else if (Motor != NULL)
            {
                position = Motor->position(degrees);
            }
            else
            {
                return;
            }

            if (reset)
            {
                if (MotorsA != NULL)
                {
                    MotorsA->setPosition(0, degrees);
                    MotorsB->setPosition(0, degrees);
                }
                else if (MotorA != NULL)
                {
                    MotorA->setPosition(0, degrees);
                    MotorB->setPosition(0, degrees);
                }
                else 
                {
                    Motor->setPosition(0, degrees);
                }
                reset = false;
                position = 0.0;
            }

            error = desiredValue - position;

            if (fabs(error) < integralThreshold)
            {
                integral += error;
            }
            else
            {
                integral = 0.0;
            }

            //Prevent dividing by 0
            if (time == previousTime)
            {
                derivitive = 0.0;
            }
            else
            {
                derivitive = (error - previousError) / (time - previousTime);
            }
            previousTime = time;

            double driveMotorPower = kp * error + ki * integral + kd * derivitive;

            if (MotorsA != NULL)
            {
                MotorsA->spin(direction, driveMotorPower, volt);
                MotorsB->spin(direction, driveMotorPower, volt);
            }
            else if (MotorA != NULL)
            {
                MotorA->spin(direction, driveMotorPower, volt);
                MotorB->spin(direction, driveMotorPower, volt);
            }
            else
            {
                Motor->spin(direction, driveMotorPower, volt);
            }

            if (fabs(position) >= fabs(desiredValue))
            {
                enable = false;

                if (MotorsA != NULL)
                {
                    MotorsA->stop();
                    MotorsB->stop();
                }
                else if (MotorA != NULL)
                {
                    MotorA->stop();
                    MotorB->stop();
                }
                else
                {
                    Motor->stop();
                }
            }

            wait(15, msec);
        }
    }
    
    void pid::turn(double desiredValue, directionType direction)
    {
        double rotation = 0.0;
        double time = Brain.timer(msec);
        double previousTime = 0.0;
        double error = 0.0;
        double previousError = 0.0;
        double derivitive = 0.0;
        double integral = 0.0;

        while (enable)
        {
            if (sensor != NULL)
            {
                while (Inertial.isCalibrating())
                {
                    wait(150, msec);
                }
                rotation = Inertial.rotation(degrees);    
            }
            else if (MotorsA != NULL)
            {
                rotation = (MotorsA->position(degrees) + MotorsB->position(degrees)) / 2.0;
            }
            else if (MotorA != NULL)
            {
                rotation = (MotorA->position(degrees) + MotorB->position(degrees)) / 2.0;
            }
            else
            {
                return;
            }

            if (reset)
            {
                if (sensor != NULL)
                {
                    sensor->calibrate(0);
                }
                
                if (MotorsA != NULL)
                {
                    MotorsA->setPosition(0, degrees);
                    MotorsB->setPosition(0, degrees);
                }
                else
                {
                    MotorA->setPosition(0, degrees);
                    MotorB->setPosition(0, degrees);
                }

                reset = false;
                rotation = 0.0;
            }

            error = desiredValue - rotation;
            if (fabs(error) < integralThreshold)
            {
                integral += error;
            }
            else
            {
                integral = 0.0;
            }

            if (time == previousTime)
            {
                derivitive = 0.0;
            }
            else 
            {
                derivitive = (error - previousError) / (time - previousTime);
            }

            previousTime = time;

            double driveMotorPower = kp * error + ki * integral + kd * derivitive;
            if (MotorsA != NULL)
            {
                MotorsA->spin(direction, driveMotorPower, volt);
                MotorsB->spin(direction, -1 * driveMotorPower, volt);                
            }
            else
            {
                MotorA->spin(direction, driveMotorPower, volt);
                MotorB->spin(direction, -1 * driveMotorPower, volt);                
            }

            if (fabs(rotation) >= fabs(desiredValue))
            {
                enable = false;

                if (MotorsA != NULL)
                {
                    MotorsA->stop();
                    MotorsB->stop();
                }
                else
                {
                    MotorA->stop();
                    MotorB->stop();
                }
            }

            wait(10, msec);
        }
    }

    void pid::Reset()
    {
        reset = true;
    }