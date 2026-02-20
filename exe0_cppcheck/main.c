#include <stdio.h>
#include <stdlib.h>

#define NUM_ELEMENTS 5

int multiplyNumbers(int x, int y) {
    int product = x * y;
    return product;
}

int main(void) {
    int a;
    int b = 5;
    scanf("%d", &a);
    int result = multiplyNumbers(a, b);
    printf("Resultado: %d\n", result);

    int arr[NUM_ELEMENTS];
    for(int i = 0; i < NUM_ELEMENTS; i++) { 
        arr[i] = i;
    }

    return 0;
}
