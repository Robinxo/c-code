#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// Insert at first
struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));

    ptr->data = data;
    ptr->next = head;

    return ptr;
}

// Insert in between if you know the first and second
struct Node* insertInBetweenFirstAndSecond(struct Node* head, struct Node* secondNode, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));

    ptr->next = secondNode;
    ptr->data = data;
    head->next = ptr;

    return ptr;
}

// Insert in between
struct Node* insertInBetween(struct Node* head, int index, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;
    while (i != index - 1) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
};

// Insert in the last node
struct Node* insertAtLast(struct Node* head, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;

    while (p->next != NULL) {
        p = p->next;
    }
    ptr->data = index;
    ptr->next = NULL;
    p->next = ptr;

    return head;
}
// DELETION IN CIRCULAR LINKED LIST
// Delete at first

struct Node* deleteAtFirst(struct Node* head) { return head; }

int main() {
    // Declaration of nodes
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* fifth;
    // Declaration of head
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));
    // Declaring the data
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL

    // head = insertAtFirst(head, 0);
    printf("after function run!\n");
    // linkedListTraversal(head);
    // second = insertInBetween(second, third, 33);
    //  head = insertInBetween(head, 3, 22);
    head = insertAtLast(head, 22);

    linkedListTraversal(head);
    return 0;
}
