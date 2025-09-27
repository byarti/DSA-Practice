#include <stdio.h>
#include <stdlib.h>  // for exit()

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Check if empty
int isempty() {
    return (front == -1 && rear == -1);
}

// Check if full
int isfull() {
    return ((rear + 1) % SIZE == front);
}

// Enqueue
void enqueue(int x) {
    if (isfull()) {
        printf("Queue Overflow! Can't Insert anymore bby.\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        queue[rear] = x;
        printf("%d inserted into queue.\n", x);
    }
}

// Dequeue
void dequeue() {
    if (isempty()) {
        printf("Queue Underflow! No element to delete, sweetie.\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

// Display
void display() {
    if (isempty()) {
        printf("Queue is empty, now. But you can lemme insert something you'd like.\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, x;
    while (1) {
        printf("\nQueue using Array Menu\n");
        printf("1. Is Empty\n");
        printf("2. Is Full\n");
        printf("3. Insert in Queue\n");
        printf("4. Delete in Queue\n");
        printf("5. Display the Queue\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (isempty()) printf("Queue is empty.\n");
                else printf("Queue is not empty.\n");
                break;
            case 2: 
                if (isfull()) printf("Queue is full.\n");
                else printf("Queue is not full.\n");
                break;
            case 3: 
                printf("Enter the element: "); 
                scanf("%d", &x); 
                enqueue(x); 
                break;
            case 4: 
                dequeue(); 
                break;
            case 5: 
                display(); 
                break;
            case 6: 
                printf("Exiting...\n"); 
                exit(0);
            default: 
                printf("Invalid choice. Enter again bby.\n"); 
        }
    }
    return 0;
}
