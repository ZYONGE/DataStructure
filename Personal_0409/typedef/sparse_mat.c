#include <stdio.h>
#include <stdlib.h>
#include "sparse_mat.h"


int main(){
    Elem mat[5] = {
        {0,3,1},
        {2,5,42},
        {3,1,33},
        {4,4,87},
        {5,4,55},
    };

    print_mat(mat, 5, "희소행렬");
    transpose_mat(mat, 5);
    print_mat(mat, 5, "전치행렬");

    return 0;
}