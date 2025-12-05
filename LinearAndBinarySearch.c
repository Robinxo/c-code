#include <stdio.h>

int linearSearch(int arr[], int n, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == n) {
            return i;
        }
    }
    return -1;
};

int binarySearch(int arr[], int target, int size) {
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        printf("the new mid is %d\n", mid);
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
            int A[] = {12, 14, 145, 25, 46, 77, 1, 2, 3};
        }
    }
    return -1;
}

int main() {
    int arr[] = {3,   5,   7,   9,   12,  15,  18,  21,  23,  26,  29,  32,  35,
                 38,  41,  44,  47,  50,  53,  56,  59,  62,  65,  68,  71,  74,
                 77,  80,  83,  86,  89,  92,  95,  98,  101, 104, 107, 110, 113,
                 116, 119, 122, 125, 128, 131, 134, 137, 140, 143, 146, 250};
    int size = sizeof(arr) / sizeof(arr[0]);
    /*
         int searchValued = linearSearch(arr, 88, size);
      printf("%d", searchValued);
    */
    int searchIndex = binarySearch(arr, 98, size);

    printf("The value of search index is %d\n", searchIndex);
    return 0;
}
