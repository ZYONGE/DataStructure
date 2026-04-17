typedef struct Node{
    Element data;
    struct Node* link;
}Node;

Node* rear = NULL;

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
    return rear == NULL;
}

int is_full(){
    return 0;
}

void init_queue(){
    rear = NULL;
}

void enqueue(Element e){
    Node *p = alloc_node(e);
    if(is_empty()){
        rear = p;
        rear->link = rear;
    } else {
        p->link = rear->link;
        rear->link = p;
        rear = p;
    }
}

Element dequeue(){
    if(is_empty()) error("Queue underflow");
    Node *p = rear->link;
    Element e = p->data;
    if(rear == rear->link){
        rear = NULL;
    } else {
        rear->link = p->link;
    }
    free_node(p);
    return e;
}
Element peek(){
    if(is_empty()) error("Queue underflow");
    return rear->link->data;
}

void destroy_queue(){
    while(!is_empty()) dequeue();
}

int size(){
    if(is_empty()) return 0;

    int count = 1;
    for(Node *p = rear->link; p != rear; p = p->link){
        count++;
    }
    return count;
}

void print_queue(char *msg){
    printf("%s\n", msg);

    if(rear!= NULL){
        for(Node *p = rear->link; p != rear; p = p->link){
            printf("%2d ", p->data);
        }
        printf("%2d ", rear->data);
    }
    printf("\n");
}

void print_recur(Node *p){
    if(p != NULL){
        print_recur(p->link);
        printf("%3d ", p->data);
    }
}