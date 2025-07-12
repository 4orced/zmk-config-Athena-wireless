zephyr_include_directories(config)

target_sources(app PRIVATE
  src/display.c
  src/logo.c
)

zmk_display_render_override(config/src/display.c)
