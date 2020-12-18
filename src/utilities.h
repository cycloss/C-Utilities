#include <arrayList.h>

#define START 1
#define STOP 0
void timer(int operation);

/**
 * @param string the string to be split, must be null terminated.
 * @param separator the separator to split the string with.
 * @return an array list containing void pointers to the components of the string split by separator.
 * Remember to free the array list and its values with freeAl(arrayList* al, bool freeValues)
 */
arrayList* split(char* string, char separator);