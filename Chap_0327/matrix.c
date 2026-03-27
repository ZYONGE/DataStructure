// define이란, 
// C 언어에서 매크로를 정의하는 데 사용되는 전처리 지시자입니다.
// 매크로는 코드에서 특정 식이나 값을 대체하는 데 사용됩니다.
// 매크로를 정의하면, 컴파일러가 소스 코드를 처리할 때 해당 매크로를 찾아서 정의된 값으로 대체합니다.

#define ROWS 3
#define COLS 3

#include <stdio.h>
#include <stdlib.h>

void print_mat(int m[ROWS][COLS], char *str);
void transpose_mat(int mat[ROWS][COLS]);

int main(void){
//2차원 배열을 통해 행렬을 표현하고
//전치행렬을 연산
//전치행렬이란, 대각선의 값은 그대로 두고, 나머지 값은 대각선을 기준으로 서로 위치가 바뀌는 행렬입니다.
//구현하는 방법은 2차원 배열을 사용하여 행렬을 표현하고, 전치행렬을 계산하는 함수를 작성하는 것입니다.

    int mat[ROWS][COLS] = {
        {4, 0, 1},
        {1, 6, 5},
        {7, 3, 6}
    };
    print_mat(mat, "원래행렬");
    transpose_mat(mat);
    print_mat(mat, "전치행렬");

    return 0;
}

void print_mat(int m[ROWS][COLS], char *str) {
    printf("%s\n", str);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}

void transpose_mat(int mat[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = i + 1; j < COLS; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}