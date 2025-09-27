#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int pq[SIZE];      // store values
int pr[SIZE];      // store priority (higher value = higher priority)
int n = 0;         // current number of elements

int isEmpty() {
    return (n == 0);
}

int isFull() {
    return (n == SIZE);
}

// Insert element with priority
void enqueue(int val, int priority) {
    if (isFull()) {
        printf("Priority Queue is full!\n");
        return;
    }
    // Insert at the end
    pq[n] = val;
    pr[n] = priority;
    n++;
    printf("%d with priority %d inserted.\n", val, priority);
}

// Delete highest priority element
void dequeue() {
    if (isEmpty()) {
        printf("Priority Queue is empty!\n");
        return;
    }

    // Find index of highest priority
    int highest = 0;
    for (int i = 1; i < n; i++) {
        if (pr[i] > pr[highest])
            highest = i;
    }

    printf("Deleted element: %d (priority %d)\n", pq[highest], pr[highest]);

    // Shift elements left
    for (int i = highest; i < n - 1; i++) {
        pq[i] = pq[i + 1];
        pr[i] = pr[i + 1];
    }
    n--;
}

// Display queue
void display() {
    if (isEmpty()) {
        printf("Priority Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < n; i++)
        printf("%d(p%d) ", pq[i], pr[i]);
    printf("\n");
}

int main() {
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);

    display();

    dequeue();
    display();

    enqueue(40, 5);
    display();

    return 0;
}
