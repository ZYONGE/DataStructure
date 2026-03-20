#include <stdio.h>
#include <stdlib.h>

int add(int a, int b);
int sub(int a, int b);
int cmp_asc(const void* a, const void* b);
int cmp_desc(const void* a, const void* b);

int main(void) {

    int (*fp_add)(int, int); //함수 포인터 선언: func_ptr은 두 개의 int 매개변수를 받고 int를 반환하는 함수에 대한 포인터임.
    fp_add = add; //함수 포인터에 add 함수의 주소를 할당함.
    printf("Addition: %d\n", fp_add(5, 3));
    int (*fp_sub)(int, int) = sub; //함수 포인터 선언과 동시에 sub 함수의 주소를 할당함.
    printf("Subtraction: %d\n", fp_sub(5, 3));

    int arr[] = {100, 20, 1, 200, 120};

    //function call back.
    int (*cmp)(const void*, const void*) = cmp_asc;; 

    //qsort() : 배열을 정렬하는 데 사용. qsort(배열의 포인터, 배열의 요소 수, 각 요소의 크기, 비교 함수의 포인터)
    qsort(arr, 5, sizeof(int), cmp);
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //function call back.
    cmp = cmp_desc; //함수 포인터에 cmp_desc 함수의 주소를 할당함.

    qsort(arr, 5, sizeof(int), cmp);
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}
int cmp_asc(const void* a, const void* b) {
    //참고: asc는 "ascending".
    return (*(int*)a - *(int*)b); //오름차순 정렬을 위해 a에서 b를 뺌.
}
int cmp_desc(const void* a, const void* b) {
    //참고: desc는 "descending".
    return (*(int*)b - *(int*)a); //내림차순 정렬을 위해 b에서 a를 뺌.
}