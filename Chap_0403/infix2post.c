//중위 연산을 후위 연산으로 변환하는 프로그램
#include <stdio.h>
#include <stdlib.h>

int precedence(char op);
void infix_to_postfix(char exp[]);

typedef char Element;
#define MAX_SIZE 80
#include "array_stack.h"

int main(){

    char expr[2][80] = {
        {"8/2-3+(3*2)"},
        {"1/2*4*(1/4)"}
    };

    printf("중위수식 %s ==> 후위수식:", expr[0]);
    infix_to_postfix(expr[0]);

    printf("중위수식 %s ==> 후위수식:", expr[1]);
    infix_to_postfix(expr[1]);

    return 0;
}

int precedence(char op){
    switch (op){
        case '(':
        case ')':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1; //연산자가 아닌 경우
}

void infix_to_postfix(char expr[]){

    init_stack();
    int i=0;

    while(expr[i]!='\0'){
        char c = expr[i++];

        if (c >= '0' && c <= '9'){ //피연산자
            printf("%c ", c);
        }
        else if (c == '('){
            push(c);
        }
        else if (c == ')'){
            while (is_empty()==0){
                char op = pop();
                if (op == '('){
                    break;
                }else{
                    printf("%c ", c);
                }
            }
            pop(); // '(' 제거
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/'){ //연산자
            while (!is_empty() == 0){
                char op = peek();
                if (precedence(op) >= precedence(c)){
                    printf("%c ", op);
                    pop();
                } else {
                    break;
                }
            }
            push(c);
        }
    }
    while(is_empty() == 0){
        printf("%c ", peek());
        pop();
    }
    printf("\n");
}
