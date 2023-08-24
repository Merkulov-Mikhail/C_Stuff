#ifndef DEFAULT_FUNCTIONS_H
#define DEFAULT_FUNCTIONS_H

#include <stdio.h>
#include <cerrno>

void flushUserInput();
void nullifyIfZero (double *x);
bool isZero (double value);
bool doubleEquals (double value1, double value2);
bool isErrnoSet();

#endif
