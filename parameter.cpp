#include "parameter.h"
#include "defaultFunctions.h"
#include "constants.h"
#include <stdio.h>


int getAllParameterValues(double *a, double *b, double *c)
{
    int success = 0;

    success += getParameterValue("a", a);
    if (success == 0)
        return 0;

    success += getParameterValue("b", b);
    if (success == 1)
        return 1;

    success += getParameterValue("c", c);
    return success;
}


int getParameterValue(const char *variableName, double *var)
{
    printf("Enter variable %s value: ", variableName);
    int a = '0';
    while ((a = scanf("%lf", var)) == 0 && a != EOF)
    {
        flushUserInput();
    }
    if (a == EOF)
        return 0;
    return 1;
}
