#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#include "linkedstack.h"

int main(){

    int A[7] = {0,1,1,2,3,5,8};
    init_stack();

    printf("Stack test. Enter 7 integers.\n");
    for(int i=0; i<7; i++){
        push(A[i]);
    }
    printf("\n입력된 순서");
    print_recur(top);
    printf("\n입력된 역순");
    print_stack();
    printf("\n");

    printf("Print data\n");

    while(!is_empty()){
        printf("%3d ", peek());
        pop();
    }
    printf("\n");

    return 0;
}