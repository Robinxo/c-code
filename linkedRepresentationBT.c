#include <stdio.h>
#include <stdlib.h>

typedef struct node {

  int data;
  struct node *left;
  struct node *right;
} Node;

Node *createNode(int data) {
  Node *n;
  n = (Node *)malloc(sizeof(Node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

int main() {
  Node *p = createNode(2);
  Node *p1 = createNode(1);
  Node *p2 = createNode(4);

  p->left = p1;
  p->right = p2;

  return 0;
}
