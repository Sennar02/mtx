#ifndef COMPLEX_H
#define COMPLEX_H

/**
 * @brief Struct representing a complex number
 *        in algebraic form.
 */
typedef struct complex
{
    double re;
    double im;
} complex_t;

/**
 * @brief Translates a complex number from the polar form to the algebraic one.
 * 
 * @param r Modulus of the number.
 * @param a Argument of the number.
 * @return A complex number in algebraic form.
 */
complex_t
cpxpol(double r, double a);

/**
 * @brief Calculates the conjugate of a complex number.
 * 
 * @param z A complex number in algebraic form.
 * @return A complex number in algebraic form.
 */
complex_t
cpxcnj(complex_t z);

/**
 * @brief Calculates the modulus of a complex number.
 * 
 * @param z A complex number in algebraic form.
 * @return The modulus of the parameter.
 */
double
cpxmod(complex_t z);

/**
 * @brief Calculates the argument of a complex number.
 * 
 * @param z A complex number in algebraic form.
 * @return The argument of the parameter.
 */
double
cpxarg(complex_t z);

/**
 * @brief Adds the second complex number to the first one.
 * 
 * @param a A complex number in algebraic form.
 * @param b A complex number in algebraic form.
 * @return A complex number in algebraic form.
 */
complex_t
cpxadd(complex_t a, complex_t b);

/**
 * @brief Calculates the opposite of a complex number.
 * 
 * @param z A complex number in algebraic form.
 * @return A complex number in algebraic form.
 */
complex_t
cpxopp(complex_t z);

/**
 * @brief Subtracts the second complex number to the first one.
 * 
 * @param a A complex number in algebraic form.
 * @param b A complex number in algebraic form.
 * @return A complex number in algebraic form.
 */
complex_t
cpxsub(complex_t a, complex_t b);

/**
 * @brief Multiplies the first complex number by the second one.
 * 
 * @param a A complex number in algebraic form.
 * @param b A complex number in algebraic form.
 * @return A complex number in algebraic form.
 */
complex_t
cpxmul(complex_t a, complex_t b);

/**
 * @brief Calculates the reciprocal of a complex number.
 * 
 * @param z A complex number in algebraic form.
 * @return A complex number in algebraic form.
 */
complex_t
cpxrpc(complex_t z);

/**
 * @brief Divides the first complex number by the second one.
 * 
 * @param a A complex number in algebraic form.
 * @param b A complex number in algebraic form.
 * @return A complex number in algebraic form.
 */
complex_t
cpxdiv(complex_t a, complex_t b);

/**
 * @brief Calculates the nth-power of a complex number.
 * 
 * @param z A complex number in algebraic form.
 * @param n A real exponent number.
 * @return A complex number in algebraic form.
 */
complex_t
cpxpow(complex_t z, double n);

/**
 * @brief Calculates one of the nth-roots of a complex number.
 * 
 * @param z A complex number in algebraic form.
 * @param n A real exponent number.
 * @param k An integer selector of the root.
 * @return A complex number in algebraic form.
 */
complex_t
cpxnrt(complex_t z, double n, unsigned k);

/**
 * @brief Populates a string representing a complex number in algebraic form.
 * 
 * @param z A complex number in algebraic form.
 * @param str A string to populate.
 */
void
cpxstr(complex_t z, char* str);

#ifdef CPXSTRE
    /**
     * @brief Populates a string representing a complex number in exponential form.
     * 
     * @param z A complex number in algebraic form.
     * @param str A string to populate.
     */
    void
    cpxstre(complex_t z, char* str);
#endif /* CPXSTRE */

#endif /* COMPLEX_H */
