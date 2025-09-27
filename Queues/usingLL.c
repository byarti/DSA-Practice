#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int isempty() {
    return (front == NULL && rear == NULL);
}

void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (isempty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted into queue.\n", x);
}

void dequeue(){
    if(isempty()){
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    
    printf("Deleted: %d\n", front->data);
    front = front->next;

    if(front == NULL){
        rear = NULL;
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
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, x;

    while (1) {
        printf("\nQueue using Linked List Menu\n");
        printf("1. Is Empty\n");
        printf("2. Insert in Queue\n");
        printf("3. Delete in Queue\n");
        printf("4. Display the Queue\n");
        printf("5. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (isempty()) printf("Queue is empty.\n");
                else printf("Queue is not empty.\n");
                break;
            case 2: 
                printf("Enter the element: "); 
                scanf("%d", &x); 
                enqueue(x); 
                break;
            case 3: 
                dequeue(); 
                break;
            case 4: 
                display(); 
                break;
            case 5: 
                printf("Exiting...\n"); 
                exit(0);
            default: 
                printf("Invalid choice. Enter again.\n");
        }
    }

    return 0;
}
