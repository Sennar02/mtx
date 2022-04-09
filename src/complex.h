#ifndef COMPLEX_H
#define COMPLEX_H

/**
 * @brief Struct representing a complex number in algebraic form.
 */
typedef struct complex
{
    // Real part of the number.
    double re;
    // Imaginary part of the number.
    double im;
} Complex;

Complex
mComplexPolar(double r, double a);

Complex
mComplexConj(Complex z);

double
mComplexMod(Complex z);

double
mComplexArg(Complex z);

Complex
mComplexAdd(Complex a, Complex b);

Complex
mComplexOpp(Complex z);

Complex
mComplexSub(Complex a, Complex b);

Complex
mComplexMul(Complex a, Complex b);

Complex
mComplexRep(Complex z);

Complex
mComplexDiv(Complex a, Complex b);

Complex
mComplexExp(Complex z);

Complex
mComplexLog(Complex z);

unsigned
mComplexString(Complex z, char *s);

#endif /* COMPLEX_H */
