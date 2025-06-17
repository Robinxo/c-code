#include "stdio.h"

void display(int arr[], int n) {
  // Traversal
  for (int i = 0; i < n; i++) {

    printf("%d ", arr[i]);
  }
  printf("\n");
};

int indDeletion(int arr[], int index, int size) {

  for (int i = index; i < size; i++) {
    arr[i] = arr[i + 1];
  }
  return 0;
}

int main() {
  int arr[100] = {9, 8, 12, 27, 88};
  int size = 5, element = 45, index = 1;
  display(arr, size);
  size -= 1;
  indDeletion(arr, index, size);
  display(arr, size);
  return 0;
}
