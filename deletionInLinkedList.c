#include "stdio.h"
#include "stdlib.h"

struct Node {

  int data;
  struct Node *next;
};

void linkedListTraversal(struct Node *ptr) {

  while (ptr != NULL) {
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
  }
};

struct Node *deleteAtFirst(struct Node *head) {
  // Logic
  struct Node *ptr = head;
  head = head->next;
  free(ptr);
  return head;
};

struct Node *deleteAtIndex(struct Node *head, int index) {

  struct Node *p = head;
  struct Node *q = head->next;
  for (int i = 0; i < index - 1; i++) {
    p = p->next;
    q = q->next;
  }

  p->next = q->next;
  free(q);

  return head;
}

struct Node *deleteAtLast(struct Node *head) {
  struct Node *p = head;
  struct Node *q = p->next;

  while (q->next != NULL) {
    p = p->next;
    q = q->next;
  }
  p->next = NULL;
  free(q);

  return head;
}

struct Node *deleteByValue(struct Node *head, int value) {
  // If head node is null
  if (head == NULL) {
    return NULL;
  }

  // If head node holds the value
  if (head->data == value) {
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
  }
  // For other nodes
  struct Node *p = head;
  struct Node *q = head->next;

  while (q->next != NULL && q->data != value) {
    p = p->next;
    q = q->next;
  }
  if (q->data == value) {
    p->next = q->next;
    free(q);
  }
  return head;
}

int main() {

  // Declaration of nodes
  struct Node *head;
  struct Node *second;
  struct Node *third;
  struct Node *fourth;

  // Declaration of head
  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));
  fourth = (struct Node *)malloc(sizeof(struct Node));

  // Declaring the data
  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = fourth;

  fourth->data = 4;
  fourth->next = NULL;

  // head = deleteAtFirst(head);
  // head = deleteAtIndex(head, 1);
  // head = deleteAtLast(head);
  head = deleteByValue(head, 1);

  linkedListTraversal(head);
  return 0;
}
