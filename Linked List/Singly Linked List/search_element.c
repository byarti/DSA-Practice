#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertEnd(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL){
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void Print(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int Search(struct Node* head, int key){
    struct Node* temp = head;
    int pos = 1; 
    while (temp != NULL){
        if (temp->data == key) return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

int count(struct Node* head){
    int cnt = 0;
    struct Node* temp = head;
    while (temp != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main(){
    struct Node* head = NULL;
    int search;

    insertEnd(&head, 10); 
    insertEnd(&head, 20); 
    insertEnd(&head, 30); 
    insertEnd(&head, 40); 
    insertEnd(&head, 50);

    Print(head);

    printf("Value you wanna search from the LL: ");
    scanf("%d", &search);

    int pos = Search(head, search);
    if (pos != -1)
        printf("Value %d found at position %d\n", search, pos);
    else
        printf("Value %d not found in the list\n", search);

    printf("Total nodes in the list: %d\n", count(head));

    return 0;
}
