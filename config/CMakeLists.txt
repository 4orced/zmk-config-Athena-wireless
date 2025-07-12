zephyr_include_directories(config)

target_sources(app PRIVATE
  src/logo.c
  src/display.c
)

# VERY IMPORTANT: Override ZMK's built-in renderer
set(CONF_FILE "prj.conf")
set(ZMK_DISPLAY_RENDER_OVERRIDE TRUE)
