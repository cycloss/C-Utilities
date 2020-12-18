#include <arrayList.h>

typedef struct {
    char* string;
    //where the null terminator is currently
    int _nextInd;
    int _currentCapacity;
} stringBuilder;

stringBuilder* createStringBuilder();

/**
 * Copies the string to be appended (don't forget to free the original string if it was on the heap)
 */
void appendToBuilder(stringBuilder* sb, char* strToAppend);

/**
 * @return the length of the string in the builder not including the null terminator. "Hello" would return 5. 
 */
int getBuilderStringLength(stringBuilder* sb);
void freeBuilder(stringBuilder* sb);
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
