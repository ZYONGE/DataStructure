#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef struct Pos2D {
    int r;
    int c;
} Element;

Element data[MAX_SIZE];

int front;
int rear;

void error(char str[]){
    printf("%s\n", str);
    exit(1);
}
void init_queue(){
    front = rear = 0;
}
int is_empty(){
    return front == rear;
}
int is_full(){
    return front == (rear + 1) % MAX_SIZE;
}

void enqueue(Element item){
    if(is_full()){
        error("Overflow");
    }
    rear = (rear + 1) % MAX_SIZE;
    data[rear] = item;
}

Element dequeue(){
    if(is_empty()){
        error("Underflow");
    }
    front = (front + 1) % MAX_SIZE;
    return data[front];
}

Element peek(){
    if(is_empty()){
        error("Underflow");
    }
    return data[(front + 1) % MAX_SIZE];
}

void print_que(char msg[]){
    printf("%s front = %d rear = %d\n", msg, front, rear);

    int size = (rear - front + MAX_SIZE) % MAX_SIZE;
    for(int i = 0; i < size; i++){
        Element item = data[(front + 1 + i) % MAX_SIZE];
        printf("(%d,%d) ", item.r, item.c);
    }
    printf("\n");   
}

void init_deque(void) {
    init_queue();
}
void add_rear(Element val) {
    enqueue(val);
}
Element delete_front(void) {
    return dequeue();
}
Element get_front(void) {
    return peek();
}
void add_front(Element val) {
    if(is_full()){
        error("Overflow");
    }
    front = (front - 1 + MAX_SIZE) % MAX_SIZE;
    data[front] = val;
}
Element delete_rear(void) {
    if(is_empty()){
        error("Underflow");
    }
    Element item = data[rear];
    rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    return item;
}
Element get_rear(void) {
    if(is_empty()){
        error("Underflow");
    }
    return data[rear];
}
void print_deque(char msg[]){
    printf("%s front = %d rear = %d\n", msg, front, rear);

    int size = (rear - front + MAX_SIZE) % MAX_SIZE;
    for(int i = 0; i < size; i++){
        Element item = data[(front + 1 + i) % MAX_SIZE];
        printf("(%d,%d) ", item.r, item.c);
    }
    printf("\n");   
}