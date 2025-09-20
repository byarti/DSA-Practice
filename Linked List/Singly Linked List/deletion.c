#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void insertEnd(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteBeginning(struct Node** head){
    if(*head == NULL)return;
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteEnd(struct Node** head){
    if(*head == NULL)return;
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deletePos(struct Node** head, int pos){
    if(*head == NULL)
        return;
    struct Node* temp = *head;
    if(pos == 1){
        *head = temp->next;
        free(temp);
        return;
    }   
    for(int i=1; i<pos-1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL) return;

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

void Print(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head = NULL;
    int choice, pos;

    printf("Given Linked List: \n");
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    Print(head);
    
    while(1){ 
        printf("Delete some nodes from the given LL: \n");
        printf("1. Delete the beginning Node\n");
        printf("2. Delete the Last Node\n");
        printf("3. Delete the Node of a given position\n");
        printf("4. Exit\n");

        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: deleteBeginning(&head); Print(head); break;
            case 2: deleteEnd(&head); Print(head); break;
            case 3: printf("Enter the position: "); scanf("%d", &pos); deletePos(&head, pos); Print(head); break;
            case 4: printf("Exiting ...."); exit(0);
            default: printf("Invalid Option.");
        }
    }
    return 0;
}