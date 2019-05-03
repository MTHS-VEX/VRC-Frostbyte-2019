#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "main.h"

// Chassis motor ports
const int LEFT_MOTOR_FRONT = 1;
const int LEFT_MOTOR_BACK = 2;
const int RIGHT_MOTOR_FRONT = 3;
const int RIGHT_MOTOR_BACK = 4;

// Intake & shooter motor ports
const int INTAKE_MOTOR = 5;
const int SHOOTER_MOTOR = 6;

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

// Drivetrain controller declaration
extern QLength wheelDiameter;
extern QLength chassisWidth;

extern ChassisControllerIntegrated dt;

#endif
