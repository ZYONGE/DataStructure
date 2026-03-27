// 구조체를 포함하는 구조체와 구조체 배열 학습
// 주제: Call by Value vs Call by Reference의 차이점 이해

#include <stdio.h>
#include <stdlib.h>

// 복소수(Complex Number)를 나타내는 구조체 정의
// typedef를 사용하여 "struct Complex" 대신 "Complex"로 사용 가능
typedef struct{
    double real;    // 실수부
    double imag;    // 허수부
} Complex;

// Call by Value: 구조체의 복사본을 전달
// 함수 내에서 수정해도 원본에 영향 없음
void print_complex(Complex a){
    printf("실수부: %4.1lf, 허수부: %4.1lf \n", a.real, a.imag);
}

// Call by Value 예시: 함수 내 변경이 원본에 반영되지 않음
void reset_complex(Complex a){
    a.real  = a.imag = 0.0;  // a의 복사본만 변경됨
}

// Call by Reference: 포인터를 통해 원본 주소 전달
// 함수 내에서 수정하면 원본도 변경됨
void reset_complex_reference(Complex *a){
    a->real = a->imag = 0.0;  // 원본 직접 변경
}

int main(void){
    Complex a = {1.0, 2.0};  // 복소수 초기화

    printf("초기화 이전: \n");
    print_complex(a);

    // Call by Value: 원본이 변경되지 않음
    reset_complex(a);
    printf("초기화 이후: \n");
    print_complex(a);  // 여전히 {1.0, 2.0}

    // Call by Reference: 원본이 변경됨
    reset_complex_reference(&a);
    printf("call by reference 초기화 이후: \n");
    print_complex(a);  // {0.0, 0.0}으로 변경됨

    return 0;
}