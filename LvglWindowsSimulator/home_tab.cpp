#include "lvgl.h"
#include "home_tab.h"
#include "sharp_logo_good.h"
#include <string>

lv_obj_t* selected_auton_label;

void set_auton_string(const char* auton) {
    lv_label_set_text_fmt(selected_auton_label, "Selected Auton: %s", auton);
}

void create_home_tab(lv_obj_t* parent) {
    lv_obj_clear_flag(parent, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t* sharp_img = lv_img_create(parent);
    lv_obj_set_size(sharp_img, 176, 114);
    lv_img_set_zoom(sharp_img, 64);
    lv_img_set_src(sharp_img, &sharp_logo_good);
    lv_obj_align(sharp_img, LV_ALIGN_CENTER, 0, -5);

    selected_auton_label = lv_label_create(parent);
    lv_obj_set_style_text_color(selected_auton_label, lv_color_black(), LV_PART_MAIN);
    set_auton_string("Select an Autonomous Routine!");
    lv_obj_align(selected_auton_label, LV_ALIGN_BOTTOM_MID, 0, 10);
}
