#ifndef CALLSMAKER_H
#define CALLSMAKER_H


#include "test.h"
#include "constants.h"
#include <stdio.h>


int callTests();
void callHelp();
void callError (int info);
int printResult (int nRoots, double x1, double x2, int doInfo);
void greetings();


#endif
