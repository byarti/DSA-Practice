#include <stdio.h>
#define INF 999999

void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;   // size of left part
    int n2 = r - q;       // size of right part

    int L[n1 + 1], R[n2 + 1];

    // Copy elements into L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    // Add infinity at end (sentinel)
    L[n1] = INF;
    R[n2] = INF;

    int i = 0, j = 0;

    // Merge back into A[p..r]
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergesort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;

        // Divide
        mergesort(A, p, q);
        mergesort(A, q + 1, r);

        // Conquer
        merge(A, p, q, r);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    mergesort(A, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
