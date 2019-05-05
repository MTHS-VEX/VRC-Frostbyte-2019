#include "globals.hpp"

lv_obj_t *redButton;
lv_obj_t *redButtonLabel;
lv_obj_t *blueButton;
lv_obj_t *blueButtonLabel;

lv_obj_t *autonLabel;

lv_style_t redButtonStyleREL;
lv_style_t redButtonStylePR;
lv_style_t blueButtonStyleREL;
lv_style_t blueButtonStylePR;

static const char *autonSide[] = {"Red", "Blue"};

static lv_res_t btn_click_action(lv_obj_t * btn) {
	uint8_t id = lv_obj_get_free_num(btn);
	char labelMsg[100];
	char controllerMsg[100];
	sprintf(labelMsg, "%s Side Selected", autonSide[id]);
	sprintf(controllerMsg, "%s Side", autonSide[id]);
	lv_label_set_text(autonLabel, labelMsg);
	side = id;

	return LV_RES_OK;
}



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	lv_style_copy(&redButtonStyleREL, &lv_style_plain);
	redButtonStyleREL.body.radius = 10;
	redButtonStyleREL.text.color = LV_COLOR_RED;

	lv_style_copy(&redButtonStylePR, &lv_style_plain);
	redButtonStylePR.body.main_color = LV_COLOR_RED;
	redButtonStylePR.body.grad_color = LV_COLOR_RED;
	redButtonStylePR.body.radius = 10;
	redButtonStylePR.text.color = LV_COLOR_WHITE;

	lv_style_copy(&blueButtonStyleREL, &lv_style_plain);
	blueButtonStyleREL.body.radius = 10;
	blueButtonStyleREL.text.color = LV_COLOR_BLUE;

	lv_style_copy(&blueButtonStylePR, &lv_style_plain);
	blueButtonStylePR.body.main_color = LV_COLOR_BLUE;
	blueButtonStylePR.body.grad_color = LV_COLOR_BLUE;
	blueButtonStylePR.body.radius = 10;
	blueButtonStylePR.text.color = LV_COLOR_WHITE;

    redButton = lv_btn_create(lv_scr_act(), NULL);
	lv_obj_set_free_num(redButton, 0);
	lv_btn_set_action(redButton, LV_BTN_ACTION_CLICK, btn_click_action);
	lv_btn_set_style(redButton, LV_BTN_STYLE_REL, &redButtonStyleREL);
	lv_btn_set_style(redButton, LV_BTN_STYLE_PR, &redButtonStylePR);
	lv_obj_set_size(redButton, 150, 50);
	lv_obj_align(redButton, NULL, LV_ALIGN_IN_TOP_LEFT, 40, 40);

	redButtonLabel = lv_label_create(redButton, NULL);
	lv_label_set_text(redButtonLabel, "Red");
	
	
	blueButton = lv_btn_create(lv_scr_act(), NULL);
	lv_obj_set_free_num(blueButton, 1);
	lv_btn_set_action(blueButton, LV_BTN_ACTION_CLICK, btn_click_action);
	lv_btn_set_style(blueButton, LV_BTN_STYLE_REL, &blueButtonStyleREL);
	lv_btn_set_style(blueButton, LV_BTN_STYLE_PR, &blueButtonStylePR);
	lv_obj_set_size(blueButton, 150, 50);
	lv_obj_align(blueButton, NULL, LV_ALIGN_IN_TOP_RIGHT, -40, 40);

	blueButtonLabel = lv_label_create(blueButton, NULL);
	lv_label_set_text(blueButtonLabel, "Blue");

	autonLabel = lv_label_create(lv_scr_act(), NULL);
	lv_label_set_text(autonLabel, "Select Autonomous");
	
	lv_obj_align(autonLabel, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -40);
}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
