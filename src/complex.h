#ifndef COMPLEX_H
#define COMPLEX_H

/**
 * @brief Struct representing a complex number.
 */
typedef struct complex
{
    double re;
    double im;
} complex_t;

/**
 * @brief 
 * 
 * @param r 
 * @param a 
 * @return complex_t 
 */
complex_t
cpxpol(double r, double a);

/**
 * @brief 
 * 
 * @param z 
 * @param str 
 */
void
cpxstr(complex_t z, char* str);

/**
 * @brief 
 * 
 * @param z 
 * @param str 
 */
void
cpxstre(complex_t z, char* str);

/**
 * @brief 
 * 
 * @param z 
 * @return double 
 */
double
cpxmod(complex_t z);

/**
 * @brief 
 * 
 * @param z 
 * @return double 
 */
double
cpxarg(complex_t z);

/**
 * @brief 
 * 
 * @param z 
 * @return complex_t 
 */
complex_t
cpxcnj(complex_t z);

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return complex_t 
 */
complex_t
cpxadd(complex_t a, complex_t b);

/**
 * @brief 
 * 
 * @param z 
 * @return complex_t 
 */
complex_t
cpxopp(complex_t z);

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return complex_t 
 */
complex_t
cpxsub(complex_t a, complex_t b);

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return complex_t 
 */
complex_t
cpxmul(complex_t a, complex_t b);

/**
 * @brief 
 * 
 * @param z 
 * @return complex_t 
 */
complex_t
cpxrpc(complex_t z);

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return complex_t 
 */
complex_t
cpxdiv(complex_t a, complex_t b);

/**
 * @brief 
 * 
 * @param z 
 * @param n 
 * @return complex_t 
 */
complex_t
cpxpow(complex_t z, double n);

/**
 * @brief 
 * 
 * @param z 
 * @param n 
 * @param k 
 * @return complex_t 
 */
complex_t
cpxnrt(complex_t z, double n, unsigned k);

#endif /* COMPLEX_H */
