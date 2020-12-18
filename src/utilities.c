#include "utilities.h"
#include <arrayList.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define SB_INITIAL_SIZE 10
#define SB_GROWTH_FACTOR 2

stringBuilder* createStringBuilder() {
    stringBuilder* sb = malloc(sizeof(stringBuilder));
    char* baseStr = malloc(sizeof(char) * SB_INITIAL_SIZE);
    baseStr[0] = '\0';
    *sb = (stringBuilder) { baseStr, 0, SB_INITIAL_SIZE };
    return sb;
}

void appendToBuilder(stringBuilder* sb, char* strToAppend) {
    int strLen = strlen(strToAppend) + 1;
    while (sb->_nextInd + strLen > sb->_currentCapacity) {
        int newCap = sb->_currentCapacity * SB_GROWTH_FACTOR;
        // printf("Expanding capacity from %i to %i\n", sb->_currentCapacity, newCap);
        sb->string = realloc(sb->string, sizeof(char) * newCap);
        sb->_currentCapacity = newCap;
    }
    memcpy(sb->string + sb->_nextInd, strToAppend, strLen);
    //-1 as want to put next string where the null terminator is
    sb->_nextInd += strLen - 1;
}

int getBuilderStringLength(stringBuilder* sb) {
    return sb->_nextInd;
}

void freeBuilder(stringBuilder* sb) {
    free(sb->string);
    free(sb);
}

void clearBuilder(stringBuilder* sb) {
    free(sb->string);
    char* baseStr = malloc(sizeof(char) * SB_INITIAL_SIZE);
    baseStr[0] = '\0';
    *sb = (stringBuilder) { baseStr, 0, SB_INITIAL_SIZE };
}

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
    static bool started = false;

    if (operation == START) {
        gettimeofday(&start, NULL);
        started = true;
    } else if (operation == STOP) {
        if (!started) {
            puts("Timer not started");
            return;
        }
        struct timeval stop;
        gettimeofday(&stop, NULL);
        float secToMil = ((float)stop.tv_sec - start.tv_sec) * 1000;
        float nanoToMil = ((float)stop.tv_usec - start.tv_usec) / 1000;
        float mils = secToMil + nanoToMil;
        printf("Program took %f seconds, or %f milliseconds, or %lu microseconds\n", mils / 1000, mils, (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec); //usec will loop, 1 mil micro in a second
        started = false;
    } else {
        printf("Timer operation: %d is invalid, please use START or STOP\n", operation);
        exit(1);
    }
}