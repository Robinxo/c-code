#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

// Traversal
void linkedListTraversal(struct Node *head) {
  struct Node *p = head;
  int i = 1;
  while (p != NULL) {
    printf("Element at %d is %d\n", i, p->data);
    i++;
    p = p->next;
  }
};

// Insertion

void insertAtFirst(struct Node **n1, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));

  if (newNode == NULL) {
    printf("Memory Allocation failed Bye Bye!");
    exit(-1);
  }
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = *n1;
  (*n1)->prev = newNode;
  *n1 = newNode;
};

struct Node *insertAtIndex(Node *n1, int data, int index) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;

  if (index == 1) {
    Node *newNodee = (Node *)malloc(sizeof(Node));
    newNodee->data = data;
    newNodee->prev = NULL;
    newNodee->next = n1;
    n1->prev = newNodee;
    n1 = newNodee;
    return n1;
  }
  Node *p = n1;
  int i = 1;
  while (p != NULL && i != index - 1) {
    p = p->next;
    i++;
  };
  newNode->next = p->next;
  p->next = newNode;
  newNode->prev = n1;
  return n1;
}

struct Node *insertAtEnd(Node *n1, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  Node *p = n1;

  while (p->next != NULL) {
    p = p->next;
  }
  printf("We are at ummm %d\n", p->data);
  p->next = newNode;
  newNode->prev = p;

  return n1;
}

// Deletion

int main() {
  Node *n1, *n2, *n3, *n4, *n5, *n6, *n7;
  n1 = (Node *)malloc(sizeof(Node));
  n2 = (Node *)malloc(sizeof(Node));
  n3 = (Node *)malloc(sizeof(Node));
  n4 = (Node *)malloc(sizeof(Node));
  n5 = (Node *)malloc(sizeof(Node));
  n6 = (Node *)malloc(sizeof(Node));
  n7 = (Node *)malloc(sizeof(Node));

  n1->prev = NULL;
  n1->data = 1;
  n1->next = n2;

  n2->prev = n1;
  n2->data = 2;
  n2->next = n3;

  n3->prev = n2;
  n3->data = 3;
  n3->next = n4;

  n4->prev = n3;
  n4->data = 4;
  n4->next = n5;

  n5->prev = n4;
  n5->data = 5;
  n5->next = n6;

  n6->prev = n5;
  n6->data = 6;
  n6->next = n7;

  n7->prev = n6;
  n7->data = 7;
  n7->next = NULL;

  // insertAtFirst(&n1, 0);
  // n1 = insertAtIndex(n1, 41, 1);
  n1 = insertAtEnd(n1, 10);
  linkedListTraversal(n1);
  return 0;
}
