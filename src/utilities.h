#include <arrayList.h>
#include <stdio.h>
#include <stdlib.h>

#define len(x) sizeof(x) / sizeof(x[0])

void* fatalError(char* formatString, ...);

typedef struct {
    char* string;
    //where the null terminator is currently
    int _nextInd;
    int _currentCapacity;
} stringBuilder;

stringBuilder* createStringBuilder();

/**
 * Copies the string to be appended.
 * Don't forget to free the original string if it was on the heap, as it will not be freed by this function
 */
void appendToBuilder(stringBuilder* sb, char* strToAppend);

void appendCharToBuilder(stringBuilder* sb, char charToAppend);

/**
 * @return the length of the string in the builder not including the null terminator. "Hello" would return 5. 
 */
int getBuilderStringLength(stringBuilder* sb);
void freeBuilder(stringBuilder* sb, bool freeString);
void clearBuilder(stringBuilder* sb);

/**
 * @param string the string to be split, must be null terminated.
 * @param separator the separator to split the string with.
 * @return an array list containing void pointers to the components of the string split by separator.
 * Remember to free the array list and its values with freeAl(arrayList* al, bool freeValues)
 */
arrayList* split(char* string, char separator);

#define START 1
#define STOP 0
void timer(int operation);

void printBinary(int num);
char* toBinaryString(int num);