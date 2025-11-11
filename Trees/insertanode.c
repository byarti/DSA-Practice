#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* insertBST(struct node* root, int value){
    if(root == NULL){
        return createNode(value);
    }
    if(value < root->data){
        root->left = insertBST(root->left, value);
    }
    if(value > root->data){
        root->right = insertBST(root->right, value);
    }
    return root;
}

void inorder(struct node* root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct node* root = NULL;

    root = insertBST(root, 5);    
    root = insertBST(root, 1);  
    root = insertBST(root, 0); 
    root = insertBST(root, 2);
    root = insertBST(root, 7);
    root = insertBST(root, 6);
    root = insertBST(root, 8);
    root = insertBST(root, 4);

    printf("Inorder traversal of BST: ");
    inorder(root);

    return 0;
}

// int main(){
//     struct node* root = NULL;
//     int choice, value;

//     while(1){
//         printf("\n MENU \n");
//         printf("1. Insert a node.\n");
//         printf("2. Inorder traversal of BST.\n");
//         printf("3. Exit\n");

//         printf("Enter your choice: "); scanf("%d", &choice);

//         switch(choice){
//             case 1: 
//                 printf("Enter the value of the node: "); scanf("%d", &value);
//                 root = insertBST(root, value);
//                 printf("Node inserted.\n");
//                 break;

//             case 2:
//                 printf("Inorder traversal of BST: ");
//                 inorder(root);
//                 break;

//             case 3: 
//                 printf("exiting.....");
//                 exit(0);

//             default:
//                 printf("Invalid option! Enter again.\n");
//         }

//     }

//     return 0;
    
// }