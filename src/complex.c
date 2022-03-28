#include <stdio.h>
#include <math.h>
#include "complex.h"

complex_t
cpxpol(double r, double a)
{
    return (complex_t) {
        r * cos(a), r * sin(a)
    };
}

complex_t
cpxcnj(complex_t z)
{
    return (complex_t) {
        z.re, z.im * -1
    };
}

double
cpxmod(complex_t z)
{
    return pow(z.re * z.re + z.im * z.im, 1.0 / 2.0);
}

double
cpxarg(complex_t z)
{
    return atan2(z.im, z.re);
}

complex_t
cpxadd(complex_t a, complex_t b)
{
    return (complex_t) {
        a.re + b.re, a.im + b.im
    };
}

complex_t
cpxopp(complex_t z)
{
    return (complex_t) {
        -z.re, -z.im
    };
}

complex_t
cpxsub(complex_t a, complex_t b)
{
    return cpxadd(a, cpxopp(b));
}

complex_t
cpxmul(complex_t a, complex_t b)
{
    return (complex_t) {
        a.re * b.re - a.im * b.im,
        a.re * b.im + a.im * b.re
    };
}

complex_t
cpxrpc(complex_t z)
{
    complex_t conj = cpxcnj(z),
              mod2 = cpxmul(z, conj);

    return (complex_t) {
        conj.re / mod2.re, conj.im / mod2.re
    };
}

complex_t
cpxdiv(complex_t a, complex_t b)
{
    return cpxmul(a, cpxrpc(b));
}

complex_t
cpxpow(complex_t z, double n)
{
    return cpxnrt(z, 1.0 / n, 0);
}

complex_t
cpxnrt(complex_t z, double n, unsigned k)
{
    double r = pow(cpxmod(z), 1.0 / n);
    double a = (cpxarg(z) + 2 * k * M_PI) / n;

    return cpxpol(r, a);
}

void
cpxstr(complex_t z, char* str)
{
    if (z.im < 0)
        sprintf(str, "%g - %g i", z.re, -z.im);
    else
        sprintf(str, "%g + %g i", z.re, +z.im);
}

void
cpxstre(complex_t z, char* str)
{
    sprintf(str, "%g exp(%g i)", cpxmod(z), cpxarg(z));
}
