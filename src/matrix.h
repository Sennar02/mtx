#ifndef MATRIX_H
#define MATRIX_H

#include "complex.h"

typedef struct matrix matrix_t;

matrix_t*
mtxnew(unsigned m, unsigned n);

void
mtxset(matrix_t* a, complex_t z, unsigned i, unsigned j);

void
mtxstr(matrix_t* a, char* str);

complex_t*
mtxget(matrix_t* a, unsigned i, unsigned j);

#endif /* MATRIX_H */
