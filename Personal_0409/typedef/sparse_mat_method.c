#include <stdio.h>
#include <stdlib.h>
#include "sparse_mat.h"

void print_mat(Elem mat[],int len, char* str){
    printf("%s: \n", str);
    for(int i=0;i<len;i++){
        printf("%d%d%d\n", mat[i].rows,mat[i].cols,mat[i].value);
    }
}

void transpose_mat(Elem mat[], int len){
    for(int i=0;i<len;i++){
        int temp = mat[i].rows;
        mat[i].rows = mat[i].cols;
        mat[i].cols = temp;
    }
}