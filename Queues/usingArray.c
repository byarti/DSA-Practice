#include <stdio.h>
#define SIZE 5 // maximum size of queue

int queue[SIZE];
int front = -1, rear = -1;

// check if queue is empty
int isEmpty() {
    return (front == -1);
}

// check if queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// add element
void enqueue(int val) {
    if (isFull()) {
        printf("Queue Overflow! Can't Insert anymore bby.\n");
    } else {
        if (front == -1) front = rear = 0; // first element, yay!
        else rear = (rear + 1) % SIZE;
        queue[rear] = val;
        printf("%d inserted into queue\n", val);
    }
}

// delete element
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No element to delete, sweetie.\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        if (front == rear) front = rear = -1; // queue empty now
        else front = (front + 1) % SIZE;
    }
}

// display elements
void display() {
    if (isEmpty()) {
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
    enqueue(10);
    enqueue(12);
    enqueue(14);
    enqueue(16);
    enqueue(18);
    display();

    dequeue();
    dequeue();
    display();

    enqueue(20);
    enqueue(22);
    display();

    return 0;
}
