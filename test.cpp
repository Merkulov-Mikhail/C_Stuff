#include "test.h"
#include "solver.h"
#include "constants.h"
#include <stdio.h>


int TestLinear(double b, double c, double x1ref, int nRootsRef){
	double x1 = 0;
	int nRoots = solveLinear(b, c, &x1);

	if (nRootsRef == nRoots){
		if (x1ref == x1){
			return 0;
		}
		printf("--TEST LINEAR FAILED--\n"
               "x1 = %lf, x1ref = %lf, b = %lf, c = %lf\n", x1, x1ref, b, c);
		return 1;
	}
	printf("--TEST LINEAR FAILED--\n"
           "nRoots = %d, nRootsRef = %d, b = %lf, c = %lf\n", nRoots, nRootsRef, b, c);
	return 1;
}


int TestSquare(double a, double b, double c, double x1ref, double x2ref, int nRootsRef)
{
    double x1 = 0, x2 = 0;
    int nRoots = solveSquare(a, b, c, &x1, &x2);
    if (nRoots == nRootsRef){
        if ((x1ref == x1 && x2ref == x2) || (x1ref == x2 && x2ref == x1)){
            return 0;
        }
        if (nRoots == 1 && (x1ref == x1 || x1ref == x2 || x2ref == x1 || x2ref == x2)){
            return 0;
        }
        if (nRoots == STATUSES::INFINITY_SOLUTIONS || nRoots == STATUSES::ZERO_SOLUTIONS){
            return 0;
        }
        printf("--TEST SQUARE FAILED--\n"
               "x1 = %lf, x1ref = %lf, x2 = %lf, x2ref = %lf, a = %lf, b = %lf, c = %lf\n", x1, x1ref, x2, x2ref, a, b, c);
		return 1;
    }
    printf("--TEST SQUARE FAILED--\n"
           "nRoots = %d, nRootsRef = %d, a = %lf, b = %lf, c = %lf\n", nRoots, nRootsRef, a, b, c);
    return 1;
}


int TestAll(){
    int failed = 0;
    failed += TestLinear(0, 0, 0, STATUSES::INFINITY_SOLUTIONS);
    failed += TestLinear(1, 1, -1, STATUSES::ONE_SOLUTION);
    failed += TestLinear(0, 1, 0, STATUSES::ZERO_SOLUTIONS);
    failed += TestLinear(2, 1, -0.5, STATUSES::ONE_SOLUTION);
    failed += TestSquare(1, 2, 1, -1, -1, STATUSES::ONE_SOLUTION);
    failed += TestSquare(0, 0, 0, 0, 0, STATUSES::INFINITY_SOLUTIONS);
    failed += TestSquare(1, 5, -6, 1, -6, STATUSES::TWO_SOLUTIONS);
    failed += TestSquare(1, 0, -4, -2, 2, STATUSES::TWO_SOLUTIONS);
    failed += TestSquare(1, 0, 1, 0, 0, STATUSES::ZERO_SOLUTIONS);
    return failed;
}
