#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#include "circular_deque.h"

int main(){

    Queue q;

    init_deque();

    for(int i = 0; i < 10; i++){
        if(i % 2 == 0){
            // 짝수와 홀수를 구분하는 이유는 add_rear와 add_front의 기능을 테스트하기 위해서입니다.
            // 짝수는 add_rear로 추가하고, 홀수는 add_front로 추가하여 양쪽에서 아이템이 추가되는 것을 확인할 수 있습니다.
            //만약 짝수를 add_front로 추가하고, 홀수를 add_rear로 추가한다면, 아이템이 추가되는 방향이 반대가 되어 테스트의 목적이 달성되지 않을 수 있습니다.
            //그래서 짝수는 add_rear로 추가하고, 홀수는 add_front로 추가하는 방식으로 테스트를 진행하는 것이 일반적입니다.
            add_rear(&q);
        } else {
            add_front(&q);
        }
    }
    
    print_deque("Deque after adding 10 items: ");

    return 0;
}