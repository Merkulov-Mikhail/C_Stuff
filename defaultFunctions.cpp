#include "defaultFunctions.h"
#include "constants.h"
#include <stdio.h>


void flushUserInput (){
    int p = '0';
    while ( (p = getchar ()) != '\n' && p != EOF) {}
}


bool isZero (double value)
{
    return doubleEquals(0.0, value);
}


bool doubleEquals(double value1, double value2)
{
    int value = value1 - value2;
    return -PRETTY_LOW < value && value < PRETTY_LOW;
}

