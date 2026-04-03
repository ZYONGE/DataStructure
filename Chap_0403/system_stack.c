#include <stdio.h>
#include <stdlib.h>

void a();
void b();
void c();
void d();

int main(void){
    a();
    b();
    c();
    return 0;
}
// system stack: 함수 호출 시마다 시스템이 자동으로 관리하는 메모리 영역
// 시스템 스택은 함수 호출 시마다 함수의 매개변수, 지역 변수, 반환 주소 등을 저장하는 데 사용
// 시스템 스택은 함수 호출이 끝나면 자동으로 정리되고, 함수가 반환될 때마다 이전 상태로 돌아감
// 시스템 스택은 함수 호출이 중첩될 때마다 새로운 스택 프레임이 생성되고, 함수가 반환될 때마다 해당 프레임이 제거됨
// 시스템 스택은 함수 호출이 깊어질수록 더 많은 메모리를 사용하게 되며, 너무 깊은 호출이 발생하면 스택 오버플로우가 발생할 수 있음

void a(){
    d();
    return;
}
void b(){
    a();
    return;
}
void c(){
    b();
    return;
}
void d()
{
    return;
}