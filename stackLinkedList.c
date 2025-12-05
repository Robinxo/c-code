#include <stdalign.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


void linkedListTraversal(Node* ptr) {
    int i = 0;
    while (ptr != NULL) {
        printf(" The value at %d and it's value is: %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

int isEmpty(Node* top) {
    if (top == NULL) {
        return 1;
    } else
        return 0;
};

int isFull(Node* top) {
    Node* new = (Node*)malloc(sizeof(Node));
    if (new == NULL) {
        return 1;
    } else
        return 0;
};

Node* push(Node* top, int val) {
    if (isFull(top)) {
        printf("Bawwe this is very full");
    } else {
        Node* new = (Node*)malloc(sizeof(Node));
        new->data = val;
        new->next = top;
        top = new;
        return top;
    }
    return 0;
}

int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Bawwe this is very empty");
        return -1;
    }
    Node* n = *top;
    *top = (*top)->next;
    int x = n->data;
    free(n);
    return x;
}

int stackTop(Node* n) {
    printf("The top value is %d", n->data);
    return 0;
}

int stackBottom(Node* n) {
    if (isEmpty(n)) {
        return -1;
    }
    Node* new = n;
    while (new->next != NULL) {
        new = new->next;
    }

    return new->data;
};

int peek(Node* n, int index) {
    int i = 0;
    while (n != NULL) {
        if (index == i) {
            printf(" The value at %d and it's value is: %d\n", i, n->data);
            return 0;
        }
        n = n->next;
        i++;
    }
    printf("Index %d does not exist in the stack\n", index);

    return 1;
}

int main() {
    Node* top = NULL;
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 50);
    //   int val = pop(&top);

    // linkedListTraversal(top);
    // stackTop(top);
    // printf("\nstackBottom result is %d", stackBottom(top));
    //
    peek(top, 1);

    return 0;
}
