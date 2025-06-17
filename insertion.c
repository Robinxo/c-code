#include "stdio.h"

void display(int arr[], int n) {
  // Traversal
  for (int i = 0; i < n; i++) {

    printf("%d ", arr[i]);
  }
  printf("\n");
};

int indInsertion(int arr[], int capacity, int element, int index, int size) {
  if (size >= capacity) {
    printf("This shit can't happen the array is too big bro!\n");
    return -1;
  } else {
    for (int i = size - 1; i >= index; i--) {

      arr[i + 1] = arr[i];
    }
    arr[index] = element;
    printf("This shit happened cause why not\n");
    return 1;
  }
};

int main() {
  int arr[100] = {9, 8, 12, 27, 88};
  int size = 5, element = 45, index = 3;
  display(arr, size);
  size += 100;
  indInsertion(arr, 100, element, index, size);
  display(arr, size);
  return 0;
}
