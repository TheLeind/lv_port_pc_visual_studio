#include <Windows.h>
#include <iostream>
#include <LvglWindowsIconResource.h>

#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"
#include "lvgl/src/drivers/windows/lv_windows_display.h"
#include "lvgl/src/drivers/windows/lv_windows_input.h"

#include "home_tab.h"
#include "auton_selector.h"
#include "sharp_logo_good.h"

int screenWidth = 480;
int screenHeight = 240;

void ui_init(void) {
    lv_obj_t* scr_act = lv_scr_act();
    lv_obj_set_style_bg_color(scr_act, lv_color_make(217, 217, 217), LV_PART_MAIN);

    lv_obj_t* tab_view = lv_tabview_create(scr_act);

    lv_obj_t* home_tab = lv_tabview_add_tab(tab_view, "Home");
    lv_obj_t* auton_tab = lv_tabview_add_tab(tab_view, "Auton");
    lv_obj_t* pid_tab = lv_tabview_add_tab(tab_view, "PID Tuning");
    lv_obj_t* temp_tab = lv_tabview_add_tab(tab_view, "Temperature");

    create_home_tab(home_tab);
    create_auto_selector(auton_tab);
}

int main()
{
    lv_init();

    lv_display_t* display = lv_windows_create_display(
        L"LVGL Display",
        screenWidth,
        screenHeight,
        100,
        false,
        true);

    ui_init();

    HWND window_handle = lv_windows_get_display_window_handle(display);
    if (!window_handle)
    {
        return -1;
    }

    HICON icon_handle = LoadIconW(
        GetModuleHandleW(NULL),
        MAKEINTRESOURCE(IDI_LVGL_WINDOWS));
    if (icon_handle)
    {
        SendMessageW(
            window_handle,
            WM_SETICON,
            TRUE,
            (LPARAM)icon_handle);
        SendMessageW(
            window_handle,
            WM_SETICON,
            FALSE,
            (LPARAM)icon_handle);
    }

    lv_indev_t* pointer_indev = lv_windows_acquire_pointer_indev(display);
    lv_indev_t* keypad_indev = lv_windows_acquire_keypad_indev(display);
    lv_indev_t* encoder_indev = lv_windows_acquire_encoder_indev(display);

    while (1)
    {
        uint32_t time_till_next = lv_timer_handler();
        lv_delay_ms(time_till_next);
    }

    return 0;
}
