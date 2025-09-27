#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    int priority;      // higher number = higher priority
    struct Node* next;
};

struct Node* front = NULL;

// Check if empty
int isEmpty() {
    return (front == NULL);
}

// Insert element based on priority
void enqueue(int val, int pr) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->priority = pr;
    newNode->next = NULL;

    // If queue is empty or new node has higher priority than front
    if (isEmpty() || pr > front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        // Find proper position
        struct Node* temp = front;
        while (temp->next != NULL && temp->next->priority >= pr)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("%d with priority %d inserted.\n", val, pr);
}

// Delete highest priority element (front)
void dequeue() {
    if (isEmpty()) {
        printf("Priority Queue is empty!\n");
        return;
    }
    struct Node* temp = front;
    printf("Deleted element: %d (priority %d)\n", temp->data, temp->priority);
    front = front->next;
    free(temp);
}

// Display queue
void display() {
    if (isEmpty()) {
        printf("Priority Queue is empty!\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d(p%d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
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
