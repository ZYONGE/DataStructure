#include <stdio.h>

//함수 선언
void add_one_by_value(int x);
void add_one_by_reference(int *x);
void swap_by_reference(int *x, int *y);
void find_max_min(int *arr, int n, int *max, int *min);
void double_all(int arr[], int n);

//main 함수
int main(void){
    // 포인터에 대하여
    int a = 10;
    int *ptr= &a; // p는 a의 주소값을 저장하는 포인터 변수

    // &a는 a의 주소값. 16진수로 출력하기 위해 %p 사용
    printf("address of a: %p\n", &a);
    printf("address stored in ptr: %p\n", ptr);
    printf("value of a: %d\n", a);
    printf("value pointed by ptr: %d\n", *ptr);

    //주소를 가지고 그 주소에 있는 값을 변경할 수 있다.
    *ptr = 99;
    printf("value pointed by ptr after change: %d\n", *ptr);
    printf("new value of a: %d\n", a);

    // 포인터를 이용해서 함수에 값을 전달할 수 있다.
    // 값에 의한 전달이 실제 변수값에 영향을 주지 않는 이유는 함수에 전달된 값이 복사되어 함수 내부에서 사용되기 때문이다.
    // 포인터를 이용한 전달이 실제 변수값에 영향을 주는 이유는 함수에 전달된 포인터가 변수의 주소를 가리키고 있기 때문이다.
    add_one_by_value(a);
    printf("value of a after add_one_by_value: %d\n", a);
    add_one_by_reference(&a);
    printf("value of a after add_one_by_reference: %d\n", a);

    // 포인터를 이용해서 두 변수의 값을 서로 바꿀 수 있다.
    // swap_by_reference 함수는 두 변수의 주소를 받아서 그 주소에 있는 값을 서로 바꿔준다.
    int b = 30;
    int c = 40;
    printf("before swap: b = %d, c = %d\n", b, c);
    swap_by_reference(&b, &c);
    printf("after swap: b = %d, c = %d\n", b, c);    
    
    // 배열의 이름은 변수가 아닌 포인터
    // 원소의 갯수를 직접 지정할 필요는 없다.
    int arr[5] = {10, 20, 30, 40, 50};
    //arr == &arr[0] == 배열의 첫번째 원소의 주소값
    int *ptr_arr = arr; // arr은 배열의 이름이자 포인터. arr == &arr[0] == 배열의 첫번째 원소의 주소값

    // 포인터 주소 + 1은 다음 원소의 주소값이 된다.
    // 포인터 연산은 포인터가 가리키는 데이터 타입의 크기만큼 이동한다.
    printf("value of arr: %d\n", *ptr_arr);
    printf("value of arr: %d\n", *(ptr_arr+0));
    printf("value of arr: %d\n", *(ptr_arr+1));
    printf("value of arr: %d\n", *(ptr_arr+2));
    printf("value of arr: %d\n", *(ptr_arr+3));
    printf("value of arr: %d\n", *(ptr_arr+4));

    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    // 포인터를 이용해서 최솟값과 최댓값을 찾을 수 있다.
    int max, min;
    find_max_min(arr, n, &max, &min);
    printf("\nmax: %d, min: %d\n", max, min);

    // 포인터를 이용해서 배열의 모든 원소를 두배로 만들 수 있다.
    double_all(arr, n);
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

//함수
void add_one_by_value(int x){
    x = x +1;
}

void add_one_by_reference(int *x){
    *x = *x +1;
}

void swap_by_reference(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void find_max_min(int arr[], int n, int *max, int *min){
    *max = arr[0];
    *min = arr[0];

    for(int i=1;i<n;i++){
        if(arr[i] > *max){
            *max = arr[i];
        }
        if(arr[i] < *min){
            *min = arr[i];
        }
    }
}

void double_all(int arr[], int n){
    for(int i=0;i<n;i++){
        arr[i] = arr[i] * 2;
    }
}