#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int search(struct Node** head, int key){
    struct Node* temp = head;
    int pos = 1; 
    while(temp != NULL){
        if (temp->data == key) return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

int count(struct Node** head){
    int count = 0;
    struct Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

int main(){
    
}

