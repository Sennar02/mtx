#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

struct matrix
{
    complex_t* data;

    unsigned h;
    unsigned w;
};

matrix_t*
mtxnew(unsigned h, unsigned w)
{
    matrix_t* ptr = (matrix_t*) malloc(sizeof(matrix_t));

    if (ptr != NULL) {
        (*ptr) = (matrix_t) { 
            (complex_t*) calloc(h * w + 1, sizeof(complex_t)),
            h: h, w: w
        };
    }

    return ptr;
}

void
mtxdel(matrix_t* m)
{
    if (m != NULL) {
        if (m->data != NULL) 
            free(m->data);

        free(m);
    }
}

unsigned
mtxhgt(matrix_t* m)
{
    if (m != NULL)
        return m->h;

    return 0;
}

unsigned
mtxwdt(matrix_t* m)
{
    if (m != NULL)
        return m->w;

    return 0;
}

void
mtxset(matrix_t* m, unsigned i, unsigned j, complex_t z)
{
    if (m != NULL && m->data != NULL) {
        if ((i >= 0 && i <= m->h) &&
            (j >= 0 && j <= m->w))
            m->data[i * m->w + j] = z;
    }
}

complex_t*
mtxget(matrix_t* m, unsigned i, unsigned j)
{
    if (m != NULL && m->data != NULL) {
        if ((i >= 0 && i <= m->h) &&
            (j >= 0 && j <= m->w))
            return &m->data[i * m->w + j];
    }

    return NULL;
}

void
mtxaddn(matrix_t* m, complex_t z)
{
    if (m != NULL && m->data != NULL) {
        for (int i = 0; i < m->h; i++) {
            for (int j = 0; j < m->w; j++) {
                m->data[i * m->w + j] = cpxadd(m->data[i * m->w + j], z);
            }
        }
    }
}

void
mtxadd(matrix_t* a, matrix_t* b)
{
    if ((a != NULL && a->data != NULL) &&
        (b != NULL && b->data != NULL) &&
        (a->h == b->h && a->w == b->w)) {
        for (int i = 0; i < a->h; i++) {
            for (int j = 0; j < a->w; j++) {
                a->data[i * a->w + j] = cpxadd(a->data[i * a->w + j], b->data[i * a->w + j]);
            }
        }
    }
}

void
mtxstr(matrix_t* m, char* str)
{
    char buf[200] = {0};

    if (m != NULL && m->data != NULL) {
        for (int i = 0; i < m->h; i++) {
            str += sprintf(str, "| ");

            for (int j = 0; j < m->w; j++) {
                cpxstr(m->data[i * m->w + j], buf);
                str += sprintf(str, "%*s ",
                    (j != 0) * 20, buf
                );
            }

            str += sprintf(str, "|\n");
        }
    }
}

void
mtxstre(matrix_t* m, char* str)
{
    char buf[200] = {0};

    if (m != NULL && m->data != NULL) {
        for (int i = 0; i < m->h; i++) {
            str += sprintf(str, "| ");

            for (int j = 0; j < m->w; j++) {
                cpxstre(m->data[i * m->w + j], buf);
                str += sprintf(str, "%*s ",
                    (j != 0) * 20, buf
                );
            }

            str += sprintf(str, "|\n");
        }
    }
}
