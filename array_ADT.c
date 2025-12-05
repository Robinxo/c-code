#include <stdio.h>
#include <stdlib.h>

struct MyArray {
  int total_size;
  int used_size;
  int *ptr;
};


struct MySecondArray {
    int double_size;
    int used_size;
};

void createArray(struct MyArray *a, int t_Size, int u_Size) {
  a->total_size = t_Size;
  a->used_size = u_Size;
  a->ptr = (int *)malloc(t_Size * sizeof(int));
  printf("Array created succesfully\n");
};

void setVal(struct MyArray *a) {
  int n;
  for (int i = 0; i < a->used_size; i++) {
    printf("Enter element %d", i);
    scanf("%d", &n);
    (a->ptr)[i] = n;
  }
}

void Show(struct MyArray *a) {
  for (int i = 0; i < a->used_size; i++) {
    printf("%d\n", (a->ptr)[i]);
  }
}

int main() {
  struct MyArray example;
  createArray(&example, 10, 2);
  setVal(&example);
  Show(&example);

  return 0;
}
