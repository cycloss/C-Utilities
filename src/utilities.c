#include "utilities.h"
#include <arrayList.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

arrayList* split(char* string, char separator) {
    char* strp = string;
    arrayList* al = createArrayList();
    int len = strlen(string);
    for (int start = 0, i = 0; i <= len; i++) {
        char current = string[i];
        if (current == separator || i == len) {
            int size = i - start;
            char* subStr = malloc(sizeof(char) * size);
            memcpy(subStr, strp, size);
            strp += size + 1;
            start = i + 1;
            appendToAl(al, subStr);
        }
    }
    return al;
}

void timer(int operation) {

    static struct timeval start;

    if (operation == START) {
        gettimeofday(&start, NULL);
    } else if (operation == STOP) {
        struct timeval stop;
        gettimeofday(&stop, NULL);
        float secToMil = ((float)stop.tv_sec - start.tv_sec) * 1000;
        float nanoToMil = ((float)stop.tv_usec - start.tv_usec) / 1000;
        float mils = secToMil + nanoToMil;
        printf("Program took %f seconds, or %f milliseconds, or %lu microseconds\n", mils / 1000, mils, (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec); //usec will loop, 1 mil micro in a second
        start = (struct timeval) {};
    } else {
        printf("Operation: %d is invalid, please use START or STOP\n", operation);
        exit(1);
    }
}