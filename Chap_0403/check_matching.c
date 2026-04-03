#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_matching(const char expr[]);

#define MAX_SIZE 80

typedef char Element;
#include "array_stack.h"

int main(void){

    char expr[4][80] = {
        {"({]})"},
        {"({[]})"},
        {"({[]{)"},
        {"(]})"}
    };

    for (int i = 0; i < 4; i++){
        int errCode = check_matching(expr[i]);

        if (errCode == 0){
            printf("%s -> 정상\n", expr[i]);
        }
        else{
            printf("%s -> 오류 (조건 %d 위반): ", expr[i], errCode);
            switch (errCode){
                case 1:
                    printf("Unmatched left parenthesis\n");
                    break;
                case 2:
                    printf("Unmatched right parenthesis\n");
                    break;
                case 3:
                    printf("Mismatched parenthesis\n");
                    break;
            }
        }
    }

    char expr2[100];
    printf("Enter an expression without spaces: ");
    scanf("%s", expr2);

    for (int i = 0; i < 100; i++){
        if (expr2[i] == '\n' || expr2[i] == '\0'){
            break;
        }
    }

    int errCode = check_matching(expr2);

    if (errCode == 0){
        printf("%s -> 정상\n", expr2);
    }
    else{
        printf("%s -> 오류 (조건 %d 위반): ", expr2, errCode);
        switch (errCode){
            case 1:
                printf("Unmatched left parenthesis\n");
                break;
            case 2:
                printf("Unmatched right parenthesis\n");
                break;
            case 3:
                printf("Mismatched parenthesis\n");
                break;
        }
    }

    return 0;
}

int check_matching(const char expr[]){

    char prev;
    const char *p = expr;

    init_stack();

    while(*p != '\0'){
        char ch = *p++;

        if (ch == '(' || ch == '{' || ch == '['){
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']'){
            if (is_empty()){
                return 2; // Unmatched right parenthesis
            }
            prev = pop();
            if ((ch == ')' && prev != '(') ||
                (ch == '}' && prev != '{') ||
                (ch == ']' && prev != '[')){
                return 3; // Mismatched parenthesis
            }
        }
    }

    if (!is_empty()){
        return 1; // Unmatched left parenthesis
    }else{
        return 0; // All parentheses are matched
    }

}
