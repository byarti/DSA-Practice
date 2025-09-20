#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void insertBeginning(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

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

void insertPos(struct Node** head, int data, int pos){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if(pos == 1){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for(int i=1; i<pos-1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL) return;

    newNode->next = temp->next;
    temp->next = newNode;
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
    int choice, data, pos;

    while(1){
        printf("Linked List Insertion Menu\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at a given Position\n");
        printf("4. Print the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data to insert: "); scanf("%d", &data);
                insertBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert: "); scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 3: 
                printf("Enter data to insert: "); scanf("%d", &data);
                printf("Enter the postion: "); scanf("%d", &pos);
                insertPos(&head, data, pos);
                break;
            case 4:
                Print(head);
                break;
            case 5:
                printf("Exiting....");
                exit(0);
            default: 
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

