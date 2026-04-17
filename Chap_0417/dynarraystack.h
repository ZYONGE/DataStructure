int MAX_SIZE = 100;
Element* data = NULL;
int top;

void error(char str[]) {
    printf("%s\n", str);
    exit(1);
}

int is_empty(){
    if(top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int is_full() {
    if(top == (MAX_SIZE - 1)) {
        return 1;
    } else {
        return 0;
    }
}

void init_stack() {
    data = (Element*)malloc(sizeof(Element) * MAX_SIZE);
    top = -1;
}

void push(Element e){
    if (is_full()) {
        MAX_SIZE *= 2;
        data = (Element*)realloc(data, sizeof(Element) * MAX_SIZE);
        printf("Stack size doubled to %d\n", MAX_SIZE);
    }
    data[++top] = e;
}

Element pop() {
    if (is_empty()) {
        error("Stack underflow");
    }
    return data[top--];
}

Element peek(){
    if (is_empty()) {
        error("Stack underflow");
    }
    return data[top];
}