#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "main.h"

extern int side;

// Chassis motor ports
const int LEFT_MOTOR_FRONT = 17;
const int LEFT_MOTOR_BACK = 14;
const int RIGHT_MOTOR_FRONT = 16;
const int RIGHT_MOTOR_BACK = 12;

// Intake & shooter motor ports
const int INTAKE_MOTOR = 10;
const int SHOOTER_MOTOR = 1;
const int ANGLE_MOTOR = 3;

// Controller declarations
extern Controller master;
extern Controller partner;

// Controller button declarations
extern ControllerButton ButtonL1;
extern ControllerButton ButtonL2;
extern ControllerButton ButtonR1;
extern ControllerButton ButtonR2;
extern ControllerButton ButtonA;
extern ControllerButton ButtonB;
extern ControllerButton ButtonX;
extern ControllerButton ButtonY;
extern ControllerButton ButtonUP;
extern ControllerButton ButtonDOWN;
extern ControllerButton ButtonLEFT;
extern ControllerButton ButtonRIGHT;

// Drivetrain motor declarations
extern Motor dtLeftFront;
extern Motor dtLeftBack;
extern Motor dtRightFront;
extern Motor dtRIghtBack;

// Intake & shooter declarations
extern Motor intake;
extern Motor shooter;
extern Motor angle;

// Drivetrain controller declaration
extern QLength wheelDiameter;
extern QLength chassisWidth;

extern ChassisControllerIntegrated dt;

#endif
