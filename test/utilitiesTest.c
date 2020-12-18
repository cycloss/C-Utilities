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

    stringBuilder* sb = createStringBuilder();
    appendToBuilder(sb, "Hello");
    appendToBuilder(sb, "World");

    puts(sb->string);
    int builderLen = getBuilderStringLength(sb);
    printf("Builder length (not including null terminator): %i\n", builderLen);
    printf("Last char of builder: %c\n", sb->string[builderLen - 1]);

    clearBuilder(sb);
    appendToBuilder(sb, "Foo");
    appendToBuilder(sb, "Bar");
    puts(sb->string);
    freeBuilder(sb);
}