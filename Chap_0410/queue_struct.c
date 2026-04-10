#include <stdio.h>
#include <stdlib.h>

//이 문장의 의미는
//Element는 int 타입의 별칭입니다.
//즉, Element라는 이름은 int 타입을 가리키며,
//코드에서 Element를 사용할 때마다 int로 간주됩니다.
typedef int Element;

#include "queue_struct.h"

int main(){

    Queue q;

    init_queue(&q);

    for(int i = 1; i <= 4; i++){
        enqueue(&q, i);
    }
    print_que(&q, "큐에 1~4까지 삽입 후");

    for(int i = 0; i < 2; i++){
        printf("dequeue: %d\n", dequeue(&q));
    }
    print_que(&q, "큐에서 2개 제거 후");

    for(int i = 5; i <= 7; i++){
        enqueue(&q, i);
    }
    print_que(&q, "큐에 5~7까지 삽입 후");

    return 0;
}