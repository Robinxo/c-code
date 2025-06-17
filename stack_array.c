#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int size;
  int top;
  int *arr;
} stack;

int isEmpty(stack *ptr) {
  if (ptr->top == -1) {
    return 1;
  } else {
    return 0;
  }
};

int isFull(stack *ptr) {
  if (ptr->top == ptr->size - 1) {
    printf("The stack is full.\n");
    return 1;
  }
  return 0;
}

void push(stack *stack, int val) {
  if (isFull(stack)) {
    printf("Stack overflow");
  } else {
    stack->top++;
    stack->arr[stack->top] = val;
  }
}
int pop(stack *stack) {
  if (isEmpty(stack)) {
    printf("It's empty bro");
    return -1;
  } else {
    int val = stack->arr[stack->top];
    stack->top--;
    return val;
  }
}

int peek(stack *stack, int index) {
  int arrayInd = stack->top - index + 1;
  if (arrayInd < 0) {
    printf("wrong index");
    return -1;
  } else {

    return stack->arr[arrayInd];
  }
}

int main() {
  stack *s = (stack *)malloc(sizeof(stack));
  s->size = 3;
  s->top = -1;
  s->arr = (int *)malloc(s->size * sizeof(int));
  push(s, 1);
  push(s, 1);
  push(s, 3);
  printf("%d", pop(s));
  return 0;
}
