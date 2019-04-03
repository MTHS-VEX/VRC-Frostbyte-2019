#pragma once

#include "main.h"

// Autonomous selector declarations
inline std::string autoList [4] = {
    "Red Flag Side",
    "Red Post Side",
    "Blue Flag Side",
    "Blue Post Side"
};
inline int autoSel = 0;

// Controller definition
inline Controller controller;

// Chassis motor declarations
const int DRIVE_MOTOR_LEFT_1 = 1; //1, 2 = Front, Middle & Back
const int DRIVE_MOTOR_LEFT_2 = 2;
const int DRIVE_MOTOR_RIGHT_1 = 3; //1, 2 = Front, Middle & Back
const int DRIVE_MOTOR_RIGHT_2 = 4;

// Shooter & intake motor declarations
const int INTAKE_MOTOR = 5;
const int SHOOTER_MOTOR = 6;

// Chassis controller declarations
inline const auto WHEEL_DIAMETER = 4.125_in;
inline const auto CHASSIS_WIDTH = 10.6_in;

inline auto chassis = ChassisControllerFactory::create(
    {DRIVE_MOTOR_LEFT_1, DRIVE_MOTOR_LEFT_2},
    {-DRIVE_MOTOR_RIGHT_1, -DRIVE_MOTOR_RIGHT_2},
    AbstractMotor::gearset::green,
    {WHEEL_DIAMETER, CHASSIS_WIDTH}
);

// Shooter & intake declarations
inline Motor intakeMotor(INTAKE_MOTOR, false, AbstractMotor::gearset::green);
inline Motor shooterMotor(SHOOTER_MOTOR, false, AbstractMotor::gearset::red);
