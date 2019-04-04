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
inline bool autoRun = false;

// Controller declaration
inline Controller controller;

// Controller button declarations
inline ControllerButton ButtonL1(ControllerDigital::L1);
inline ControllerButton ButtonL2(ControllerDigital::L2);
inline ControllerButton ButtonR1(ControllerDigital::R1);
inline ControllerButton ButtonR2(ControllerDigital::R2);
inline ControllerButton ButtonA(ControllerDigital::A);
inline ControllerButton ButtonB(ControllerDigital::B);
inline ControllerButton ButtonX(ControllerDigital::X);
inline ControllerButton ButtonY(ControllerDigital::Y);
inline ControllerButton ButtonUP(ControllerDigital::up);
inline ControllerButton ButtonDOWN(ControllerDigital::down);
inline ControllerButton ButtonLEFT(ControllerDigital::left);
inline ControllerButton ButtonRIGHT(ControllerDigital::right);

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
