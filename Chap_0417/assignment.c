#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#include "assignment.h"

int main() {
    init_deque();

    // 뒤에 삽입
    for (int i = 1; i <= 5; i++)
        push_rear(i);
    print_forward("push_rear 1~5");
    print_backward("push_rear 1~5");

    // 앞에 삽입
    push_front(0);
    push_front(-1);
    print_forward("push_front 0, -1");
    print_backward("push_front 0, -1"); // 역방향으로 이중연결 확인

    // 앞/뒤 삭제
    printf("\npop_front: %d\n", pop_front());
    printf("pop_rear : %d\n", pop_rear());
    print_forward("after pop_front & pop_rear");
    print_backward("after pop_front & pop_rear");

    // 앞/뒤 peek
    printf("\npeek_front: %d\n", peek_front());
    printf("peek_rear : %d\n", peek_rear());

    destroy_deque();
    return 0;
}
