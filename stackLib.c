#define MAX_STACK_SIZE 100


struct Stack {
    int data[MAX_STACK_SIZE];
    int size;
};

typedef struct Stack Stack;


void stackInit (Stack *s) {
    s->size = 0;
}

int stackTop(Stack *s) {
    if (s->size == 0) {
        fprintf(stderr, "Error : Stack is empty!\n");
        return -1;
    } 
    return s->data[s->size - 1];
}

void stackPush(Stack *s, int value) {
    if (s->size < MAX_STACK_SIZE) {
        s->data[s->size++] = value;
    } else {
        fprintf(stderr, "Error : Stack is full!\n");
    }
}

int stackPop(Stack *s) {
    if (s->size == 0) {
        fprintf(stderr, "Error : Stack is empty!\n");
        return 0;
    } else {
        int ret = stackTop(s);
        s->size--;
        return ret;
    }
}

