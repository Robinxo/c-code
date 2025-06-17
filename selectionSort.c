#include "stdio.h"

void printArray(int *A, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

void selectionSort(int *A, int n) {
  printf("Running Selection sort  ");
  int indexOfMin;
  for (int i = 0; i < n - 1; i++) {
    indexOfMin = i;
  }
}

int main() {
  int A[] = {
      12, 14, 145, 25, 46, 77, 1, 2,
  };
  int n = (sizeof A / sizeof A[0]);
  return 0;
}
