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
} complex_t;

/**
 * @brief Translates a complex number from the polar form to the algebraic one.
 * 
 * @param r Modulus of the number.
 * @param a Argument of the number.
 * @return A complex number.
 */
complex_t
cpx_pol(double r, double a);

/**
 * @brief Calculates the conjugate of a complex number.
 * 
 * @param z A complex number.
 * @return The conjugate of z.
 */
complex_t
cpx_cnj(complex_t z);

/**
 * @brief Calculates the modulus of a complex number.
 * 
 * @param z A complex number.
 * @return The modulus of z.
 */
double
cpx_mod(complex_t z);

/**
 * @brief Calculates the argument of a complex number.
 * 
 * @param z A complex number.
 * @return The argument of z.
 */
double
cpx_arg(complex_t z);

/**
 * @brief Adds the second complex number to the first one.
 * 
 * @param a A complex number.
 * @param b A complex number.
 * @return The result of a + b.
 */
complex_t
cpx_add(complex_t a, complex_t b);

/**
 * @brief Calculates the opposite of a complex number.
 * 
 * @param z A complex number.
 * @return The opposite of z.
 */
complex_t
cpx_opp(complex_t z);

/**
 * @brief Subtracts the second complex number to the first one.
 * 
 * @param a A complex number.
 * @param b A complex number.
 * @return The result of a - b.
 */
complex_t
cpx_sub(complex_t a, complex_t b);

/**
 * @brief Multiplies the first complex number by the second one.
 * 
 * @param a A complex number.
 * @param b A complex number.
 * @return The result of a * b.
 */
complex_t
cpx_mul(complex_t a, complex_t b);

/**
 * @brief Calculates the reciprocal of a complex number.
 * 
 * @param z A complex number.
 * @return The reciprocal of z.
 */
complex_t
cpx_rpc(complex_t z);

/**
 * @brief Divides the first complex number by the second one.
 * 
 * @param a A complex number.
 * @param b A complex number.
 * @return The result of a / b.
 */
complex_t
cpx_div(complex_t a, complex_t b);

/**
 * @brief Calculates the exponential of a complex number.
 * 
 * @param z A complex number.
 * @return The result of exp(z).
 */
complex_t
cpx_exp(complex_t z);

/**
 * @brief Calculates the logarithm of a complex number.
 * 
 * @param z A complex number.
 * @return The result of log(z). 
 */
complex_t
cpx_log(complex_t z);

/**
 * @brief Populates a string representing a complex number.
 * 
 * @param z A complex number.
 * @param s A string to populate.
 * @return The number of characters written.
 */
unsigned
cpx_str(complex_t z, char* s);

#endif /* COMPLEX_H */
