#include "main.h"

// Controller definitions
Controller master = ControllerId::master;
Controller partner = ControllerId::partner;

// Autonomous selector definitions
std::string autoList [4] = {
    "Red Flag Side",
    "Red Post Side",
    "Blue Flag Side",
    "Blue Post Side"
};
int autoSel = 0;

// Controller button definitions
ControllerButton ButtonL1(ControllerDigital::L1);
ControllerButton ButtonL2(ControllerDigital::L2);
ControllerButton ButtonR1(ControllerDigital::R1);
ControllerButton ButtonR2(ControllerDigital::R2);
ControllerButton ButtonA(ControllerDigital::A);
ControllerButton ButtonB(ControllerDigital::B);
ControllerButton ButtonX(ControllerDigital::X);
ControllerButton ButtonY(ControllerDigital::Y);
ControllerButton ButtonUP(ControllerDigital::up);
ControllerButton ButtonDOWN(ControllerDigital::down);
ControllerButton ButtonLEFT(ControllerDigital::left);
ControllerButton ButtonRIGHT(ControllerDigital::right);

// Drivetrain motor definitions
Motor leftFront = 1_mtr;
Motor leftBack = 2_mtr;
Motor rightFront = 3_rmtr;
Motor rightBack = 4_rmtr;

// Intake & shooter definitions
Motor intake = 5_mtr;
Motor shooter(6, false, AbstractMotor::gearset::red);

// Drivetrain controller definition
QLength wheelDiameter = 4.125_in;
QLength chassisWidth = 10.6_in;

ChassisControllerIntegrated dt = ChassisControllerFactory::create(
    {leftFront, leftBack},
    {rightFront, rightBack},
    AbstractMotor::gearset::green,
    {wheelDiameter, chassisWidth}
);