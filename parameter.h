#ifndef PARAMETER_H
#define PARAMETER_H
#include <math.h>


int getAllParameterValues (double *a, double *b, double *c, int doInfo);
int getParameterValue (double *var, const char *variableName = nullptr, int doInfo = 1);


#endif
