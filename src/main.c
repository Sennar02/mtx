#include <stdio.h>
#include "matrix.h"

int
main(int argc, char** argv)
{
    if (argc != 1) {
        printf("Warning: Too much arguments for program '%s'.\n", argv[0]);
        return 1;
    }

    char buf[500];

    matrix_t* mtx = mtxnew(2, 3);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            mtxset(mtx, (complex_t) {i, j}, i, j);
        }
    }

    mtxstr(mtx, buf);
    printf("La matrice è:\n%s\n", buf);

    return 0;
}
