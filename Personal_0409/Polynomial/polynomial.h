#define MAX 1000

typedef struct{
    int degree;
    float coef[MAX];
}Poly;

int degree(Poly p);

float coefficient(Poly p, int i);

float evaluate(Poly p, float x);

Poly add(Poly a, Poly b);

void print_poly(Poly p, char str[]);
