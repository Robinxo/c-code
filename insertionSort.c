#include <stdio.h>

void printArray(int *A, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

void insertion(int *A, int n) {

  int key, j;
  for (int i = 1; i <= n - 1; i++) {
    key = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > key) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;
  }
}

int main() {
  int A[] = {
      12, 14, 145, 25, 46, 77, 1, 2,
  };
  int n = (sizeof A / sizeof A[0]);
  printArray(A, n);
  insertion(A, n);
  printArray(A, n);

  return 0;
}
