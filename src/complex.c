#include <stdio.h>
#include <math.h>
#include "complex.h"

complex_t
cpx_pol(double r, double a)
{
    complex_t z = {
        re: r * cos(a),
        im: r * sin(a)
    };

    return z;
}

complex_t
cpx_cnj(complex_t z)
{
    complex_t c = {
        re: z.re,
        im: z.im * -1
    };

    return c;
}

double
cpx_mod(complex_t z)
{
    return pow((z.re * z.re) + (z.im * z.im), 0.5);
}

double
cpx_arg(complex_t z)
{
    return atan2(z.im, z.re);
}

complex_t
cpx_add(complex_t a, complex_t b)
{
    complex_t z = {
        re: a.re + b.re,
        im: a.im + b.im
    };

    return z;
}

complex_t
cpx_opp(complex_t z)
{
    complex_t o = {
        re: z.re * -1,
        im: z.im * -1
    };

    return o;
}

complex_t
cpx_sub(complex_t a, complex_t b)
{
    return cpx_add(a, cpx_opp(b));
}

complex_t
cpx_mul(complex_t a, complex_t b)
{
    complex_t z = {
        re: a.re * b.re - a.im * b.im,
        im: a.re * b.im + a.im * b.re
    };

    return z;
}

complex_t
cpx_rpc(complex_t z)
{
    complex_t conj = cpx_cnj(z),
              mod2 = cpx_mul(z, conj);

    complex_t r = {
        re: conj.re / mod2.re,
        im: conj.im / mod2.re
    };

    return r;
}

complex_t
cpx_div(complex_t a, complex_t b)
{
    return cpx_mul(a, cpx_rpc(b));
}

complex_t
cpx_exp(complex_t z)
{
    return cpx_pol(exp(z.re), z.im);
}

complex_t
cpx_log(complex_t z)
{
    complex_t l = {
        re: log(cpx_mod(z)),
        im: cpx_arg(z)
    };

    return l;
}

unsigned
cpx_str(complex_t z, char* s)
{
    if (s != NULL)
        return sprintf(s, "(%g, %g)", z.re, z.im);

    return 0;
}
