// 다항식을 배열 기반으로 표현하는 예제
// coeff[i]는 x^i 항의 계수를 의미한다.
// 예: 3 + 6x + 10x^5 -> coeff[0]=3, coeff[1]=6, coeff[5]=10

#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 1001

typedef struct{
    // 다항식의 최고차수
    int degree;
    // 각 차수의 계수 배열 (인덱스가 곧 차수)
    float coeff[MAX_DEGREE];
}Polynomial;

// 다항식 기본 연산/조회 함수 선언
int degree(Polynomial p);
float coefficient(Polynomial p, int d);
float evaluate(Polynomial p, float x);
Polynomial add(Polynomial a, Polynomial b);
void print_poly(Polynomial p, char *str);


int main(void){

    // a(x) = 3 + 6x + 10x^5
    Polynomial a = {5, {3, 6, 0, 0, 0, 10}}; //3 + 6x + 10x^5
    // b(x) = 7 + 5x^2 + x^4
    Polynomial b = {4, {7, 0, 5, 0, 1}}; //7 + 5x^2 + x^4
    // c(x) = a(x) + b(x)
    Polynomial c = add(a, b);

    print_poly(a, "A = ");
    print_poly(b, "B = ");
    print_poly(c, "A + B = ");

    printf("A(1) = %f\n", evaluate(a, 1.0f));
    printf("B(1) = %f\n", evaluate(b, 2.0f));

    return 0;
}

int degree(Polynomial p){
    // 다항식의 최고차수 반환
    return p.degree;
}

float coefficient(Polynomial p, int d){
    // d차항의 계수 반환
    return p.coeff[d];
}

float evaluate(Polynomial p, float x){
    // p(x) = sum(coeff[i] * x^i)
    float result = p.coeff[0]; // 상수항부터 시작
    float mul = 1;

    // 각 차수에 대해 x^i 계산과 계수 곱셈 수행
    // i=1부터 시작하여 최고차수까지 반복
    //쉽게 말해서, x^i는 x^(i-1) * x로 계산할 수 있으므로, mul을 이용해 누적 곱셈을 수행
    for (int i = 1; i <= p.degree; i++) {
        mul *= x;
        result += p.coeff[i] * mul;
    }
    return result;
}

Polynomial add(Polynomial a, Polynomial b){
    // 두 다항식의 합을 계산하여 반환
    Polynomial p;
    // 최고차수는 두 다항식 중 큰 차수로 설정
    p.degree = (a.degree > b.degree) ? a.degree : b.degree;

    // 각 차수에 대해 a와 b의 계수를 더하여 p의 계수로 설정
    // i가 a 또는 b의 차수 범위 내에 있는 경우 해당 계수를 사용하고, 그렇지 않은 경우 0으로 간주하여 더함
    // 예: a의 2차항이 존재하지 않으면 0으로 간주하여 b의 2차항 계수만 더함
    // i=0부터 최고차수까지 반복하여 각 차수의 계수를 계산
    for (int i = 0; i <= p.degree; i++) {
        p.coeff[i] = ((i <= a.degree) ? a.coeff[i] : 0) + \
                     ((i <= b.degree) ? b.coeff[i] : 0);
    }
    return p;
}

void print_poly(Polynomial p, char *str){
    // 높은 차수부터 출력해 일반적인 수학 표기 형태로 표현
    printf("%s", str);
    for (int i = p.degree; i >= 0; i--) {
        printf("%5.1fx^%d ", p.coeff[i], i);
    }
    //상수를 출력하는 printf
    printf("%5.1f", p.coeff[0]);
    printf("\n");
}