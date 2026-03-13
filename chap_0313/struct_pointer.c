#include <stdio.h>

typedef struct{
    char name[50];
    int age;
    double gpa;
}Person;

int main(void){

    Person alice = {"Alice", 30, 4.23};
    Person *p = &alice;

    //파라미터를 던질때, 구조체의 값을 넘기는 것보다 포인터를 넘기는것이 훨씬 빠르다. 
    //값을 직접 넘기면 구조체의 크기만큼 메모리를 복사해야하기때문이다.
    printf("Name: %s, Age: %d, GPA: %.2f\n", p->name, p->age, p->gpa);
    printf("Name: %s, Age: %d, GPA: %.2f\n", alice.name, alice.age, alice.gpa);

    p -> age = 10;
    printf("Name: %s, Age: %d\n", p->name, p->age);

    Person class[] = {
        {"Bob", 25, 3.5},
        {"Charlie", 22, 3.8},
        {"David", 28, 3.2}
    };

    Person *ptr = class; // 배열의 첫 번째 요소를 가리키는 포인터

    for(int i = 0; i < 3; i++){
        printf("Name: %s, Age: %d, GPA: %.2f\n", ptr[i].name, ptr[i].age, ptr[i].gpa);
    }
    return 0;
}