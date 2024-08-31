using namespace vex;

#ifndef PID_H
#define PID_H
#define left vex::reverse
#define right vex::forward

/**
 * @brief Use the PID class to make and control PID loops
 */
class pid
{
    private:
        inertial *sensor = 0;
        motor_group *MotorsA = 0;
        motor_group *MotorsB = 0;
        motor *Motor = 0;
        motor *MotorA = 0;
        motor *MotorB = 0;
        double wheelSize;
        double kp;
        double ki;
        double kd;
        double integralThreshold;
        double reset;

    public:
        bool enable = true;
        /**
         * @brief Creates a new PID drivetrain(4M) using the inertial sensor
         * @param sensor The inertial sensor object to use
         * @param MotorsA The first motor group object to use
         * @param MotorsB The second motor group object to use
         * @param wheelSize The diameter of the wheels
         * @param kp The proportion factor to use
         * @param ki The integral factor to use
         * @param kd The derivitive factor to use
         * @param integralThreshold The threshold of the integral
        */
       pid(inertial sensor, motor_group MotorsA, motor_group MotorsB, double wheelSize, double kp, double ki, double kd, double integralThreshold)
       {
            this->sensor = &sensor;
            this->MotorsA = &MotorsA;
            this->MotorsB = &MotorsB;
            this->wheelSize = wheelSize;
            this->kp = kp;
            this->ki = ki;
            this->kd = kd;
            this->integralThreshold = integralThreshold;
       }
        /**
         * @brief Creates a new PID drivetrain(4M) without the inertial sensor
         * @param MotorsA The first motor group object to use
         * @param MotorsB The second motor group object to use
         * @param wheelSize The diameter of the wheels
         * @param kp The proportion factor to use
         * @param ki The integral factor to use
         * @param kd The derivitive factor to use
         * @param integralThreshold The threshold of the integral
        */
       pid(motor_group MotorsA, motor_group MotorsB, double wheelSize, double kp, double ki, double kd, double integralThreshold)
       {
            this->MotorsA = &MotorsA;
            this->MotorsB = &MotorsB;
            this->wheelSize = wheelSize;
            this->kp = kp;
            this->ki = ki;
            this->kd = kd;
            this->integralThreshold = integralThreshold;
       }
       /**
         * @brief Creates a new PID drivetrain(2M) using the inertial sensor
         * @param sensor The inertial sensor object to use
         * @param MotorA The first motor group object to use
         * @param MotorB The second motor group object to use
         * @param wheelSize The diameter of the wheels
         * @param kp The proportion factor to use
         * @param ki The integral factor to use
         * @param kd The derivitive factor to use
         * @param integralThreshold The threshold of the integral
        */
       pid(inertial sensor, motor MotorA, motor MotorB, double wheelSize, double kp, double ki, double kd, double integralThreshold)
       {
            this->sensor = &sensor;
            this->MotorA = &MotorA;
            this->MotorB = &MotorB;
            this->wheelSize = wheelSize;
            this->kp = kp;
            this->ki = ki;
            this->kd = kd;
            this->integralThreshold = integralThreshold;
       }
       /**
         * @brief Creates a new PID drivetrain(2M) without the inertial sensor
         * @param MotorA The first motor group object to use
         * @param MotorB The second motor group object to use
         * @param wheelSize The diameter of the wheels
         * @param kp The proportion factor to use
         * @param ki The integral factor to use
         * @param kd The derivitive factor to use
         * @param integralThreshold The threshold of the integral
        */
       pid(motor MotorA, motor MotorB, double wheelSize, double kp, double ki, double kd, double integralThreshold)
       {
            this->MotorA = &MotorA;
            this->MotorB = &MotorB;
            this->wheelSize = wheelSize;
            this->kp = kp;
            this->ki = ki;
            this->kd = kd;
            this->integralThreshold = integralThreshold;
       }
       /**
         * @brief Creates a new PID object
         * @param Motor The motor object to use
         * @param kp The proportion factor to use
         * @param ki The integral factor to use
         * @param kd The derivitive factor to use
         * @param integralThreshold The threshold of the integral
        */
       pid(motor Motor, double wheelSize, double kp, double ki, double kd, double integralThreshold)
       {
            this->Motor = &Motor;
            this->wheelSize = wheelSize;
            this->kp = kp;
            this->ki = ki;
            this->kd = kd;
            this->integralThreshold = integralThreshold;
       }
       /**
        * @brief Move the motors
        * @param desiredValue Amount to move in the units used for wheelSize
        * @param direction Spin the motors forward or reverse
       */
       void move(double desirvedValue, directionType direction);
       /**
        * @brief Turn the robot
        * @param desiredValue Amount to turn in degrees
        * @param direction Chose whether the robot will turn left or right
       */
       void turn(double desiredValue, directionType direction);
       /**
        * @brief Reset PID positioning
       */
       void Reset();
};
#endif