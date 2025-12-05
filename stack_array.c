#include <stdio.h>
#include <stdlib.h>

// Declaration of stack
typedef struct stack {
    int size;
    int top;
    int* arr;
} stack;

// Is it empty?
int isEmpty(stack* ptr) {
    if (ptr->top == -1) {
        return 1;
    } else {
        return 0;
    }
};
// is it Full?
int isFull(stack* ptr) {
    if (ptr->top == ptr->size - 1) {
        printf("The stack is full.\n");
        return 1;
    }
    return 0;
}

void push(stack* stack, int val) {
    if (isFull(stack)) {
        printf("Stack overflow");
    } else {
        stack->top++;
        stack->arr[stack->top] = val;
    }
}
int pop(stack* stack) {
    if (isEmpty(stack)) {
        printf("It's empty bro");
        return -1;
    } else {
        int val = stack->arr[stack->top];
        stack->top--;
        return val;
    }
}

int peek(stack* stack, int index) {
    int arrayInd = stack->top - index + 1;
    if (arrayInd < 0) {
        printf("wrong index");
        return -1;
    } else {
        int val = stack->arr[arrayInd];
        printf("%d", val);
        return 0;
    }
}

int stackTop(stack* s) {
    printf("the top of this stack is %d\n", s->arr[s->top]);
    return 1;
};
int stackBottom(stack* s) {
    printf("the bottom of this stack is %d\n", s->arr[0]);
    return 1;
};

int printarray(stack* s) {
    if (isEmpty(s)) {
        printf("it's empty bro");
        return -1;
    } else {
        for (int i = 0; i <= s->top; i++) {
            printf(" The value at index %d is %d\n", i, s->arr[i]);
        };
        return 1;
    }
}
int main() {
    stack* s = (stack*)malloc(sizeof(stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int*)malloc(s->size * sizeof(int));
    push(s, 20);
    push(s, 21);
    push(s, 22);
    push(s, 23);
    // printarray(s);
    // peek(s, 0);
    stackTop(s);
    stackBottom(s);
    return 0;
}
