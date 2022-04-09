#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

struct matrix
{
    // Array of complex numbers.
    Complex *arr;

    // Number of rows.
    unsigned h;
    // Number of columns.
    unsigned w;
};

Matrix*
mMatrixNew(unsigned h, unsigned w, Complex *v)
{
    Matrix *m = (Matrix*) malloc(sizeof(Matrix));

    if (m != NULL) {
        m->arr = (Complex*) calloc(
            h * w + 1, sizeof(Complex)
        );
        m->h = h;
        m->w = w;

        if (v != NULL) {
            memcpy(m->arr, v, h * w * sizeof(Complex));
        }
    }

    return m;
}

Matrix*
mMatrixCopy(Matrix *m)
{
    Matrix *c = NULL;

    if (m != NULL && m->arr != NULL) {
        unsigned dim = m->w * m->h;
        c = mMatrixNew(m->h, m->w, NULL);

        if (c != NULL && c->arr != NULL) {
            memcpy(c->arr, m->arr, dim * sizeof(Complex));
        }
    }

    return c;
}

Matrix*
mMatrixDiag(unsigned h, unsigned w, Complex *v)
{
    Matrix *m = mMatrixNew(h, w, NULL);
    unsigned min = h;

    if (w < min) min = w;

    if (m != NULL && m->arr != NULL) {
        for (unsigned d = 0; d < min; d++) {
            m->arr[d * m->w + d] = v[d];
        }
    }

    return m;
}

Matrix*
mMatrixIden(unsigned h, unsigned w)
{
    Matrix *m = mMatrixNew(h, w, NULL);
    unsigned min = h;

    if (w < min) min = w;

    if (m != NULL && m->arr != NULL) {
        for (unsigned d = 0; d < min; d++) {
            m->arr[d * m->w + d] = (Complex) {1};
        }
    }

    return m;
}

void
mMatrixFree(Matrix **m)
{
    if (m != NULL && (*m) != NULL) {
        if ((*m)->arr != NULL)
            free((*m)->arr);

        free(*m);
        (*m) = NULL;
    }
}

void
mMatrixTras(Matrix *m)
{
    if (m != NULL && m->arr != NULL) {
        Complex *arr = (Complex*) calloc(m->h * m->w + 1, sizeof(Complex));

        if (arr != NULL) {
            for (unsigned i = 0; i < m->h; i++) {
                for (unsigned j = 0; j < m->w; j++) {
                    arr[i * m->w + j] = m->arr[j * m->w + i];
                }
            }

            free(m->arr);
            m->arr = arr;
        }
    }
}

unsigned
mMatrixH(Matrix* m)
{
    if (m != NULL)
        return m->h;

    return 0;
}

unsigned
mMatrixW(Matrix* m)
{
    if (m != NULL)
        return m->w;

    return 0;
}

Matrix*
mMatrixRow(Matrix *m, unsigned i)
{
    Matrix *v = NULL;

    if (m != NULL && m->arr != NULL) {
        v = mMatrixNew(1, m->w, NULL);
        
        if (v != NULL && v->arr != NULL) {
            for (unsigned o = 0; o < v->w; o++) {
                v->arr[o] = m->arr[i * m->w + o];
            }
        }
    }

    return v;
}

Matrix*
mMatrixCol(Matrix *m, unsigned j)
{
    Matrix *v = NULL;

    if (m != NULL && m->arr != NULL) {
        v = mMatrixNew(m->h, 1, NULL);
        
        if (v != NULL && v->arr != NULL) {
            for (unsigned o = 0; o < m->h; o++) {
                v->arr[o] = m->arr[o * m->w + j];
            }
        }
    }

    return v;
}

void
mMatrixSet(Matrix *m, unsigned i, unsigned j, Complex z)
{
    if (m != NULL && m->arr != NULL) {
        if ((0 <= i && i < m->h) &&
            (0 <= j && j < m->w)) {
            m->arr[i * m->w + j] = z;
        }
    }
}

Complex*
mMatrixGet(Matrix *m, unsigned i, unsigned j)
{
    if (m != NULL && m->arr != NULL) {
        if ((0 <= i && i < m->h) &&
            (0 <= j && j < m->w)) {
            return &m->arr[i * m->w + j];
        }
    }

    return NULL;
}

void
mMatrixAdd(Matrix *a, Matrix *b)
{
    if ((a != NULL && a->arr != NULL) &&
        (b != NULL && b->arr != NULL) && (a->h == b->h && a->w == b->w)) {
        for (unsigned i = 0; i < a->h; i++) {
            for (unsigned j = 0; j < a->w; j++) {
                a->arr[i * a->w + j] = mComplexAdd(
                    a->arr[i * a->w + j], b->arr[i * a->w + j]
                );
            }
        }
    }
}

void
mMatrixMul(Matrix *a, Matrix *b)
{
    Complex z = {0};

    if ((a != NULL && a->arr != NULL) &&
        (b != NULL && b->arr != NULL) && (a->w == b->h)) {
        Complex *arr = (Complex*) calloc(a->h * b->w + 1, sizeof(Complex));

        if (arr != NULL) {
            for (unsigned i = 0; i < a->h; i++) {
                for (unsigned j = 0; j < b->w; j++) {
                    for (unsigned k = 0; k < a->w; k++) {
                        z = mComplexMul(a->arr[i * a->h + k], b->arr[k * a->h + j]);
                        arr[i * a->h + j] = mComplexAdd(arr[i * a->h + j], z);
                    }
                }
            }

            free(a->arr);
            a->arr = arr;
        }
    }
}

void
mMatrixMulN(Matrix *m, Complex z)
{
    if (m != NULL && m->arr != NULL) {
        for (unsigned i = 0; i < m->h; i++) {
            for (unsigned j = 0; j < m->w; j++) {
                m->arr[i * m->h + j] = mComplexMul(m->arr[i * m->h + j], z);
            }
        }
    }
}

unsigned
mMatrixString(Matrix *m, char *s)
{
    static char arr[128] = {0};
    unsigned c = 0;

    if (m != NULL && m->arr != NULL && s != NULL) {
        for (unsigned i = 0; i < m->h; i++) {
            for (unsigned j = 0; j < m->w; j++) {
                mComplexString(m->arr[i * m->w + j], arr);
                c += sprintf(s + c, "%15s ", arr);
            }

            c += sprintf(s + c, "\n");
        }
    }

    return c;
}
