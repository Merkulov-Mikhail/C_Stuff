#include "callsMaker.h"


void callHelp()
{
    printf ("Pretty simple quadratic equations solver\n\n"
                "usage: squareSolver.exe [-h] [-t] [-ni] [-ar M1 M2 M3]\n\n"
                "options:\n"
                "-h, --help              -> shows this message and leaves\n"
                "-t, --tests             -> runs program on tests and leaves\n"
                "-ar, --arguments X Y Z  -> gets 3 floats X, Y, Z and solves quadratic equation X * x**2 + Y * x + Z = 0\n");
}


int callTests()
{
    int failedTests = TestAll();
    if (failedTests)
    {
        printf ("TESTS FAILED: %d\n", failedTests);
        return PROGRAM_RESULTS::TESTS_FAILED;
    }
    printf ("PASSED all tests\n");
    return 0;
}


void callError (int info){
    if (info)
        printf ("Incorrect user input\n");
    else
        printf ("-2\n");
}


int printResult (int nRoots, double x1, double x2, int doInfo)
{
    switch (nRoots)
    {
        case STATUSES::ZERO_SOLUTIONS:
            if (doInfo)
            {
                printf ("No solution\n");
            }
            else
            {
                printf ("0\n");
            }
            break;

        case STATUSES::ONE_SOLUTION:
            if (doInfo)
            {
                printf ("x1 = %.3lf\n", x1);
            }
            else
            {
                printf ("%.3lf\n", x1);
            }
            break;

        case STATUSES::TWO_SOLUTIONS:
            if (doInfo)
            {
                printf ("x1 = %.3lf, x2 = %.3lf\n", x1, x2);
            }
            else
            {
                printf ("%.3lf %.3lf\n", x1, x2);
            }
            break;

        case STATUSES::INFINITY_SOLUTIONS:
            if (doInfo)
            {
                printf ("Inf solutions\n");
            }
            else
            {
                printf ("-1\n");
            }
            break;

        default:
            fprintf (stderr, "Error!! Number of roots: %d\n", nRoots);
            return PROGRAM_RESULTS::ERROR_WITH_ROOTS;

    }
    return 0;
}


void greetings()
{
    printf ("Program solves equations of this form -> ax**2 + bx + c = 0\n\n");
}
