#include "defaultFunctions.h"
#include "constants.h"
#include <stdio.h>


void flushUserInput(){
    int p = '0';
    while ((p = getchar()) != '\n' && p != EOF) {}
}


bool isZero(double value)
{
    return value < PRETTY_LOW && value > -PRETTY_LOW;
}
