#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>
const int BTN_PIN_G = 26;
const int BTN_PIN_R=28;
const int LED_PIN_G = 6;
const int LED_PIN_R = 4;

int main() {
  stdio_init_all();
  gpio_init(BTN_PIN_G);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);
  gpio_pull_up(BTN_PIN_G);

  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R  , GPIO_IN);
  gpio_pull_up(BTN_PIN_R);

  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);
  gpio_put(LED_PIN_G, 0);

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_put(LED_PIN_R, 0);

  while (true) {
    if (!gpio_get(BTN_PIN_G)) {
      gpio_put(LED_PIN_G, !gpio_get(LED_PIN_G));
      while (!gpio_get(BTN_PIN_G)) {
      };
    }
    if (!gpio_get(BTN_PIN_R)) {
      gpio_put(LED_PIN_R, !gpio_get(LED_PIN_R));
      while (!gpio_get(BTN_PIN_R)) {
      };
    }
  }
}
