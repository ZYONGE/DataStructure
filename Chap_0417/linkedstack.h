typedef struct Node{
    Element data;
    struct Node *link;
} Node;

Node *top = NULL;

Node* alloc_node(Element e){
    Node *p = (Node*)malloc(sizeof(Node)*1);
    p->data = e;
    p->link = NULL;
    return p;
}

Element free_node(Node *p){
    Element e = p->data;
    free(p);
    return e;
}

void error(char str[]){
    printf("%s\n", str);
    exit(1);
}

int is_empty(){
    return top == NULL;
}

int is_full(){
    return 0;
}

void init_stack(){
    top = NULL;
}

void push(Element e){
    Node *p = alloc_node(e);
    p->link = top;
    top = p;
}

void pop(){
    if(is_empty()) error("Stack underflow");
    Node *p = top;
    top = top->link;
    free_node(p);
}
Element peek(){
    if(is_empty()) error("Stack underflow");
    return top->data;
}
void destroy_stack(){
    while(!is_empty()) pop();
}

int size(){
    int count = 0;
    Node *p = top;

    while(p != NULL){
        count++;
        p = p->link;
    }
    return count;
}

void print_stack(){
    for(Node* p = top; p != NULL; p = p->link){
        printf("%3d ", p->data);
    }
    printf("\n");
}

void print_recur(Node *p){
    if(p != NULL){
        print_recur(p->link);
        printf("%3d ", p->data);
    }
}