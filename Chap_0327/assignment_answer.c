#include <stdio.h>
#include <math.h>

// 복소수 구조체 정의
typedef struct {
    double real;    // 실수부
    double imag;    // 허수부
} Complex;

// 복소수 덧셈: a + b를 반환
Complex add(Complex a, Complex b)
{
    Complex result;
    result.real=a.real+b.real;
    result.imag=a.imag+b.imag;
    return result;
}

// 복소수 뺄셈: a - b를 반환
Complex sub(Complex a, Complex b)
{
    Complex result;
    result.real=a.real-b.real;
    result.imag=a.imag-b.imag;
    return result;
}

// 복소수 곱셈: a * b를 반환
// (a+bi)(c+di) = (ac-bd) + (ad+bc)i
Complex mul(Complex a, Complex b)
{
    Complex result;
    result.real=a.real*b.real-a.imag*b.imag;
    result.imag=a.real*b.imag+a.imag*b.real;
    return result;
}

// 복소수의 크기(절대값) 반환
double magnitude(Complex c)
{
    return sqrt(c.real*c.real+c.imag*c.imag);
}

// 복소수의 켤레(conjugate) 반환
Complex conjugate(Complex c)
{
    Complex result;
    result.real=c.real;
    result.imag=-c.imag;
    return result;
}

// 복소수를 초기화하는 함수 (call-by-value이므로 원본 변경 안됨)
void reset_complex(Complex c)
{
    c.real=c.imag=0.0;  // 원래 복소수는 변경되지 않음
}

// 복소수를 화면에 출력
void print_complex(Complex c, char str[])
{
    printf("%s", str);
    if (c.imag>=0)
        printf("%.1f + %.1fi\n", c.real, c.imag);
    else
        printf("%.1f - %.1fi\n", c.real, -c.imag);
}

int main()
{
    Complex a= { 3.0, 4.0 };      // 3 + 4i
    Complex b= { 1.5, -2.0 };     // 1.5 - 2i

    Complex c=add(a, b);          // 덧셈
    Complex d=sub(a, b);          // 뺄셈
    Complex e=mul(a, b);          // 곱셈
    Complex f=conjugate(a);       // 켤레 복소수

    print_complex(a, " A = ");
    print_complex(b, " B = ");
    print_complex(c, " A+B = ");
    print_complex(d, " A-B = ");
    print_complex(e, " A*B = ");
    print_complex(f, " conj(A) = ");

    printf(" |A| = %.6f\n", magnitude(a));
    printf(" |B| = %.6f\n", magnitude(b));

    // call-by-value 테스트
    printf("\n--- call-by-value 테스트 ---\n");
    print_complex(a, " reset 전 A = ");
    reset_complex(a);   // 원본은 변경되지 않음
    print_complex(a, " reset 후 A = ");

    return 0;
}