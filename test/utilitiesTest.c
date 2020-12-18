#include "../src/utilities.h"
#include <stdio.h>

int main() {

    timer(START);

    int res = 0;

    for (int i = 0; i < 2000000; i++) {
        res += i;
    }
    printf("%i\n", res);
    timer(STOP);
}