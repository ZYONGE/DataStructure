#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef int Element;
#include "array_stack.h"

int main(void) {

    int A[7] = {1, 2, 3, 4, 5, 6, 7};
    init_stack();
    printf("스택 테스트 \n 입력 데이터");

    for (int i = 0; i < 7; i++) {
        printf("%d ", A[i]);
        push(A[i]);
    }
    printf("\n 출력 데이터");

    while (!is_empty()) {
        printf("%d ", pop());
    }
    printf("\n");

    return 0;
}


