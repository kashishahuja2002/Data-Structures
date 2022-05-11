//  Kashish Ahuja
//  Program for operations on stack using linked list

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Stack
{
    int data;
    struct Stack *next;
};

typedef struct Stack node;
node *top=NULL;

void push();
void pop();
void display();

void main()
{
    int choice;
    do
    {
        printf("\n\n1) Insert an element (Push)\n2) Delete an element (Pop)\n3) Display\n4) Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: push();
                    break;

            case 2: pop();
                    break;

            case 3: display();
                    break;

            case 4: exit(0);

            default: printf("\nInvalid choice");
                     break;
        }
    } while (choice!=4);
    getch();
}

void push()
{
    node *p;
    p=(node *)malloc(sizeof(node));
    int data;
    printf("\nEnter an element: ");
    scanf("%d",&p->data);
    p->next=top;
    top=p;
    printf("%d is inserted in stack",p->data);
}

void pop()
{
    if(top==NULL)
        printf("\nStack Underflow");
    else
    {
        node *temp;
        temp=top;
        top=top->next;
        printf("\n%d is deleted from stack",temp->data);
        free(temp);
    }
}

void display()
{
        printf("\nStack: ");
        node *temp=top;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
}