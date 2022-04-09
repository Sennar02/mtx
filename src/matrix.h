#ifndef MATRIX_H
#define MATRIX_H

#include "complex.h"

/**
 * @brief Struct representing a matrix.
 */
typedef struct matrix Matrix;

Matrix*
mMatrixNew(unsigned h, unsigned w, Complex *v);

Matrix*
mMatrixCopy(Matrix *m);

Matrix*
mMatrixDiag(unsigned h, unsigned w, Complex *v);

Matrix*
mMatrixIden(unsigned h, unsigned w);

void
mMatrixFree(Matrix **m);

void
mMatrixTras(Matrix *m);

unsigned
mMatrixRows(Matrix *m);

unsigned
mMatrixCols(Matrix *m);

Matrix*
mMatrixRow(Matrix *m, unsigned i);

Matrix*
mMatrixCol(Matrix *m, unsigned j);

void
mMatrixSet(Matrix *m, unsigned i, unsigned j, Complex z);

Complex*
mMatrixGet(Matrix *m, unsigned i, unsigned j);

void
mMatrixAdd(Matrix *a, Matrix *b);

void
mMatrixMul(Matrix *a, Matrix *b);

void
mMatrixMulN(Matrix *m, Complex z);

unsigned
mMatrixString(Matrix *m, char *s);

#endif /* MATRIX_H */
