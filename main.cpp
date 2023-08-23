#include "TXLib.h"
#include "solver.h"
#include "constants.h"
#include "defaultFunctions.h"
#include "argumentParser.h"
#include "parameter.h"
#include "test.h"
#include <stdlib.h>
#include <stdio.h>


int printResult (int nRoots, double x1, double x2, int doInfo);
void greetings();


int main (int argc, char *argv[])
{
    int info = 1, have_args = 0, tests = 0;
    char *arguments[3] = {};

    parseArguments (argc, argv, &info, &have_args, &tests, arguments);

    if (tests){
        int failedTests = TestAll();
        if (failedTests)
        {
            printf("TESTS FAILED: %d\n", failedTests);
            return -3;
        }
    }

    if (info)
    {
        greetings();
    }

    double a = NAN, b = NAN, c = NAN;
    if (!have_args){
        if (getAllParameterValues (&a, &b, &c, info) != 3)
        {
            printf  ("Incorrect user input\n");
            return -2;
        }
    }
    else
    {
        a = atof (arguments[0]);
        b = atof (arguments[1]);
        c = atof (arguments[2]);
    }
    double x1 = NAN, x2 = NAN;
    int nRoots = solveSquare (a, b, c, &x1, &x2);
    return printResult (nRoots, x1, x2, info);
}


int printResult (int nRoots, double x1, double x2, int doInfo)
{
    switch (nRoots)
    {
        case STATUSES::ZERO_SOLUTIONS:
                if (doInfo)
                {
                    printf ("No solution");
                }
                else
                {
                    printf ("0");
                }
                break;

        case STATUSES::ONE_SOLUTION:
                if (doInfo)
                {
                    printf ("x1 = %.3lf", x1);
                }
                else
                {
                    printf ("%.3lf", x1);
                }
                break;

        case STATUSES::TWO_SOLUTIONS:
                if (doInfo)
                {
                    printf ("x1 = %.3lf, x2 = %.3lf", x1, x2);
                }
                else
                {
                    printf ("%.3lf %.3lf", x1, x2);
                }
                break;

        case STATUSES::INFINITY_SOLUTIONS:
                if (doInfo)
                {
                    printf ("Inf solutions");
                }
                else
                {
                    printf  ("-1");
                }
                break;

        default:
                printf ("Error!! Number of roots: %d", nRoots);
                return -1;

    }
    return 0;
}


void greetings()
{
    printf ("Program solves equations of this form -> ax**2 + bx + c = 0\n\n");
}
