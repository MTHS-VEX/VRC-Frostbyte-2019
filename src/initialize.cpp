#include "globals.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
    master.clear();
    master.setText(1, 0, "Robot Disabled");
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {/*
    master.clear();
    master.setText(0, 0, "Select Auton");
    master.setText(2, 0, "A to Confirm");

    // Autonomous selector
    while (!ButtonA.changedToPressed()) { // A = Confirm Button
        if (ButtonRIGHT.changedToPressed()) {
            autoSel++;
            if (autoSel>3) {
                autoSel = 0;
            }
            master.clearLine(1);
            master.setText(1, 0, autoList[autoSel]);
        }
        else if (ButtonLEFT.changedToPressed()) {
            autoSel--;
            if (autoSel<0) {
                autoSel = 3;
            }
            master.clearLine(1);
            master.setText(1, 0, autoList[autoSel]);
        }
    }

    master.clear();
    master.setText(0, 0, "Auton Selected");
    master.setText(1, 0, autoList[autoSel]);*/
}
