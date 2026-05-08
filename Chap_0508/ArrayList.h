#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int Element;

#define MAX_SIZE 100

// 리스트의 데이터를 저장할 1차원 배열
Element data[MAX_SIZE];

// 현재 리스트에 저장된 항목의 총 개수
int size = 0;

// 에러 메시지 출력 후 프로그램 강제 종료
void error(char str[]){
    printf("%s\n", str);
    exit(1);
}

// 리스트 초기화: 원소의 개수를 0으로 설정하여 초기 상태로 만듦
void init_list(){
    size = 0;
}

// 리스트가 비어있는지 확인 (size가 0이면 비어있는 상태)
int is_empty(){
    return size == 0;
}

// 리스트가 꽉 찼는지 확인 (size가 배열의 최대 크기에 도달했는지 확인)
int is_full(){
    return size == MAX_SIZE;
}

// [핵심] 특정 위치(pos)에 새로운 데이터(e) 삽입
void insert(int pos, Element e){
    if (is_full()){
        error("overflow");
    }
    // 삽입 가능한 위치는 0부터 현재 size까지입니다. (size 위치에 넣으면 맨 끝에 추가됨)
    if(pos < 0 || pos > size){
        error("position error");
    }
    
    // 새 데이터가 들어갈 자리를 마련하기 위해, 맨 끝 데이터부터 pos 위치의 데이터까지 한 칸씩 뒤로(오른쪽으로) 이동시킵니다.
    for (int i = size - 1; i >= pos; i--){
        data[i + 1] = data[i];
    }
    
    // 자리가 비워진 pos 위치에 새 데이터를 넣고, 전체 개수(size)를 1 증가시킵니다.
    data[pos] = e;
    size++;
}

// [핵심] 특정 위치(pos)의 데이터를 삭제하고 반환
Element delete_entry(int pos){
    if (is_empty()){
        error("underflow");
    }
    if(pos < 0 || pos >= size){
        error("position error");
    }
    
    // 삭제할 데이터를 미리 백업해 둡니다.
    Element e = data[pos];
    
    // 삭제된 빈 공간을 메우기 위해, pos 바로 다음 위치부터 맨 끝 데이터까지 한 칸씩 앞으로(왼쪽으로) 당깁니다.
    for (int i = pos; i < size - 1; i++){
        data[i] = data[i + 1];
    }
    
    // 데이터 하나가 삭제되었으므로 전체 개수(size)를 1 감소시킵니다.
    size--;
    return e;
}

// 특정 위치(pos)의 데이터를 삭제하지 않고 값만 읽어옴
Element get_entry(int pos){
    if (is_empty()){
        error("underflow");
    }
    if(pos < 0 || pos >= size){
        error("Invalid position error");
    }
    return data[pos];
}

// 리스트의 맨 끝에 데이터 추가 (insert 함수 재활용)
void append(Element e){
    insert(size, e);
}

// 리스트 맨 끝의 데이터를 삭제하고 반환 (delete_entry 함수 재활용)
Element pop(){
    if (is_empty()){
        error("underflow");
    }
    return delete_entry(size - 1);
}

// 특정 위치(pos)의 데이터를 새로운 데이터(e)로 덮어쓰기(교체)
void replace(int pos, Element e){
    if (is_empty()){
        error("underflow");
    }
    if(pos < 0 || pos >= size){
        error("Invalid position error");
    }
    data[pos] = e;
}

// 특정 데이터(e)를 리스트에서 찾아 인덱스 반환 (없으면 -1 반환)
int find(Element e){
    for (int i = 0; i < size; i++){
        if (data[i] == e){
            return i;
        }
    }
    return -1;
}

// 리스트 내부의 현재 상태 출력
void print_list(char msg[]){
    printf("%s[%2d]\n", msg, size);
    printf("--------------------\n");
    for (int i = 0; i < size; i++){
        // 값이 들어간 위치(인덱스)도 함께 출력하도록 변경하면 확인하기 좋습니다.
        printf("배열 구조 리스트[%2d] = %d\n", i, data[i]);
    }
    printf("\n");
}

#endif