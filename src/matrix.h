#ifndef MATRIX_H
#define MATRIX_H

#include "complex.h"

typedef struct matrix matrix_t;

/**
 * @brief 
 * 
 * @param m 
 * @param n 
 * @return matrix_t* 
 */
matrix_t*
mtxnew(unsigned m, unsigned n);

/**
 * @brief 
 * 
 * @param m 
 */
void
mtxdel(matrix_t* m);

/**
 * @brief 
 * 
 * @param a 
 * @return unsigned 
 */
unsigned
mtxhgt(matrix_t* m);

/**
 * @brief 
 * 
 * @param a 
 * @return unsigned 
 */
unsigned
mtxwdt(matrix_t* m);

/**
 * @brief 
 * 
 * @param m 
 * @param i 
 * @param j 
 * @param z 
 */
void
mtxset(matrix_t* m, unsigned i, unsigned j, complex_t z);

/**
 * @brief 
 * 
 * @param m 
 * @param i 
 * @param j 
 * @return complex_t* 
 */
complex_t*
mtxget(matrix_t* m, unsigned i, unsigned j);

/**
 * @brief 
 * 
 * @param m 
 * @param z 
 */
void
mtxaddn(matrix_t* m, complex_t z);

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 */
void
mtxadd(matrix_t* a, matrix_t* b);

/**
 * @brief 
 * 
 * @param m 
 * @param str 
 */
void
mtxstr(matrix_t* m, char* str);

#ifdef CPXSTRE
    /**
     * @brief 
     * 
     * @param m 
     * @param str 
     */
    void
    mtxstre(matrix_t* m, char* str);
#endif /* CPXSTRE */

#endif /* MATRIX_H */
