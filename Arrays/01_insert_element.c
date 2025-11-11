#include <stdio.h>

void insertElement(int arr[], int n, int element, int pos) {
    if (pos < 0 || pos > n) {
        printf("Invalid position\n");
        return;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int n = 5; // current number of elements
    int element = 10;
    int pos = 2;

    insertElement(arr, n, element, pos);
    n++; // increase the size after insertion

    printf("Array after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

