#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#define PRETTY_LOW 0.0000001
#define INF_SOLVES -1


bool isZero(double value);

int solveSquare(const double a, const double b, const double c, double *x1, double *x2);
int solveLinear(const double b, const double c, double *x1);
void getAllParameterValues(double *a, double *b, double *c);
void getParameterValue(const char *variableName, double *var);
void greetings();


int main()
{
    greetings();

    double a = NAN, b = NAN, c = NAN;
    int res = 0;

    res = getAllParameterValues(&a, &b, &c);
    if (res != 3){
        printf("Incorrect user input\n");
        return -2
    }

    if (isnan(a) || isnan(b) || isnan(c))
    {
        printf("Incorrect user input");
        return -2;
    }

    double x1 = 0, x2 = 0;
    int nRoots = solveSquare(a, b, c, &x1, &x2);
    return printResults;
}


void printResults(int nRoots){
    switch (nRoots){
        case 0: printf("No solution");
                break;
        case 1: printf("x1 = %.3lf", x1);
                break;
        case 2: printf("x1 = %.3lf, x2 = %.3lf", x1, x2);
                break;
        case INF_SOLVES:
                printf("Inf solutions");
                break;
        default:
                printf("Error!! Number of roots: %d", nRoots);
                return -1;

    }
    return 0;
}


int getAllParameterValues(double *a, double *b, double *c)
{
    int succsess = 0;

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
    scanf("%lf", var);
    int a = '0';
    while ((a = scanf("%lf", var) == 0 && a != EOF)
    {
        flushUserInput();
    }
    if (a == EOF)
        return 0;
    return 1;
}

void flushUserInput(){
    char p = '0';
    while ((p = getchar()) != '\n' && p != EOF) {}
}

void greetings()
{
    printf("Program solves equations of this form -> ax**2 + bx + c = 0\n\n");
}


int solveSquare(const double a, const double b, const double c, double *x1, double *x2)
{
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);


    if (isZero(a))
        return solveLinear(b, c, x1);


    // ax**2 + bx + c = 0

    double discriminant = b * b - 4.0 * a * c;

    if (isZero(discriminant))
    {
        *x1 = -b / 2.0 / a;
        return 1;
    }
    else if (discriminant < 0.0)
        return 0;
    else
    {

        discriminant = sqrt(discriminant);
        *x1 = (-b + discriminant) / 2.0 / a;
        *x2 = (-b - discriminant) / 2.0 / a;
        return 2;
    }
}

int solveLinear(const double b, const double c, double *x1)
{
    if (isZero(b))
        return (isZero(c)) ? INF_SOLVES : 0;
    *x1 = -b / c;
    return 1;
}

bool isZero(double value)
{
    return value < PRETTY_LOW && value > -PRETTY_LOW;
}
