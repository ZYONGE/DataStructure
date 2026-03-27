//희소 다항식을 표현하는 코드
//0이 아닌 항만 저장하여 메모리를 절약하고, 병합 방식으로 효율적인 덧셈을 수행한다.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 다항식의 항의 최대 개수
#define MAX_TERMS 1001

//항을 최고차항 내림차순으로 저장하는 구조체
// 표현 예시: 10x^5 + 6x + 3 -> terms[0] = {5, 10}, terms[1] = {1, 6}, terms[2] = {0, 3}
typedef struct {
    int exp; // 항의 차수
    float coef; // 항의 계수
} Term;

typedef struct {
    int degree; // 다항식의 최고차수
    int num_terms; // 다항식의 항의 개수
    Term terms[MAX_TERMS]; // 다항식의 항 배열 (내림차순으로 정렬 유지)
} SparsePoly;

// 희소 다항식의 기본 연산/조회 함수 선언
float evaluate(SparsePoly p, float x);
SparsePoly add(SparsePoly a, SparsePoly b);
void print_spoly(SparsePoly p, char str[]);

int main(void){
    // 다항식 A: 10x^5 + 6x + 3 초기화
    SparsePoly a = {5, 3, {{5, 10.0f}, {1, 6.0f}, {0, 3.0f}}};
    print_spoly(a, "A = ");
    
    // 다항식 B: x^4 + 5x^2 + 7 초기화
    SparsePoly b = {4, 3, {{4, 1.0f}, {2, 5.0f}, {0, 7.0f}}};
    print_spoly(b, "B = ");
    
    // A와 B의 합을 계산하여 C에 저장
    SparsePoly c = add(a, b);
    print_spoly(c, "A + B = ");

    return 0;
}

// 희소 다항식 p를 x값에 대해 계산하는 함수
// 0이 아닌 항들만 존재하므로 p.num_terms번만 반복 (효율적)
float evaluate(SparsePoly p, float x){
    float result = 0.f; // 결과값 초기화

    // 모든 0이 아닌 항들을 순회하며 항의 값(계수 * x^차수)을 누적
    for (int i = 0; i < p.num_terms; i++) {
        result += p.terms[i].coef * pow(x, p.terms[i].exp);
    }

    return result;
}

// 두 희소 다항식 a와 b를 더하는 함수
// 시간복잡도: O(m + n) (m, n은 각 다항식의 항의 개수)
// 병합(merge) 방식: 두 개의 정렬된 배열을 한 번에 순회하며 병합
SparsePoly add(SparsePoly a, SparsePoly b){
    SparsePoly c; // 결과 다항식
    c.num_terms = 0; // 결과 다항식 항의 개수 초기화

    // i: a의 인덱스, j: b의 인덱스
    // a와 b의 모든 항을 내림차순으로 처리하며 병합
    for(int i = 0, j = 0; i < a.num_terms || j < b.num_terms;){
        
        // Case 1: a가 끝났거나 a의 현재 차수 < b의 현재 차수 (내림차순이므로 a가 작음)
        // -> b의 항을 결과에 추가 및 j 증가
        if (i == a.num_terms || a.terms[i].exp < b.terms[j].exp) {
            c.terms[c.num_terms++] = b.terms[j++];
        } 
        // Case 2: b가 끝났거나 a의 현재 차수 > b의 현재 차수 (내림차순이므로 a가 큼)
        // -> a의 항을 결과에 추가 및 i 증가
        else if (j == b.num_terms || a.terms[i].exp > b.terms[j].exp) {
            c.terms[c.num_terms++] = a.terms[i++];
        } 
        // Case 3: 두 다항식의 같은 차수 항을 만남
        // -> 계수를 더한 후 결과에 추가 (0이면 자동 제외됨)
        else {
            c.terms[c.num_terms] = a.terms[i++];
            c.terms[c.num_terms++].coef += b.terms[j++].coef;
        }
    }
    return c; // 더해진 다항식 반환
}

// 희소 다항식을 문자열 str과 함께 출력하는 함수
// 0이 아닌 항들만 출력 (희소성 활용)
void print_spoly(SparsePoly p, char str[]){
    printf("%s", str); // 레이블 출력 (예: "A = ")

    // 0이 아닌 항들을 순회하며 출력
    for (int i = 0; i < p.num_terms; i++) {
        printf("%5.1fx^%d ", p.terms[i].coef, p.terms[i].exp);
        if (p.terms[i].exp > 0) {
            // 마지막 항이 아니면 "+" 기호 추가
            if(i != p.num_terms - 1) {
                printf("+ ");
            }
        }
        printf("\n");
    }
    printf("\n"); // 빈 줄 출력
}