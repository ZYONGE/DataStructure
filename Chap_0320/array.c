#include <stdio.h>
#include <string.h>

int my_strlen(const char* s);
void my_strcpy(char* dest, const char* src);

int main(void) {

    char str[] = "Hello, World!";
    char str2[20];
    char str3[20];

    printf("%s\n", str);
    printf("len = %d\n", strlen(str)); //C언어 기본 제공 함수. strlen() : 문자열의 길이를 반환하는 함수.
    printf("len = %d\n", my_strlen(str));//strlen은 unsigned long 타입을 반환하지만, 여기서는 int로 출력하기 위해 %d를 사용

    strcpy(str, str2); //strcpy() : 문자열을 복사하는 함수. str2에 str의 내용을 복사함.
    printf("%s\n", str2);
    my_strcpy(str2, str3);
    printf("%s\n", str3);

    return 0;
}

//const: 문자열을 변경할 수 없도록 하는 키워드. 문자열 리터럴은 const char* 타입으로 취급됨.
//literal: 프로그램에서 직접 작성된 문자열이나 숫자 등의 고정된 값을 의미함. 예시에서는 "Hello, World!"가 문자열 리터럴임.
int my_strlen(const char* s) {

    int len = 0;
    // 문자열의 끝을 나타내는 null 문자('\0')를 만날 때까지 반복하여 문자열의 길이를 계산함.
    while (s[len] != '\0') {
        len++;
        s++; // 문자열 포인터를 다음 문자로 이동시킴.
    }
    return len;
}

void my_strcpy(char* dest, const char* src) {
    // src 문자열의 끝을 나타내는 null 문자('\0')를 만날 때까지 반복하여 src의 내용을 dest로 복사함.
    while (*src != '\0') {
        *dest = *src; // src가 가리키는 문자를 dest가 가리키는 위치에 복사함.
        dest++; // dest 포인터를 다음 위치로 이동시킴.
        src++;  // src 포인터를 다음 위치로 이동시킴.
    }
    *dest = '\0'; // 복사가 끝난 후 dest의 마지막에 null 문자를 추가하여 문자열을 종료함.
}

