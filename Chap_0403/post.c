// 사람들은 중위 표기법을 선호하지만,
// 컴퓨터는 후위 표기법을 선호한다.
// 그 이유는 후위 표기법에서는 연산자의 우선순위를 고려할 필요가 없기 때문이다.
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

double eval_postfix(const char expr[]);

typedef double Element;
#include "array_stack.h"

int main(){

    char expr[2][80] = {
        {"82/3-32*+"},
        {"12/4*14/*"}
    };

    printf("식: %s = %lf\n", expr[0], eval_postfix(expr[0]));
    printf("식: %s = %lf\n", expr[1], eval_postfix(expr[1]));

    return 0;
}

double eval_postfix(const char expr[]){
    int i=0;
    init_stack();

    while (expr[i] != '\0'){
        char c = expr[i++];

        if(c >= '0' && c <= '9'){ //아스키코드: '0'부터 '9' 사이의 값은 숫자 (피연산자)
            double num = (double)(c - '0'); //문자 '0'의 아스키 코드 값을 빼면 실제 숫자 값이 된다.
            push(num);
        }else if(c == '+' || c == '-' || c == '*' || c == '/'){ //연산자
            double val1 = pop();
            double val2 = pop();

            switch(c){
                case '+':
                    push(val1 + val2);
                    break;
                case '-':
                    push(val1 - val2);
                    break;
                case '*':
                    push(val1 * val2);
                    break;
                case '/':
                    push(val1 / val2);
                    break;
            };
        }
    }

    return pop();
}