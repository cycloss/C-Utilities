#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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
        // printf("took %lu seconds or %lu microseconds\n", stop.tv_sec - start.tv_sec, (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec); //usec will loop, 1 mil micro in a second
        start = (struct timeval) {};
    } else {
        printf("Operation: %d is invalid, please use START or STOP\n", operation);
        exit(1);
    }
}