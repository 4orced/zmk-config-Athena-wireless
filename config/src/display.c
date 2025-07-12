```c
#include <zmk/display/status.h>
#include <zmk/log.h>
#include <lvgl.h>
#include "logo.h"

LV_IMG_DECLARE(my_logo_img);

static void render_right(lv_obj_t *parent) {
    LOG_DBG("Rendering RIGHT display...");
    lv_obj_t *img = lv_img_create(parent);
    lv_img_set_src(img, &my_logo_img);
    lv_obj_center(img);
}

static void render_left(lv_obj_t *parent) {
    LOG_DBG("Rendering LEFT display...");
    zmk_display_status_init();
    zmk_display_status_render(parent);
}

int zmk_display_render_status() {
    LOG_DBG("zmk_display_render_status() called");
#if IS_ENABLED(CONFIG_ZMK_DISPLAY_RIGHT)
    render_right(lv_scr_act());
#elif IS_ENABLED(CONFIG_ZMK_DISPLAY_LEFT)
    render_left(lv_scr_act());
#endif
    return 0;
}