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
    double a = NAN, b = NAN, c = NAN;

    greetings();

    getAllParameterValues(&a, &b, &c);

    if (isnan(a) || isnan(b) || isnan(c))
    {
        printf("Неверные входные данные");
        return -2;
    }

    double x1 = 0, x2 = 0;
    int nRoots = solveSquare(a, b, c, &x1, &x2);
    switch (nRoots){
        case 0: printf("Решений нет");
                break;
        case 1: printf("x1 = %.3lf", x1);
                break;
        case 2: printf("x1 = %.3lf, x2 = %.3lf", x1, x2);
                break;
        case INF_SOLVES:
                printf("Бесконечные решения");
                break;
        default:
                printf("Ошибка!! Количество корней: %d", nRoots);
                return -1;

    }
    return 0;
}


void getAllParameterValues(double *a, double *b, double *c)
{

    getParameterValue("a", a);
    getParameterValue("b", b);
    getParameterValue("c", c);
}                     //TODO while


void getParameterValue(const char *variableName, double *var)
{
    printf("Введите значение переменной %s: ", variableName);
    scanf("%lf", var);
    while (isnan(*var)) {
        getchar();
        scanf("%lf", var);
    }
}


void greetings()
{
    printf("Программа решает уравнения вида ax**2 + bx + c = 0\n\n");
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
