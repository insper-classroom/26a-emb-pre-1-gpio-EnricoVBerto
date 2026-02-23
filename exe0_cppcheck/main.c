#include <stdio.h>

#define NUM_ELEMENTS 5

int multiplyNumbers(int x, int y) {
    return x * y;
}

int main(void) {
    int a;
    int b = 5;

    if (scanf("%d", &a) != 1) {
        return 1;
    }

    int result = multiplyNumbers(a, b);
    printf("Resultado: %d\n", result);

    int arr[NUM_ELEMENTS];
    int sum = 0;

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        arr[i] = i;
        sum += arr[i];
    }

    printf("Soma: %d\n", sum);

    return 0;
}