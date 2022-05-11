//  Kashish Ahuja
//  Program for operations on binary tree

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct binaryTree
{
    int data;
    struct binaryTree *left, *right;
};

typedef struct binaryTree node;
node *root=NULL;
int count=1;

node* insert(node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
// void display(root);

void main()
{
    int choice;
    do
    {
        printf("\n\n1) Insert an element\n2) Traversing\n3) Display\n4) Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert(root);
                    printf("Element is inserted successfully");
                    break;

            case 2: inorder(root);
                    preorder(root);
                    postorder(root);
                    break;
                
            // case 3: display(root);
                    // break;

            case 4: exit(0);

            default: printf("\nInvalid choice");
        }
    } while (choice!=4);
    
    getch();
} 

node* insert(node *p)
{
    if(p==NULL)
    {
        p=(node *)malloc(sizeof(node));
        printf("\nEnter element to insert: ");
        scanf("%d",&p->data);
        p->left=p->right=NULL;
        count++;
    }
    else if(count%2==0)
        p->left=insert(p->left);
    else
        p->right=insert(p->right);
        
    return p;
}

void inorder(node *p)
{
    printf("\nInorder: ");
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}

void preorder(node *p)
{
    printf("\nPreorder: ");
    if(p!=NULL)
    {
        printf("%d ",p->data);
        inorder(p->left);
        inorder(p->right);
    }
}

void postorder(node *p)
{
    printf("\nPostorder: ");
    if(p!=NULL)
    {
        inorder(p->left);
        inorder(p->right);
        printf("%d ",p->data);
    }
}
