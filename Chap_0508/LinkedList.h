#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node{
    Element data;
    struct Node* link;
} Node;

Node *head = NULL;

void error(char str[]){
    printf("%s\n", str);
    exit(1);
}

Node *alloc_node(Element e){
    Node *p = (Node*)malloc(sizeof(Node));

    if(p == NULL){
        error("Memory allocation failed");
        
    }

    p->data = e;
    p->link = NULL;
    return p;
}

Element free_node(Node *p){
    Element e = p->data;
    free(p);
    return e;
}

int is_full(){
    return 0;
}
int is_empty(){
    return head == NULL;
}
void init_list(){
    head = NULL;
}
Node* get_node(int pos){
    if (pos < 0){
        return NULL;
    }
    Node *p = head;
    for (int i = 0; i < pos; i++){
        if (p == NULL){
            return NULL;
        }
        p = p->link;
    }
    return p;
}

Element get_entry(int pos){
    Node *p = get_node(pos);
    if (p == NULL){
        error("Invalid position");
    }
    return p->data;
}
void insert(int pos, Element e){
    Node *p = alloc_node(e);
    if (pos == 0){
        p->link = head;
        head = p;
    } else {
        Node *prev = get_node(pos - 1);
        if (prev == NULL){
            error("Invalid position");
        }
        p->link = prev->link;
        prev->link = p;
    }
}

Element delete_entry(int pos){
    if (is_empty()){
        error("List is empty");
    }
    Node *p;
    if (pos == 0){
        p = head;
        head = head->link;
    } else {
        Node *prev = get_node(pos - 1);
        if (prev == NULL || prev->link == NULL){
            error("Invalid position");
        }
        p = prev->link;
        prev->link = p->link;
    }
    return free_node(p);
}
int size(){
    int count = 0;
    for (Node *p = head; p != NULL; p = p->link){
        count++;
    }
    return count;
}

void print_list(char msg[]){
    printf("%s[%2d]\n", msg, size());
    printf("--------------------\n");
    for (Node *p = head; p != NULL; p = p->link){
        printf("%d -> ", p->data);
    }
    printf("NULL\n"); 
    
}
void append(Element e){
    insert(size(), e);
}

Element pop(){
    return delete_entry(size() - 1);
}
void replace(int pos, Element e){
    Node *p = get_node(pos);
    if (p == NULL){
        error("Invalid position");
    }
    p->data = e;
}

void destroy_list(){
    while (!is_empty()){
        delete_entry(0);
    }
}
int find(Element e){
    int pos = 0;
    for (Node *p = head; p != NULL; p = p->link){
        if (p->data == e){
            return pos;
        }
        pos++;
    }
    return -1;
}

#endif