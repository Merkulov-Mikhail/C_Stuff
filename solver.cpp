#include "constants.h"
#include "defaultFunctions.h"
#include "parameter.h"
#include "solver.h"


int solveSquare (const double a, const double b, const double c, double *x1, double *x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);


    if (isZero (a))
    {
        // bx + c = 0
        return solveLinear (b, c, x1);
    }

    if (isZero (b))
    {
        // ax**2 + c = 0
        if (isZero (c))
        {
            // ax ** 2 = 0
            *x2 = *x1 = 0;
            return STATUSES::ONE_SOLUTION;
        }
        if (c * a > 0.0)
        {
            return STATUSES::ZERO_SOLUTIONS;
        }
        else
        {
            *x1 = sqrt (-c / a);
            *x2 = -*x1;
            nullifyIfZero (x1);
            nullifyIfZero (x2);
            if (isZero (*x1))
                return STATUSES::ONE_SOLUTION;
            return STATUSES::TWO_SOLUTIONS;
        }
    }
    if (isZero (c))
    {
        // ax**2 + bx = 0
        *x1 = 0;
        *x2 = -b / a;
        nullifyIfZero (x2);
        if (isZero (*x2))
            return STATUSES::ONE_SOLUTION;
        return STATUSES::TWO_SOLUTIONS;
    }
    // ax**2 + bx + c = 0

    double discriminant = b * b - 4.0 * a * c;  // -0.0

    if (isZero (discriminant))
    {
        *x2 = *x1 = -b / 2.0 / a;
        nullifyIfZero (x1);
        return STATUSES::ONE_SOLUTION;
    }
    else if (discriminant < 0.0)
        return STATUSES::ZERO_SOLUTIONS;
    else
    {

        discriminant = sqrt (discriminant);
        *x1 = (-b + discriminant) / 2.0 / a;
        *x2 = (-b - discriminant) / 2.0 / a;
        nullifyIfZero (x1);
        nullifyIfZero (x2);
        if (doubleEquals (*x1, *x2))
            return STATUSES::ONE_SOLUTION;
        return STATUSES::TWO_SOLUTIONS;
    }
}

int solveLinear (const double b, const double c, double *x)
{
    if (isZero (b))
        return (isZero (c)) ? STATUSES::INFINITY_SOLUTIONS : STATUSES::ZERO_SOLUTIONS;

    *x = -c / b;
    nullifyIfZero (x);
    return STATUSES::ONE_SOLUTION;
}
