#include "../src/utilities.h"

#include <stdio.h>

void strPrinter(void* str) {
    printf("|%s|\n", (char*)str);
}

int main() {

    timer(START);

    int res = 0;

    for (int i = 0; i < 2000000; i++) {
        res += i;
    }
    printf("%i\n", res);
    timer(STOP);

    char* str = "Hello world foo  bar";

    arrayList* al = split(str, ' ');
    iterateListItems(al, strPrinter);
    freeAl(al, true);
}