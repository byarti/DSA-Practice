#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int isempty() {
    return (front == NULL);
}

void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    //idhar next NULL put nai kara

    if (isempty()) {
        front = rear = newNode;
        rear->next = front;  // DIFFERENCE: make it circular
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;  // DIFFERENCE: last node points back to front
    }
    printf("%d inserted into queue.\n", x);
}

void dequeue() {
    if (isempty()) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front;

    // If only one node is left
    if (front == rear) {
        printf("Deleted: %d\n", front->data);
        front = rear = NULL;
    } else {
        printf("Deleted: %d\n", front->data);
        front = front->next;
        rear->next = front;  // DIFFERENCE: maintain circular link
    }
    free(temp);
}

// Display queue
void display() {
    if (isempty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    struct Node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);  // DIFFERENCE: stop when we come back to front
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(50);
    enqueue(60);

    display();

    return 0;
}
