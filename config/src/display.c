#include <zmk/display/status.h>
#include <lvgl.h>
#include "logo.h"

LV_IMG_DECLARE(my_logo_img); // Defined in logo.c

// Right-side: show logo
static void render_right(lv_obj_t *parent) {
    lv_obj_t *img = lv_img_create(parent);
    lv_img_set_src(img, &my_logo_img);
    lv_obj_center(img);
}

// Left-side: show battery + WPM
static void render_left(lv_obj_t *parent) {
    zmk_display_status_init();
    zmk_display_status_render(parent);
}

// ZMK render hook
int zmk_display_render_status() {
#if IS_ENABLED(CONFIG_ZMK_DISPLAY_RIGHT)
    render_right(lv_scr_act());
#elif IS_ENABLED(CONFIG_ZMK_DISPLAY_LEFT)
    render_left(lv_scr_act());
#endif
    return 0;
}
