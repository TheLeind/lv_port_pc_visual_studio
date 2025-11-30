#include "lvgl.h"
#include "auton_selector.h"
#include "home_tab.h"
#include "iostream"

lv_obj_t* auton_img;

void update_autonomous(char* auton) {
    // Update selected auton
    set_auton_string(auton);
    selected_auton = auton;

    if (!strcmp(auton, "RedLeft")) { printf("RedLeft\n"); }
    if (!strcmp(auton, "RedRight")) { printf("RedRight\n"); }
    if (!strcmp(auton, "BlueLeft")) { printf("BlueLeft\n"); }
    if (!strcmp(auton, "BlueRight")) { printf("BlueRight\n"); }
}

static void auton_list_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* obj = lv_event_get_target_obj(e);
    if (code == LV_EVENT_VALUE_CHANGED) {
        char option[32];
        lv_dropdown_get_selected_str(obj, option, sizeof(option));
        update_autonomous(option);
    }
}

void create_auto_selector(lv_obj_t* parent) {
    lv_obj_t* auton_list = lv_dropdown_create(parent);
    lv_dropdown_set_options(auton_list, "RedLeft\n"
        "RedRight\n"
        "BlueLeft\n"
        "BlueRight"
    );
    lv_obj_align(auton_list, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_add_event_cb(auton_list, auton_list_event_handler, LV_EVENT_ALL, NULL);

    auton_img = lv_image_create(parent);
    lv_obj_align(auton_img, LV_ALIGN_RIGHT_MID, 0, 0);
}
