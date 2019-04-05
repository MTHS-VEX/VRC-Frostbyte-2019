#ifndef ROBOT_H
#define ROBOT_H

#include "okapi/api.hpp"
using namespace okapi;

// Controller declarations
extern Controller master;
extern Controller partner;

// Autonomous selector declarations
extern std::string autoList [4];
extern int autoSel;

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
extern Motor leftFront;
extern Motor leftBack;
extern Motor rightFront;
extern Motor rightBack;

// Intake & shooter declarations
extern Motor intake;
extern Motor shooter;

// Drivetrain controller declaration
extern ChassisControllerIntegrated dt;

#endif
