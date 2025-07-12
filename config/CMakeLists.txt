zephyr_include_directories(config)

target_sources(app PRIVATE
  src/logo.c
  src/display.c
)

set(ZMK_DISPLAY_RENDER_OVERRIDE TRUE)
