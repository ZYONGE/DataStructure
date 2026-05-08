typedef struct DNode{
    Element data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

DNode org;

DNode *alloc_dnode(Element e){
    DNode *new_node = (DNode *)malloc(sizeof(DNode));
    new_node->data = e;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

Element free_dnode(DNode *node){
    Element e = node->data;
    free(node);
    return e;
}

void error(char str[]){
    printf("%s\n", str);
    exit(1);
}

// 리스트 초기화: 원소의 개수를 0으로 설정하여 초기 상태로 만듦
void init_list(){
    org.next = NULL;
    org.prev = NULL;
}

// 리스트가 비어있는지 확인
int is_empty(){
    return org.next == NULL;
}

// 연결 리스트는 메모리가 허용하는 한 꽉 차지 않음
int is_full(){
    return 0;
}

// 특정 위치의 노드를 반환하는 보조 함수
DNode* get_node(int pos) {
    DNode* p = &org;
    for (int i = -1; i < pos; i++) {
        if (p == NULL) break;
        p = p->next;
    }
    return p;
}

Element delete(int pos){
    DNode *p = get_node(pos);
    if (p == NULL) error("position error");
    DNode *prev = p->prev;
    DNode *next = p->next;
    if (prev != NULL) prev->next = next;
    if (next != NULL) next->prev = prev;
    return free_dnode(p);
}

// [핵심] 특정 위치(pos)에 새로운 데이터(e) 삽입
void insert(int pos, Element e){
    DNode* prev = get_node(pos - 1);
    if (prev == NULL) error("position error");

    DNode* new_node = alloc_dnode(e);
    new_node->next = prev->next;
    new_node->prev = prev;
    if (prev->next != NULL) {
        prev->next->prev = new_node;
    }
    prev->next = new_node;
}

// [핵심] 특정 위치(pos)의 데이터를 삭제하고 반환
Element delete_entry(int pos){
    DNode* curr = get_node(pos);
    if (curr == NULL || curr == &org) error("position error");

    DNode* prev = curr->prev;
    DNode* next = curr->next;

    if (prev != NULL) prev->next = next;
    if (next != NULL) next->prev = prev;

    return free_dnode(curr);
}

// 특정 위치(pos)의 데이터를 삭제하지 않고 값만 읽어옴
Element get_entry(int pos){
    DNode* curr = get_node(pos);
    if (curr == NULL || curr == &org) error("Invalid position error");
    return curr->data;
}

// 리스트의 맨 끝에 데이터 추가
void append(Element e){
    DNode* p = &org;
    while (p->next != NULL) {
        p = p->next;
    }
    DNode* new_node = alloc_dnode(e);
    new_node->prev = p;
    p->next = new_node;
}

// 특정 위치(pos)의 데이터를 새로운 데이터(e)로 덮어쓰기(교체)
void replace(int pos, Element e){
    DNode* curr = get_node(pos);
    if (curr == NULL || curr == &org) error("Invalid position error");
    curr->data = e;
}

// 특정 데이터(e)를 리스트에서 찾아 인덱스 반환 (없으면 -1 반환)
int find(Element e){
    DNode* p = org.next;
    for (int i = 0; p != NULL; i++) {
        if (p->data == e) {
            return i;
        }
        p = p->next;
    }
    return -1;
}

// 리스트 내부의 현재 상태 출력
void print_list(char msg[]){
    int size = 0;
    DNode* p = org.next;
    while(p != NULL) {
        size++;
        p = p->next;
    }

    printf("%s[%2d]\n", msg, size);
    printf("--------------------\n");
    p = org.next;
    for (int i = 0; p != NULL; i++){
        printf("이중연결 리스트[%2d] = %d\n", i, p->data);
        p = p->next;
    }
    printf("\n");
}
