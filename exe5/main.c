#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN = 26;
const int BTN_PIN_2 = 7;

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    gpio_init(BTN_PIN_2);
    gpio_set_dir(BTN_PIN_2, GPIO_IN);
    gpio_pull_up(BTN_PIN_2);

    int cnt_1 = 0;
    int cnt_2 = 0;

    int last_1 = 1;
    int last_2 = 1;

    while (true) {
        int now_1 = gpio_get(BTN_PIN);
        int now_2 = gpio_get(BTN_PIN_2);

        if (last_1 == 1 && now_1 == 0) {
            sleep_ms(20);
            if (gpio_get(BTN_PIN) == 0) {
                cnt_1++;
                printf("Botao 1: %d\n", cnt_1);
                while (gpio_get(BTN_PIN) == 0) { }
            }
        }

        if (last_2 == 1 && now_2 == 0) {
            sleep_ms(20);
            if (gpio_get(BTN_PIN_2) == 0) {
                cnt_2++;
                printf("Botao 2: %d\n", cnt_2);
                while (gpio_get(BTN_PIN_2) == 0) { }
            }
        }

        last_1 = now_1;
        last_2 = now_2;

        sleep_ms(1);
    }
}