#include <stdio.h>

typedef struct{
    char name[50];
    int age;
}Person;

int main(void){

    Person alice = {"Alice", 30};
    Person *p = &alice;

    //파라미터를 던질때, 구조체의 값을 넘기는 것보다 포인터를 넘기는것이 훨씬 빠르다. 
    //값을 직접 넘기면 구조체의 크기만큼 메모리를 복사해야하기때문이다.
    printf("Name: %s, Age: %d\n", p->name, p->age);
    printf("Name: %s, Age: %d\n", alice.name, alice.age);
    
    p -> age = 10;
    printf("Name: %s, Age: %d\n", p->name, p->age);

    return 0;
}