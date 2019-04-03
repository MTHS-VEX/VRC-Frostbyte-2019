#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    intakeMotor.moveVoltage(12000);
    chassis.moveDistance(45_in);
    pros::Task::delay(500);

    chassis.moveDistance(-8_in);
    intakeMotor.moveVoltage(0);

    chassis.turnAngle(90_deg);
    chassis.moveDistance(40_in);
}
