#include <stdio.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>

static const struct gpio_dt_spec led =
    GPIO_DT_SPEC_GET(DT_NODELABEL(blinking_led), gpios);

void main(void) {
  printf("Blinker v1.0\n");
  if (!device_is_ready(led.port)) {
    return;
  }
  int ret = 0;

  ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
  if (ret != 0) {
    return;
  }

  while (true) {
    printf("loop\n");
    ret = gpio_pin_toggle_dt(&led);
    k_msleep(500);
  }
}