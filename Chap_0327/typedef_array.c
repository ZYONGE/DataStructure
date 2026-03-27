//typedef를 통해 데이터를 추상화하고
//배열을 통해 값을 입력하는 연습

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int row;
    int col;
    int value;
}Elem;

void print_mat2(Elem m[], int len, char *str){
    printf("%s: \n", str);
    for (int i = 0; i < len; i++) {
        printf("%d, %d, %d \n", m[i].row, m[i].col, m[i].value);
    }
}

void transpose_mat2(Elem m[], int len){
    for (int i = 0; i < len; i++) {
        int temp = m[i].row;
        m[i].row = m[i].col;
        m[i].col = temp;
    }
}

int main(void){
    Elem mat[5] = {
        {0, 3, 11},
        {2, 5, 42},
        {1, 1, 3},
        {2, 0, 4},
        {2, 2, 5}
    };

    print_mat2(mat, 5, "희소 행렬");
    transpose_mat2(mat, 5);
    print_mat2(mat, 5, "전치 행렬");
    
    return 0;
}