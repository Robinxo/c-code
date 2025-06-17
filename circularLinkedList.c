#include <stdio.h>
#include <stdlib.h>

struct Node {

  int data;
  struct Node *next;
};

// Traversal
void linkedListTraversal(struct Node *head) {
  struct Node *ptr = head;
  do {
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
  } while (ptr != head);
};

// INSERTION IN CIRCULAR LINKED LIST
struct Node *insertAtFirst(struct Node *head, int data) {
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->data = data;
  struct Node *p = head->next;
  while (p->next != head) {
    p = p->next;
  }
  p->next = ptr;
  ptr->next = head;
  head = ptr;
  return head;
}

struct Node *insertAtBetween(struct Node *head, int data, int index) {

  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->data = data;

  if (index == 0) {
    struct Node *temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
  }

  struct Node *p = head;
  int i = 0;
  while (i < index - 1 && p->next != head) {
    p = p->next;
    i++;
  }
  ptr->next = p->next;
  p->next = ptr;

  return head;
}
struct Node *insertAtlast(struct Node *head, int data) {
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->data = data;
  struct Node *p = head;

  while (p->next != head) {
    p = p->next;
  }
  ptr->next = head;
  p->next = ptr;

  return head;
}

// DELETION IN CIRCULAR LINKED LIST
// Delete at first

struct Node *deleteAtFirst(struct Node *head) {
  struct Node *p = head;

  while (p->next != head) {
    p = p->next;
  }
  struct Node *temp = head;
  head = head->next;
  p->next = head;
  free(temp);
  return head;
}

struct Node *deleteAtIndex(struct Node *head, int index) {
  if (head == NULL) {
    return NULL;
  }
  int count = 1;
  struct Node *temp = head;
  while (temp->next != head) {
    count++;
    temp = temp->next;
  }

  if (index < 1 || index > count) {
    printf("invalid index EHHHHHHHHHHHHHH!\n");
    return NULL;
  }

  if (index == 1) {
    if (head->next == head) {
      free(head);
      return NULL;
    }
    struct Node *last = head;
    while (last->next != head) {
      last = last->next;
    }
    struct Node *temp = head;
    head = head->next;
    last->next = head;
    free(temp);
    return head;
  };

  struct Node *p = head;

  for (int i = 1; i < index - 1; i++) {
    p = p->next;
  }

  struct Node *q = p->next;
  p->next = q->next;
  free(q);
  return head;
}

struct Node *deleteAtLast(struct Node *head) {

  struct Node *p = head;
  struct Node *q = p->next;

  while (q->next != head) {
    p = p->next;
    q = q->next;
  }
  p->next = q->next;
  free(q);

  return head;
}
// Main code
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
  fourth->next = head;

  // head = insertAtFirst(head, 1);
  // head = insertAtBetween(head, 0, 0);
  // head = insertAtlast(head, 22);
  // head = deleteAtFirst(head);
  // head = deleteAtLast(head);
  head = deleteAtIndex(head, 7);

  linkedListTraversal(head);

  return 0;
}
