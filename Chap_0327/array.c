#include <stdio.h>
#include <stdlib.h>

int main(void){

    char c, cA[10];
    int i, iA[10];
    float f, fA[10];
    double d, dA[10];

    printf("자료형 크기 [bytes] \n");
    printf("char 형: %d, c의 크기 %d \n", sizeof(char), sizeof(c));
    printf("int 형: %d, i의 크기 %d \n", sizeof(int), sizeof(i));
    printf("float 형: %d, f의 크기 %d \n", sizeof(float), sizeof(f));
    printf("double 형: %d, d의 크기 %d \n", sizeof(double), sizeof(d));
    
    printf("배열 크기 [bytes] \n");
    printf("char 형: %d, cA의 크기 %d \n", sizeof(cA), sizeof(cA[0]));
    printf("int 형: %d, iA의 크기 %d \n", sizeof(iA), sizeof(iA[0]));
    printf("float 형: %d, fA의 크기 %d \n", sizeof(fA), sizeof(fA[0]));
    printf("double 형: %d, dA의 크기 %d \n", sizeof(dA), sizeof(dA[0]));

    printf("배열 요소의 수 구하기 \n");
    printf("cA 요소의 수 = %d \n",  sizeof(cA) / sizeof(cA[0]));
    printf("iA 요소의 수 = %d \n", sizeof(iA) / sizeof(iA[0]));
    printf("fA 요소의 수 = %d \n", sizeof(fA) / sizeof(fA[0]));
    printf("dA 요소의 수 = %d \n", sizeof(dA) / sizeof(dA[0]));


    return 0;
}