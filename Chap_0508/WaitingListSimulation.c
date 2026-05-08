#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Waiting{
    int id;
    int nperson;
    char info[32];
} ;

typedef struct Waiting Element;

#define ELEMENT_IS_STRUCT
#include "DoubleLinkedList.h"

// 리스트의 현재 크기를 구하는 보조 함수
int get_size() {
    int count = 0;
    DNode* p = org.next;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void reserve(int nperson, const char info[]){
    static int id = 1;
    Element e;
    e.id = id++;
    e.nperson = nperson;
    strcpy(e.info, info);
    append(e); // 맨 끝에 추가

    printf("<Enrollment> id: %d, nperson: %d, info: %s\n", e.id, e.nperson, e.info);
}

void find(int wid)
{
    int nTeam = 0, nPeople = 0;
    for(int pos = 0; pos < get_size(); pos++){
        Element e = get_entry(pos);
        if(e.id == wid){
            printf("<Find> id: %d, nperson: %d, info: %s (앞에 %d팀, %d명 대기 중)\n", e.id, e.nperson, e.info, nTeam, nPeople);
            return;
        }
        nTeam++;
        nPeople += e.nperson;
    }
    printf("<Find> id: %d not found.\n", wid);
}

void delay(int wid)
{
    for(int pos = 0; pos < get_size(); pos++){
        Element e = get_entry(pos);
        if(e.id == wid){
            printf("<Delay> id: %d, nperson: %d, info: %s\n", e.id, e.nperson, e.info);
            delete_entry(pos); // 기존 위치에서 삭제
            append(e);         // 순서를 맨 뒤로 미룸
            return;
        }
    }
    printf("<Delay> id: %d not found.\n", wid);
}

void cancel(int wid){
    for(int pos = 0; pos < get_size(); pos++){
        Element e = get_entry(pos);
        if(e.id == wid){
            printf("<Cancel> id: %d, nperson: %d, info: %s\n", e.id, e.nperson, e.info);
            delete_entry(pos);
            return;
        }
    }
    printf("<Cancel> id: %d not found.\n", wid);
}

void print(){
    printf("Waiting List\n");
    printf("ID\tNPerson\tInfo\n");
    for(int pos = 0; pos < get_size(); pos++){
        Element e = get_entry(pos);
        printf("%d\t%d\t%s\n", e.id, e.nperson, e.info);
    }
    printf("\n");
}

void service(){
    if (is_empty()) {
        printf("<Service> No one is waiting.\n");
        return;
    }
    Element e = delete_entry(0); // delete_entry 사용, Elemente 오타 수정
    printf("<Service> id: %d, nperson: %d, info: %s\n", e.id, e.nperson, e.info);
}

void modify(int wid, const char info[]){
    for(int pos = 0; pos < get_size(); pos++){
        Element e = get_entry(pos);
        if(e.id == wid){
            strcpy(e.info, info); // info 수정
            replace(pos, e);      // 수정된 Element를 리스트에 덮어씀
            printf("<Modify> id: %d, nperson: %d, info: %s\n", e.id, e.nperson, e.info);
            return;
        }
    }
    printf("<Modify> id: %d not found.\n", wid);
}

int main(){
    init_list(); // 리스트 초기화 필수

    reserve(4, "010-1234-5678");
    reserve(2, "010-5678-1234");
    reserve(3, "010-9012-3456");
    print();

    service();
    print();

    delay(2);
    print();
    cancel(1);
    print();
    
    modify(3, "010-0000-0000");
    print();


    return 0;
}