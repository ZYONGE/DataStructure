#include <stdio.h>
#include <stdlib.h>

typedef int Element;

#include "LinkedList.h"

int main(){
    init_list();
    append(1);
    append(2);
    append(3);
    print_list("After appending 1, 2, 3: ");
    
    insert(1, 4);
    print_list("After inserting 4 at position 1: ");
    
    replace(2, 5);
    print_list("After replacing element at position 2 with 5: ");
    
    Element e = pop();
    printf("Popped element: %d\n", e);
    print_list("After popping last element: ");
    
    return 0;
}