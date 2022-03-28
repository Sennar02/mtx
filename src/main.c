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

    matrix_t* m1 = mtxnew(2, 2),
            * m2 = mtxnew(2, 2);

    for (int i = 0; i < mtxhgt(m1); i++) {
        for (int j = 0; j < mtxwdt(m1); j++) {
            mtxset(m1, i, j, (complex_t) {i, j});
            mtxset(m2, i, j, (complex_t) {j, i});
        }
    }

    mtxadd(m1, m2);
    mtxstr(m1, buf);
    printf("%s", buf);

    mtxdel(m1);

    return 0;
}
