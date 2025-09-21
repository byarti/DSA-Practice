#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertBegin(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if(*head != NULL){
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertEnd(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL){
        newNode->prev = NULL;
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

//inserting at a given position
void insertPos(struct Node** head, int data, int pos){
    if(pos <= 0){
        printf("Invalid position.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    //insert at beginning
    if(pos == 1){
        newNode->next = *head; //new node points to current head
        if(*head != NULL){
            (*head)->prev = newNode; //old head points back to new node
        }
        *head = newNode; //update head to new node
        return;
    }

    //traverse to pos-1
    struct Node* temp = *head;
    for(int i=1; temp != NULL && i < pos-1; i++){
        temp = temp->next;
    }

    //pos is greater than length, check if position is valid 
    if(temp == NULL){
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    //insert after temp
    newNode->next = temp->next; //new node points to node after temp
    newNode->prev = temp; //new node's prev points to temp
    temp->next = newNode; //temp's mext points to new node

    //agar ham insert kar rahe hein middle mein then 
    //newnode ke nex node ko bhi update karna hoga ke uska prev newnode hai
    if(newNode->next != NULL){
        newNode->next->prev = newNode;
    }

}

void Print(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head = NULL;
    int choice, data, pos;

    while(1){
        printf("Insertion Menu\n");
        printf("1. Insert in Beginning\n");
        printf("2. Insert in End\n");
        printf("3. Insert at a given position\n");
        printf("4. Print the DLL\n");
        printf("5. Exit\n");


        printf("Enter your choice: "); scanf("%d", &choice);

        switch(choice){
            case 1: printf("Enter the data: "); scanf("%d", &data); insertBegin(&head, data); break;
            case 2: printf("Enter the data: "); scanf("%d", &data); insertEnd(&head, data); break;
            case 3: printf("Enter the data: "); scanf("%d", &data); printf("Enter the position: "); scanf("%d", &pos); insertPos(&head, data, pos); break;
            case 4: Print(head); break;
            case 5: printf("Exiting...."); exit(0);
            default: printf("Invalid option. Try again sweetie!");
        }
    }
    return 0;
}