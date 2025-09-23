#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

void deleteBegin(struct Node** head){
    if(*head == NULL){
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next; //move head to next node
    if(*head != NULL){
        (*head)->prev = NULL; //new head's prev = NULL
    }

    printf("deleted: %d\n", temp->data);
    free(temp);
}

void deleteEnd(struct Node** head){
    if(*head == NULL){
         printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp->prev != NULL){
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void deletePos(struct Node** head, int pos){
    if(*head == NULL || pos <= 0){
        printf("Invalid Position. Enter valid position sweetie. You can do it!");
        return;
    }

    struct Node* temp = *head;

    for(int i = 1; i < pos && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Position out of range.\n");
        return;
    }

    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    } else {
        *head = temp->next; //deleting head
    }

    if(temp->next != NULL){
        temp->next->prev = temp->prev; 
    }
    printf("Deleted: %d\n",temp->data);
    free(temp);
}

void Insertend(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    
}

void Print(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL){
        printf(" %d <->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}

int main(){
    struct Node* head = NULL;
    Insertend(&head, 10);
    Insertend(&head, 20);
    Insertend(&head, 30);
    Insertend(&head, 40);
    Insertend(&head, 50);
    
    printf("Original List: "); Print(head);

    int choice, pos;

    while(1){
    printf("Deletion menu :\n");
    printf("1. Deletion in the beginning.\n");
    printf("2. Deletion in the end.\n");
    printf("3. Deletion at a given position.\n");
    printf("4. Print the DLL.\n");
    printf("5. I wanna Exit.\n");
    
    printf("Enter your choice: "); scanf("%d", &choice);

    switch(choice){
        case 1: deleteBegin(&head); break;
        case 2: deleteEnd(&head); break;
        case 3: printf("The position you wanna delete: "); scanf("%d", &pos); deletePos(&head, pos); break;
        case 4: Print(head); break;
        case 5: printf("Exiting...."); exit(0);
        default: printf("Invalid option dear, enter again.");
    }
    }
    return 0;
}