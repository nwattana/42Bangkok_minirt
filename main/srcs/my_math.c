#include "../inc/minirt.h"

// return min exist positive value
double solve_quadratic(double a, double b, double c)
{
    double test;
    double t1;
    double t2;
    double testsqr;

    test = b * b - 4.0 * a * c;
    testsqr = sqrt(test);
    if (test > 0.0)
    {
        t1 = (-b + testsqr) / (2.0 * a);
        t2 = (-b - testsqr) / (2.0 * a);
        if (t1 < 0.0 || t2 < 0.0)
            return (-1);
        if (t1 < t2)
            return (t1);
        else
            return (t2);
    }
    return (-1);
}