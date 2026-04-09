#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

int degree(Poly p){
    return p.degree;
}
float coefficient(Poly p, int i){
    return p.coef[i];
}

float evaluate(Poly p, float x){
    float result = p.coef[0];
    int mul; //반복문이 거듭될 수록 x가 곱해짐 =x의 n(반복횟수)제곱
    for(int i=1;i<p.degree+1;i++){
        mul *= x;
        result += p.coef[i] * x;
    }
    return result;
}

Poly add(Poly a, Poly b){
    Poly p;
    p.degree = (a.degree > b.degree) ? a.degree : b.degree;

    for(int i=0;i<p.degree+1;i++){
        p.coef[i] = ((i <= a.degree) ? a.coef[i] : 0) + ((i <= b.degree) ? b.coef[i] : 0);
    }
    return p;
}

void print_poly(Poly p, char str[]){
    printf("%s: ",str);
    for(int i=p.degree; i>0; i--){
        printf("%5.1f x^ %d", p.coef[i], i);
    }
}
