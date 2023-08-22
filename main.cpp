#include "TXLib.h"
#include "solver.h"
#include "constants.h"
#include "defaultFunctions.h"
#include "parameter.h"
#include <stdio.h>


int printResult(int nRoots, double x1, double x2);
void greetings();


int main()
{
    greetings();

    double a = NAN, b = NAN, c = NAN;

    if (getAllParameterValues(&a, &b, &c) != 3)
    {
        printf("Incorrect user input\n");
        return -2;
    }

    double x1 = NAN, x2 = NAN;
    int nRoots = solveSquare(a, b, c, &x1, &x2);
    return printResult(nRoots, x1, x2);
}


int printResult(int nRoots, double x1, double x2)
{
    switch (nRoots)
    {
        case STATUSES::ZERO_SOLUTIONS:
                printf("No solution");
                break;

        case STATUSES::ONE_SOLUTION:
                printf("x1 = %.3lf", x1);
                break;

        case STATUSES::TWO_SOLUTIONS:
                printf("x1 = %.3lf, x2 = %.3lf", x1, x2);
                break;

        case STATUSES::INFINITY_SOLUTIONS:
                printf("Inf solutions");
                break;

        default:
                printf("Error!! Number of roots: %d", nRoots);
                return -1;

    }
    return 0;
}


void greetings()
{
    printf("Program solves equations of this form -> ax**2 + bx + c = 0\n\n");
    printf("This would be probably new line\n\n");
}
