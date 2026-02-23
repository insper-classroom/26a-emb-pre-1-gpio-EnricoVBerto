#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

#define LED_PIN_R      5
#define LED_PIN_ROXO   8
#define LED_PIN_AZUL   11
#define LED_PIN_AMARELO 15

int main(void) {
    stdio_init_all();

    gpio_init(LED_PIN_R);
    gpio_set_dir(LED_PIN_R, GPIO_OUT);

    gpio_init(LED_PIN_ROXO);
    gpio_set_dir(LED_PIN_ROXO, GPIO_OUT);

    gpio_init(LED_PIN_AZUL);
    gpio_set_dir(LED_PIN_AZUL, GPIO_OUT);

    gpio_init(LED_PIN_AMARELO);
    gpio_set_dir(LED_PIN_AMARELO, GPIO_OUT);

    gpio_put(LED_PIN_R, 1);
    gpio_put(LED_PIN_ROXO, 1);
    gpio_put(LED_PIN_AZUL, 1);
    gpio_put(LED_PIN_AMARELO, 1);

    while (true) {
        sleep_ms(100);

        gpio_put(LED_PIN_R, 0);
        gpio_put(LED_PIN_ROXO, 0);
        gpio_put(LED_PIN_AZUL, 0);
        gpio_put(LED_PIN_AMARELO, 0);

        sleep_ms(50);

        gpio_put(LED_PIN_R, 1);
        gpio_put(LED_PIN_ROXO, 1);
        gpio_put(LED_PIN_AZUL, 1);
        gpio_put(LED_PIN_AMARELO, 1);

        sleep_ms(50);
    }
}