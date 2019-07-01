#include "globals.hpp"

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
    bool anglePos = 1;
    while (true) {
        // Tank control for drivetrain
        dt.tank(
            master.getAnalog(ControllerAnalog::leftY),
            master.getAnalog(ControllerAnalog::rightY)
        );

        angle.setBrakeMode(AbstractMotor::brakeMode::hold);
        // Intake control
        if (ButtonL1.isPressed()) {
            intake.moveVoltage(12000);
        }
        else if (ButtonL2.isPressed()) {
            intake.moveVoltage(-12000);
        }
        else {
            intake.moveVoltage(0);
        }

        // Shooter control
        if (ButtonR2.isPressed()) {
            shooter.moveVoltage(12000);
        }
        else {
            shooter.moveVoltage(0);
        }
        
        // Angle control
        if (ButtonR1.changedToPressed()) {
            angle.moveAbsolute(anglePos ? -65 : 0, 25);
            anglePos = !anglePos;
        }

        pros::Task::delay(10);
    }
}
