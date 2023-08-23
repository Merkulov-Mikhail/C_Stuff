#include "parameter.h"
#include "defaultFunctions.h"
#include "constants.h"
#include <stdio.h>


int getAllParameterValues (double *a, double *b, double *c, int doInfo)
{
    int success = 0;

    success += getParameterValue (a, "a", doInfo);
    if (success == 0)
        return 0;

    success += getParameterValue (b, "b", doInfo);
    if (success == 1)
        return 1;

    success += getParameterValue (c, "c", doInfo);
    return success;
}


int getParameterValue (double *var, const char *variableName, int doInfo)
{
    if (doInfo){
        if (variableName)
            printf ("Enter variable %s value: ", variableName);
        else
            printf ("Enter variable value: ");
    }
    int nParams = '0';

    while ( (nParams = scanf ("%lf", var)) == 0 && nParams != EOF)
    {
        flushUserInput();
    }

    if (nParams == EOF)
        return 0;

    return 1;
}
