#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const uint BTN_PIN_R = 28;
const uint LED_PIN_R = 5;
const uint LED_PIN_ROXO = 8;
const uint LED_PIN_AZUL = 11;
const uint LED_PIN_AMARELO = 15;

int main() {
  stdio_init_all();
  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_pull_up(BTN_PIN_R);
  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);  
  gpio_init(LED_PIN_ROXO);
  gpio_set_dir(LED_PIN_ROXO, GPIO_OUT);
  gpio_init(LED_PIN_AZUL);
  gpio_set_dir(LED_PIN_AZUL, GPIO_OUT);
  gpio_init(LED_PIN_AMARELO);
  gpio_set_dir(LED_PIN_AMARELO, GPIO_OUT);
  
  while (true) {
if (!gpio_get(BTN_PIN_R)) {
  gpio_put(LED_PIN_R, 1);
  sleep_ms(300);
  gpio_put(LED_PIN_ROXO, 1);
  sleep_ms(300);
  gpio_put(LED_PIN_AZUL, 1);
  sleep_ms(300);
  gpio_put(LED_PIN_AMARELO, 1);
  sleep_ms(300);
  gpio_put(LED_PIN_R, 0);
  sleep_ms(300);
  gpio_put(LED_PIN_ROXO, 0);
  sleep_ms(300);
  gpio_put(LED_PIN_AZUL, 0);
  sleep_ms(300);
  gpio_put(LED_PIN_AMARELO, 0);
}
    
  }
}
