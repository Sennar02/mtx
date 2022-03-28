#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

struct matrix
{
    complex_t** data;

    unsigned m;
    unsigned n;
};

matrix_t*
mtxnew(unsigned m, unsigned n)
{
    matrix_t* mtx;
    
    mtx = (matrix_t*) malloc(sizeof(matrix_t));
    *mtx = (matrix_t) { (complex_t**) calloc(m, sizeof(complex_t*)), m, n };

    for (int i = 0; i < m; i++) {
        mtx->data[i] = (complex_t*) calloc(n, sizeof(complex_t));
    }

    return mtx;
}

void
mtxstr(matrix_t* a, char* str)
{
    char buf[200];

    if (a && a->data) {
        for (int i = 0; i < a->m; i++) {
            for (int j = 0; j < a->n; j++) {
                cpxstr(a->data[i][j], buf);
                sprintf(str, "%s\t", buf);
            }

            sprintf(str, "\n");
        }
    }
}

void
mtxset(matrix_t* a, complex_t z, unsigned i, unsigned j)
{
    if (a && a->data) {
        if (i >= 0 && i <= a->m && j >= 0 && j <= a->n) {
            a->data[i][j] = z;
        }
    }
}

complex_t*
mtxget(matrix_t* a, unsigned i, unsigned j)
{
    if (a && a->data) {
        if (i >= 0 && i <= a->m && j >= 0 && j <= a->n) {
            return &a->data[i][j];
        }
    }

    return NULL;
}