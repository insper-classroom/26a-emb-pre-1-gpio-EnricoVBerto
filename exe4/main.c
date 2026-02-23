#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdio.h>

const uint LED_PIN_R = 5;
const uint LED_PIN_ROXO = 8;
const uint LED_PIN_AZUL = 11;
const uint LED_PIN_AMARELO = 15;

int main(void) {
    stdio_init_all();

    gpio_init(LED_PIN_R);
    gpio_set_dir(LED_PIN_R, GPIO_OUT);
    gpio_put(LED_PIN_R, 0);

    gpio_init(LED_PIN_ROXO);
    gpio_set_dir(LED_PIN_ROXO, GPIO_OUT);
    gpio_put(LED_PIN_ROXO, 0);

    gpio_init(LED_PIN_AZUL);
    gpio_set_dir(LED_PIN_AZUL, GPIO_OUT);
    gpio_put(LED_PIN_AZUL, 0);

    gpio_init(LED_PIN_AMARELO);
    gpio_set_dir(LED_PIN_AMARELO, GPIO_OUT);
    gpio_put(LED_PIN_AMARELO, 0);

    sleep_ms(150);

    while (true) {
        gpio_put(LED_PIN_R, 1);
        gpio_put(LED_PIN_ROXO, 1);
        gpio_put(LED_PIN_AZUL, 1);
        gpio_put(LED_PIN_AMARELO, 1);

        sleep_ms(60);

        gpio_put(LED_PIN_R, 0);
        gpio_put(LED_PIN_ROXO, 0);
        gpio_put(LED_PIN_AZUL, 0);
        gpio_put(LED_PIN_AMARELO, 0);

        sleep_ms(60);
    }
}