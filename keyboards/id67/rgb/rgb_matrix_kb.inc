RGB_MATRIX_EFFECT(ONLY_BOTTOM_PCB_LEDS)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static bool ONLY_BOTTOM_PCB_LEDS(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  RGB current_color = hsv_to_rgb(rgb_matrix_get_hsv());
  for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
    if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
      rgb_matrix_set_color(i, current_color.r, current_color.g, current_color.b);
    }
    else {
      rgb_matrix_set_color(i, 0,0,0);
    }

  }
  return rgb_matrix_check_finished_leds(led_max);
}
#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
