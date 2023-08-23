#include "TXLib.h"
#include "constants.h"
#include "defaultFunctions.h"
#include "parameter.h"
#include "solver.h"
#include <math.h>


int solveSquare (const double a, const double b, const double c, double *x1, double *x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);


    if (isZero (a))
        return solveLinear (b, c, x1);
    if (isZero (b))
    {
        // ax**2 + c = 0
        if (isZero (c))
        {
            // ax ** 2 = 0
            *x1 = 0;
            return STATUSES::ONE_SOLUTION;
        }
        if (c > 0.0)
        {
            return STATUSES::ZERO_SOLUTIONS;
        }
        else
        {
            *x1 = sqrt(-c);
            *x2 = -*x1;
            return STATUSES::TWO_SOLUTIONS;
        }
    }
    if (isZero(c))
    {
        // ax**2 + bx = 0
        *x1 = 0;
        *x2 = -b / a;
        return STATUSES::TWO_SOLUTIONS;
    }
    // ax**2 + bx + c = 0

    double discriminant = b * b - 4.0 * a * c;

    if (isZero (discriminant))
    {
        *x1 = -b / 2.0 / a;
        return STATUSES::ONE_SOLUTION;
    }
    else if (discriminant < 0.0)
        return STATUSES::ZERO_SOLUTIONS;
    else
    {

        discriminant = sqrt (discriminant);
        *x1 = (-b + discriminant) / 2.0 / a;
        *x2 = (-b - discriminant) / 2.0 / a;
        return STATUSES::TWO_SOLUTIONS;
    }
}

int solveLinear (const double b, const double c, double *x1)
{
    if (isZero (b))
        return (isZero (c)) ? STATUSES::INFINITY_SOLUTIONS : STATUSES::ZERO_SOLUTIONS;

    *x1 = -c / b;
    return STATUSES::ONE_SOLUTION;
}
