//메모리 동적 할당
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc()과 free() 함수를 사용하기 위해 stdlib.h 헤더 파일을 포함함.

int main(void) {

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n); //사용자 입력: n에 값을 직접 저장하기 위해서 reference로 받음.
   
    // (int *) : malloc()이 반환하는 void* 포인터를 int* 타입으로 캐스팅함. n * sizeof(int) : n개의 정수를 저장할 수 있는 메모리 크기를 계산함.
    // 만약 자료형이 char이라면, (int *)를 사용할 필요가 없다. 기본 할당량이
    int* arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL) { //malloc()이 메모리 할당에 실패한 경우 NULL을 반환하므로, 이를 확인하여 오류 처리를 함.
        printf("Memory allocation failed\n");
        return 1; //프로그램을 비정상적으로 종료함.
    }

    // 배열 초기화 및 출력
    for (int i = 0; i < n; i++) {
        arr[i] = i + 10; //배열에 10부터 n+9까지의 값을 저장함.
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); //배열의 각 요소를 출력함.
    }
    printf("\n");

    free(arr); //free() : 동적으로 할당된 메모리를 해제하는 함수. arr가 가리키는 메모리를 해제하여 시스템 자원을 반환함.
    arr = NULL; //포인터를 NULL로 설정하여 dangling pointer(해제된 메모리를 가리키는 포인터) 문제를 방지함.

    return 0;
}