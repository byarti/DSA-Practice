#include <stdio.h>

void printArray(int a[], int n, const char *label) {
    printf("%s: ", label);
    for (int x = 0; x < n; x++) printf("%d ", a[x]);
    printf("\n");
}

void heapifyMin(int a[], int n, int i) {
    int small = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] < a[small]) small = l;
    if (r < n && a[r] < a[small]) small = r;

    if (small != i) {
        int temp = a[i];
        a[i] = a[small];
        a[small] = temp;
        // show the swap inside heapify
        printf("  heapify swap: swap a[%d]=%d and a[%d]=%d\n", i, a[small], small, a[i]);
        printArray(a, n, "  after swap");
        heapifyMin(a, n, small);
    }
}

void heapSortAsc(int a[], int n) {
    // Build min-heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        printf("Call heapifyMin(a, %d, %d)\n", n, i);
        heapifyMin(a, n, i);
        printArray(a, n, "After heapify");
    }

    // Extract elements by swapping root to end
    for (int i = n - 1; i > 0; i--) {
        printf("Swap root a[0]=%d with a[%d]=%d\n", a[0], i, a[i]);
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        printArray(a, n, "After root swap");
        // heapify reduced heap
        printf("Fix heap of size %d\n", i);
        heapifyMin(a, i, 0);
        printArray(a, n, "After fix");
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    printArray(a, n, "Initial array");
    heapSortAsc(a, n);
    printArray(a, n, "Final array (smallest values are at right side)");
    return 0;
}
