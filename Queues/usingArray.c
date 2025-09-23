#include <stdio.h>
#define SIZE 5 //maximum size of queue

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int val){
    if(rear == SIZE - 1){
        printf("Queue Overflow\n");
    } else {
        if(front == -1) front = 0; 
        queue[++rear] = val;
        printf("%d inserted into queue\n", val);
    }
}

//function to delete an element from queue
void dequeue(){
    if(front == -1 || front > rear){
        printf("Queue Underflow\n");
    } else {
        printf("Deleted: %d\n", queue[front++]);
    }
}

void display(){
    if(front == -1 || front > rear){
        printf("Queue is Empty\n");
        
    }
}