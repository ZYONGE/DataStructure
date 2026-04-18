/* 이중연결리스트 덱 (Double-ended Queue) */
typedef struct Node {
    Element data;
    struct Node *prev; // 이전 노드
    struct Node *next; // 다음 노드
} Node;

Node *head = NULL; // 덱의 front
Node *tail = NULL; // 덱의 rear

Node *alloc_node(Element e) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->prev = p->next = NULL;
    return p;
}

Element free_node(Node *p) {
    Element e = p->data;
    free(p);
    return e;
}

void error(char str[]) {
    printf("%s\n", str);
    exit(1);
}

int is_empty() { return head == NULL; }

void init_deque() { head = tail = NULL; }

/* 앞에 삽입 */
void push_front(Element e) {
    Node *p = alloc_node(e);
    if (is_empty()) {
        head = tail = p;
    } else {
        p->next = head;
        head->prev = p; // head의 prev 연결 (이중연결)
        head = p;
    }
}

/* 뒤에 삽입 */
void push_rear(Element e) {
    Node *p = alloc_node(e);
    if (is_empty()) {
        head = tail = p;
    } else {
        tail->next = p;
        p->prev = tail; // tail의 next가 p, p의 prev가 tail (이중연결)
        tail = p;
    }
}

/* 앞에서 삭제 */
Element pop_front() {
    if (is_empty()) error("Deque underflow");
    Node *p = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL; // 앞 노드 끊기
    }
    return free_node(p);
}

/* 뒤에서 삭제 */
Element pop_rear() {
    if (is_empty()) error("Deque underflow");
    Node *p = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL; // 뒤 노드 끊기
    }
    return free_node(p);
}

Element peek_front() {
    if (is_empty()) error("Deque underflow");
    return head->data;
}

Element peek_rear() {
    if (is_empty()) error("Deque underflow");
    return tail->data;
}

void destroy_deque() {
    while (!is_empty()) pop_front();
}

/* 정방향 출력 (head → tail) */
void print_forward(char *msg) {
    printf("[정방향] %s: ", msg);
    for (Node *p = head; p != NULL; p = p->next)
        printf("%d ", p->data);
    printf("\n");
}

/* 역방향 출력 (tail → head, prev 포인터 활용) */
void print_backward(char *msg) {
    printf("[역방향] %s: ", msg);
    for (Node *p = tail; p != NULL; p = p->prev)
        printf("%d ", p->data);
    printf("\n");
}
