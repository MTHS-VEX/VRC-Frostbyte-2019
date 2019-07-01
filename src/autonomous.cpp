#include "globals.hpp"

/**
 * Turns robot left or right. This function is used in order to automatically
 * flip the autonomous depending on if the robot is on either the blue or red
 * side, without having to manually recode it.
 */
// void autoTurn(QAngle x) {
//     if (side == 1) {
//         x = -x;
//     }
//     dt.turnAngle(x);
// }

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
// void autonomous() {
//     if (side != 2) {
//         intake.moveVoltage(12000);
//         dt.moveDistance(45_in);
//         pros::Task::delay(500);

//         dt.moveDistance(-8_in);
//         intake.moveVoltage(0);

//         autoTurn(90_deg);
//         dt.moveDistance(40_in);
//     }
//     else {
//         // Insert skills code here
//     }
// }

void autonomous() {
    dt.setMaxVelocity(100);
    intake.moveVoltage(12000);
    dt.moveDistance(45_in);
    pros::Task::delay(500);

    dt.moveDistance(-44_in);
    angle.moveAbsolute(-65, 25);
    pros::Task::delay(250);
    shooter.moveVoltage(12000);
    pros::Task::delay(300);
    shooter.moveVoltage(0);
    
    dt.moveDistance(30_in);
    pros::Task::delay(300);
    dt.moveDistance(-40_in);
}