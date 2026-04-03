Element data [MAX_SIZE];

int top;

void error(char str[]){
    printf("%s\n", str);

    exit(1);
}

void init_stack() {
    top = -1;
}

int is_empty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}
//int is_empty() {
//    int return;
//    (top == -1) ? return = 1 : return = 0;
//}

int is_full() {
    if (top == MAX_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

void push(Element item) {
    if (is_full()) {
        error("Overflow Error");
    }
    data[++top] = item;
}

Element pop() {
    if (is_empty()) {
        error("Underflow Error");
    }
    return data[top--];
}

Element peek() {
    if (is_empty()) {
        error("Underflow Error");
    }else{  
        return data[top];
    }
}

int size(void){
    return top + 1;
}