#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int rows;
    int cols;
    int value;
}Elem;

void print_mat(Elem mat[],int len, char* str);
void transpose_mat(Elem* mat, int len);
