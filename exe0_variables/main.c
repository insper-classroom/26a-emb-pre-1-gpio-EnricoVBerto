#include <stdio.h>

int foo(int *a) {
    *a = *a + 1;
    return *a;
}

int main(void) {
    int a = 0;

    while (1) {
        a = foo(&a);

        if (a > 5) {
            break;
        }
    }

    return 0;
}