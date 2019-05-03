#include "globals.hpp"

// Controller definitions
Controller master = ControllerId::master;
Controller partner = ControllerId::partner;

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
Motor dtLeftFront(LEFT_MOTOR_FRONT, false, AbstractMotor::gearset::green);
Motor dtLeftBack(LEFT_MOTOR_BACK, false, AbstractMotor::gearset::green);
Motor dtRightFront(RIGHT_MOTOR_FRONT, true, AbstractMotor::gearset::green);
Motor dtRightBack(RIGHT_MOTOR_BACK, true, AbstractMotor::gearset::green);

// Intake & shooter definitions
Motor intake(INTAKE_MOTOR, false, AbstractMotor::gearset::green);
Motor shooter(SHOOTER_MOTOR, false, AbstractMotor::gearset::red);

// Drivetrain controller definition
QLength wheelDiameter = 4.125_in;
QLength chassisWidth = 10.6_in;

ChassisControllerIntegrated dt = ChassisControllerFactory::create(
    {dtLeftFront, dtLeftBack},
    {dtRightFront, dtRightBack},
    AbstractMotor::gearset::green,
    {wheelDiameter, chassisWidth}
);