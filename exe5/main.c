#include <stdio.h>
#include <stdbool.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BTN_PIN_1 26
#define BTN_PIN_2 7

int main(void) {
    stdio_init_all();

    gpio_init(BTN_PIN_1);
    gpio_set_dir(BTN_PIN_1, GPIO_IN);
    gpio_pull_up(BTN_PIN_1);

    gpio_init(BTN_PIN_2);
    gpio_set_dir(BTN_PIN_2, GPIO_IN);
    gpio_pull_up(BTN_PIN_2);

    int cnt_1 = 0;
    int cnt_2 = 0;

    bool last_1 = true;
    bool last_2 = true;

    while (true) {
        bool now_1 = gpio_get(BTN_PIN_1);
        bool now_2 = gpio_get(BTN_PIN_2);

        if (last_1 && !now_1) {
            sleep_ms(20);
            if (!gpio_get(BTN_PIN_1)) {
                cnt_1++;
                printf("Botao 1: %d\n", cnt_1);
                while (!gpio_get(BTN_PIN_1)) { }
            }
        }

        if (last_2 && !now_2) {
            sleep_ms(20);
            if (!gpio_get(BTN_PIN_2)) {
                cnt_2++;
                printf("Botao 2: %d\n", cnt_2);
                while (!gpio_get(BTN_PIN_2)) { }
            }
        }

        last_1 = now_1;
        last_2 = now_2;

        sleep_ms(1);
    }
}