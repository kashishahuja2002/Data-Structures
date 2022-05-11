//  Kashish Ahuja   
//  Program for operations on queue using linked list

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;
};

typedef struct Queue node;
node *rear=NULL;
node *front=NULL;

void enqueue();
void dequeue();
void display();

void main()
{
    int choice;
    do
    {
        printf("\n\n1) Insert an element (Enqueue)\n2) Delete an element (Dequeue)\n3) Display\n4) Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: enqueue();
                    break;

            case 2: dequeue();
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

void enqueue()
{
    node *p;
    p=(node *)malloc(sizeof(node));
    printf("\nEnter the element you want to insert: ");
    scanf("%d",&p->data);
    if(rear==NULL)
    {
        rear=front=p;
        p->next=NULL;
    }
    else
    {
        rear->next=p;
        p->next=NULL;
        rear=p;
    }
    printf("Element %d is inserted in queue",p->data);
}

void dequeue()
{
    if(front==NULL)
        printf("\nQueue underflow");
    else
    {
        node *temp;
        temp=front;
        if(rear==front)
            rear=front=NULL;
        else
            front=front->next;
        printf("Element %d is deleted from queue",temp->data);
        free(temp);
    }
}

void display()
{
    node *temp;
    temp=front;
    printf("\nQueue: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}