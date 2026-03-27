#include <stdio.h>
#include <stdlib.h>

void reset_variable(int x);
void reset_array(int A[], int len);
void reset_variable_reference(int *x);

int main(void){

    char c, cA[10];
    int i, iA[3] = {10,20,30,}, x = 2024;

printf("변수 초기화 x = %d \n", x);
printf("배열 초기화 \n");

for (i = 0; i < 3; i++){
    printf("iA[%d] = %d \n", i, iA[i]);
}printf("\n");

// 변수와 배열 초기화 함수 호출
// 변수는 값이 복사되어 전달되고, 배열은 주소가 전달되어 초기화됩니다.
reset_variable(x);
reset_array(iA, 3);
printf("변수 초기화 x = %d \n", x);

// 배열 요소 출력
// 배열은 주소가 전달되어 초기화되므로, 초기화된 값을 확인할 수 있습니다.
reset_variable_reference(&x);
printf("변수 초기화 x = %d \n", x);


reset_variable(x);

    return 0;
}
//-----------------------------------------
void reset_variable(int x){
    x = 0;
}

void reset_array(int A[], int len){
    for (int i = 0; i < len; i++){
        A[i] = 0;
    }
}

void reset_variable_reference(int *x){
    *x = 0;
}