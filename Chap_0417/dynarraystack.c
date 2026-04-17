#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#include "dynarraystack.h"

int main(void) {
    
    MAX_SIZE = 8; // 초기 스택 크기를 작게 설정하여 동적 확장 기능을 테스트
    init_stack();

    printf("Enter Value\n");
    for (int i = 0; i < 50; i++) {
        Element e;
        scanf("%d", &e);
        push(e);
    }
    printf("Stack contents (top to bottom):\n");
    while(!is_empty()) {
        printf("%d ", pop());
    }
    printf("\n");

    free(data); // 동적 메모리 해제
    
    return 0;
}