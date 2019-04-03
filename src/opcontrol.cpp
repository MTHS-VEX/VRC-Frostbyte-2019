#include "main.h"

// Improved controller button names
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

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    while (true) {
        // Tank control for chasssis
        chassis.tank(
            controller.getAnalog(ControllerAnalog::leftY),
            controller.getAnalog(ControllerAnalog::rightY)
        );

        // Intake control
        if (ButtonL1.isPressed()) {
            intakeMotor.moveVoltage(12000);
        }
        else if (ButtonL2.isPressed()) {
            intakeMotor.moveVoltage(-12000);
        }
        else {
            intakeMotor.moveVoltage(0);
        }

        // Shooter control
        if (ButtonR2.isPressed()) {
            shooterMotor.moveVoltage(12000);
        }
        else {
            shooterMotor.moveVoltage(0);
        }

        pros::Task::delay(10);
    }
}
