#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    //real = 실수부, imag = 허수부
    float real;
    float imag;
} Complex;

void reset_complex(Complex *c);
void print_complex(Complex c);
Complex add(Complex a, Complex b);
Complex sub(Complex a, Complex b);
Complex mul(Complex a, Complex b);
Complex conj_complex(Complex c);

int main(void) {
    Complex a = {3.0f, 2.0f};
    Complex b = {1.0f, -4.0f};
    Complex result;


    printf("a = ");
    print_complex(a);

    printf("b = ");
    print_complex(b);

    result = add(a, b);
    printf("a + b = ");
    print_complex(result);

    result = sub(a, b);
    printf("a - b = ");
    print_complex(result);

    result = mul(a, b);
    printf("a * b = ");
    print_complex(result);

    result = conj_complex(a);
    printf("conj(a) = ");
    print_complex(result);

    reset_complex(&a);
    printf("reset a = ");
    print_complex(a);

    return 0;
}

void reset_complex(Complex *c) {
    c->real = 0.0f;
    c->imag = 0.0f;
}

void print_complex(Complex c) {
    if (c.imag >= 0.0f) {
        printf("%.2f + %.2fi\n", c.real, c.imag);
    } else {
        printf("%.2f - %.2fi\n", c.real, -c.imag);
    }
}

Complex add(Complex a, Complex b) {
    return (Complex){a.real + b.real, a.imag + b.imag};
}

Complex sub(Complex a, Complex b) {
    return (Complex){a.real - b.real, a.imag - b.imag};
}

Complex mul(Complex a, Complex b) {
    return (Complex){
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    };
}

Complex conj_complex(Complex c) {
    return (Complex){c.real, -c.imag};
}
