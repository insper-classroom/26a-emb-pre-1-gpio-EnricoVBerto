#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const uint BTN_PIN_G = 26;
const uint BTN_PIN_R = 28;
const uint LED_PIN_G = 6;
const uint LED_PIN_R = 4;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN_G);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);
  gpio_pull_up(BTN_PIN_G);

  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_pull_up(BTN_PIN_R);

  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  bool led_g = false;
  bool led_r = false;

  gpio_put(LED_PIN_G, led_g);
  gpio_put(LED_PIN_R, led_r);

  while (true) {
    if (gpio_get(BTN_PIN_G) == 0) {
      sleep_ms(15); 
      if (gpio_get(BTN_PIN_G) == 0) { 
        led_g = !led_g;
        gpio_put(LED_PIN_G, led_g);

        while (gpio_get(BTN_PIN_G) == 0) {
          tight_loop_contents(); 
        }
      }
    }

    if (gpio_get(BTN_PIN_R) == 0) {
      sleep_ms(15); 
      if (gpio_get(BTN_PIN_R) == 0) {
        led_r = !led_r;
        gpio_put(LED_PIN_R, led_r);

        while (gpio_get(BTN_PIN_R) == 0) {
          tight_loop_contents();
        }
      }
    }
  }
}