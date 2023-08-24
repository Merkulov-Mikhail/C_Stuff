#include "defaultFunctions.h"
#include "constants.h"

void flushUserInput(){
    int p = '0';
    while ( (p = getchar()) != '\n' && p != EOF) {}
}


void nullifyIfZero (double *x){
    if (isZero (*x))
        *x = 0.0;
}


bool isZero (double value)
{
    return doubleEquals (0.0, value);
}


bool doubleEquals (double value1, double value2)
{
    double value = value1 - value2;
    return -PRETTY_LOW < value && value < PRETTY_LOW;
}


bool isErrnoSet(){
    return errno != 0;
}
