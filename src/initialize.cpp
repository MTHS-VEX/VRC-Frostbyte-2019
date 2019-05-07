#include "globals.hpp"

lv_obj_t *redButton;
lv_obj_t *blueButton;
lv_obj_t *skillsButton;

lv_obj_t *autonLabel;

lv_style_t redButtonStyle;
lv_style_t blueButtonStyle;
lv_style_t skillsButtonStyle;

const std::string autonSide[3] = {"Red Side", "Blue Side", "Skills"};


static lv_res_t btn_click_action(lv_obj_t *btn) {
	uint8_t id = lv_obj_get_free_num(btn);
	std::string labelMsg = autonSide[id] + " Selected";

	lv_label_set_text(autonLabel, labelMsg.c_str());
	lv_obj_align(autonLabel, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -40);

	side = id;

	return LV_RES_OK;
}

lv_obj_t *createBtn(
	lv_obj_t *parent,
	lv_align_t align,
	lv_coord_t x_mod,
	lv_coord_t y_mod,
	lv_coord_t width,
	lv_coord_t height,
	uint32_t id
) {
    lv_obj_t *btn = lv_btn_create(parent, NULL);
    lv_obj_set_size(btn, width, height);
	lv_obj_align(btn, NULL, align, x_mod, y_mod);
    lv_obj_set_free_num(btn, id);
	lv_btn_set_action(btn, LV_BTN_ACTION_CLICK, btn_click_action);

    lv_obj_t *label = lv_label_create(btn, NULL);
    lv_label_set_text(label, autonSide[id].c_str());
    lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_MID, 0, 5);

    return btn;
}

void setBtnStyle(lv_style_t *btnStyle, lv_obj_t *btn) {
    lv_btn_set_style(btn, LV_BTN_STYLE_REL, &btnStyle[0]);
    lv_btn_set_style(btn, LV_BTN_STYLE_PR, &btnStyle[1]);
}

lv_style_t *createBtnStyle(
	lv_style_t *copy,
	lv_color_t rel,
	lv_color_t pr,
	lv_color_t textColorRel,
	lv_color_t textColorPr,
	lv_obj_t *btn
) {
    lv_style_t *btnStyle = (lv_style_t *)malloc(sizeof(lv_style_t) *4);

    for(int i = 0; i < 4; i++) lv_style_copy(&btnStyle[i], copy);

    btnStyle[0].body.main_color = rel;
    btnStyle[0].body.grad_color = rel;
    btnStyle[0].text.color = textColorRel;
	btnStyle[0].body.radius = 10;

    btnStyle[1].body.main_color = pr;
    btnStyle[1].body.grad_color = pr;
    btnStyle[1].text.color = textColorPr;
	btnStyle[1].body.radius = 10;

    setBtnStyle(btnStyle, btn);

    return btnStyle;
}


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

	redButton = createBtn(
		lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, 30, 30, 150, 50, 0
	);

	redButtonStyle = *createBtnStyle(
		&lv_style_plain,
		LV_COLOR_RED,
		LV_COLOR_WHITE,
		LV_COLOR_WHITE,
		LV_COLOR_RED,
		redButton
	);

	blueButton = createBtn(
		lv_scr_act(), LV_ALIGN_IN_TOP_RIGHT, -30, 30, 150, 50, 1
	);

	blueButtonStyle = *createBtnStyle(
		&lv_style_plain,
		LV_COLOR_BLUE,
		LV_COLOR_WHITE,
		LV_COLOR_WHITE,
		LV_COLOR_BLUE,
		blueButton
	);


	skillsButton = createBtn(
		lv_scr_act(), LV_ALIGN_CENTER, 0, 10, 150, 50, 2
	);

	skillsButtonStyle = *createBtnStyle(
		&lv_style_plain,
		LV_COLOR_GREEN,
		LV_COLOR_WHITE,
		LV_COLOR_WHITE,
		LV_COLOR_GREEN,
		skillsButton
	);

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
