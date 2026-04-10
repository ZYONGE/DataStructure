#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct QUEUE{
    Element data [MAX_SIZE];
    int front;
    int rear;
} Queue;
//구조체를 정의하고 매개변수를 포인터로 받는이유는:
//구조체를 정의할 때, 큐의 데이터를 저장하기 위한 배열과 큐의 상태를 나타내는 front와 rear 인덱스를 포함합니다.
//매개변수를 포인터로 받는 이유는 함수가 큐의 상태를 직접 수정할 수 있도록 하기 위함입니다. 포인터를 사용하면 함수 내에서
//큐의 front와 rear 값을 변경할 수 있으며, 이는 큐의 상태를 유지하는 데 필수적입니다. 만약 매개변수를 포인터로 받지 않는다면
//함수 내에서 큐의 상태를 변경할 수 없게 되어 큐의 기능을 제대로 구현할 수 없습니다.
void error(char str[]){
    printf("%s\n", str);
    exit(1);
}
void init_queue(Queue *q){
    q->front = q->rear = 0;
}
int is_empty(Queue *q){
    return q->front == q->rear;
}
int is_full(Queue *q){
    return q->front == (q->rear + 1) % MAX_SIZE;
}

//enqueue: 큐에 아이템을 추가하는 함수입니다. 큐가 가득 찼는지 확인한 후, rear 인덱스를 다음 위치로 이동시키고 새 아이템을 큐에 추가합니다.
void enqueue(Queue *q, Element item){
    if(is_full(q)){
        error("Overflow");
    }
    q->rear = (q->rear + 1) % MAX_SIZE; // rear를 다음 위치로 이동
    q->data[q->rear] = item; // 새 아이템을 큐에 추가
}

//dequeue: 큐에서 아이템을 제거하고 반환하는 함수입니다. 큐가 비어있는지 확인한 후, front 인덱스를 다음 위치로 이동시키고 해당 위치의 아이템을 반환합니다.
Element dequeue(Queue *q){
    if(is_empty(q)){
        error("Underflow");
    }
    q->front = (q->front + 1) % MAX_SIZE; // front를 다음 위치로 이동
    return q->data[q->front]; // 큐에서 아이템을 제거하고 반환
}
//enqueue가 void, dequeue가 Element를 반환하는 이유는 각각의 함수가 수행하는 작업과 관련이 있습니다.
//enqueue는 큐에 아이템을 추가하는 작업을 수행하며, 이 작업은 성공적으로 완료되면 특별한 값을 반환할 필요가 없습니다.
//따라서 void로 선언되어 있습니다. 반면에 dequeue는 큐에서 아이템을 제거하고 반환하는 작업을 수행합니다.
//이 함수는 제거된 아이템을 반환해야 하므로 Element 타입으로 선언되어 있습니다.

Element peek(Queue *q){
    if(is_empty(q)){
        error("Underflow");
    }
    return q->data[(q->front + 1) % MAX_SIZE]; // 큐의 front 다음 위치에 있는 아이템을 반환
}

void print_que(Queue *q, char msg[]){
    printf("%s front = %d rear = %d\n", msg, q->front, q->rear);

    // 큐의 크기를 계산하여 큐에 있는 모든 요소를 출력합니다.
    // 큐의 크기는 rear와 front의 차이를 MAX_SIZE로 나눈 나머지로 계산됩니다.
    // 쉽게 설명하면, rear가 front보다 크면 큐에 있는 요소의 수는 rear - front입니다.
    // rear가 front보다 작거나 같으면 큐에 있는 요소의 수는 rear - front + MAX_SIZE입니다.

    int size = (q->rear - q->front + MAX_SIZE) % MAX_SIZE;
    for(int i = 1; i <= size; i++){
        printf("%d ", q->data[(q->front + i) % MAX_SIZE]);
    }
    printf("\n");   
}