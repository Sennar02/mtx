#include <stdio.h>
#include <math.h>
#include "complex.h"

Complex
mComplexPolar(double r, double a)
{
    return (Complex) { re: r * cos(a), im: r * sin(a) };
}

Complex
mComplexConj(Complex z)
{
    return (Complex) { re: +z.re, im: -z.im };
}

double
mComplexMod(Complex z)
{
    return pow((z.re * z.re) + (z.im * z.im), 0.5);
}

double
mComplexArg(Complex z)
{
    return atan2(z.im, z.re);
}

Complex
mComplexAdd(Complex a, Complex b)
{
    return (Complex) { re: a.re + b.re, im: a.im + b.im };
}

Complex
mComplexOpp(Complex z)
{
    return (Complex) { re: -z.re, im: -z.im };
}

Complex
mComplexSub(Complex a, Complex b)
{
    return mComplexAdd(a, mComplexOpp(b));
}

Complex
mComplexMul(Complex a, Complex b)
{
    return (Complex) {
        re: a.re * b.re - a.im * b.im,
        im: a.re * b.im + a.im * b.re
    };
}

Complex
mComplexRep(Complex z)
{
    return (Complex) {
        re: +z.re / (z.re * z.re) + (z.im * z.im),
        im: -z.im / (z.re * z.re) + (z.im * z.im)
    };
}

Complex
mComplexDiv(Complex a, Complex b)
{
    return mComplexMul(a, mComplexRep(b));
}

Complex
mComplexExp(Complex z)
{
    return mComplexPolar(exp(z.re), z.im);
}

Complex
mComplexLog(Complex z)
{
    return (Complex) {
        re: log(mComplexMod(z)),
        im: mComplexArg(z)
    };
}

unsigned
mComplexString(Complex z, char *s)
{
    if (s != NULL)
        return sprintf(s, "(%g, %g)", z.re, z.im);

    return 0;
}
