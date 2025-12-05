#include <stdio.h>

void printArray(int* A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertion(int* A, int n) {
    int key, j;
    for (int index = 1; index <= n - 1; index++) {
        printf("The instances it took to do this is %d\n", index);
        key = A[index];
        j = index - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main() {
    //    int A[] = {12, 14, 145, 25, 46, 77, 1, 2, 3};
    int A[] = {1, 2, 3, 12, 14, 25, 46, 77, 145};
    int n = (sizeof A / sizeof A[0]);
    printf("size is %d\n", n);
    printArray(A, n);
    insertion(A, n);
    printArray(A, n);

    return 0;
}
