#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

int main(){
    Poly a = {5, {3,6,0,0,0,10}};
    Poly b = {4 ,{7,0,5,0,1}};
    Poly c = add(a, b);

    print_poly(a, "A= ");
    print_poly(b, "B= ");
    print_poly(c, "A+B= ");
    printf("A(1) = ",evaluate(a, 1.0f));
    printf("B(2) = ",evaluate(a, 2.0f));

    return 0;
}