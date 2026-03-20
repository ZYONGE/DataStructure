#include <stdio.h>

void change_ptr(int **ptr, int *new_ptr);

//이중 포인터
int main(void) {

    // 연산자: & (주소 연산자), * (간접 참조 연산자), ** (이중 간접 참조 연산자)
    int a = 10;
    int *pa = &a;
    int **ppa = &pa;

    printf("%d\n", a);

    printf("%d\n", *pa);
    printf("%p\n", (void *)&pa);

    printf("%d\n", **ppa);
    printf("%p\n", (void *)&ppa);

    int b = 20;
    int c = 30;
    int *pb = &b;

    printf("%d\n", *pb);
    // pb의 &(주소): 이중 포인터, c의 &(주소): 일반 포인터
    // 주소의 주소를 변경하기 위해 매개변수로 주소를 인수로 사용하였음
    change_ptr(&pb, &c);
    printf("%d\n", *pb);



    // C언어 코드의 작동방식:
    // 컴파일 -> 링크 -> 실행
    return 0;

}

void change_ptr(int **ptr, int *new_ptr) {
    // 포인터의 주소를 변경하고 싶을땐 함수의 매개변수로 이중 포인터를 사용해야한다.
    *ptr = new_ptr;
}