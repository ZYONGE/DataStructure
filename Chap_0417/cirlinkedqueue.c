#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#include "cirlinkedqueue.h"

int main(){
    init_queue();

    for(int i=0; i<7; i++){
        enqueue(i);
    }
    print_queue("enqueue 0~6");

    for(int i=0; i<3; i++){
        dequeue();
    }
    print_queue("dequeue 3 times");

    for(int i=7; i<10; i++){
        enqueue(i);
    }
    print_queue("enqueue 7~9");

    return 0;
}