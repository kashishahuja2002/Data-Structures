//  Kashish Ahuja
//  Program for operations on dequeue using linked list

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

struct Dequeue
{
    int data;
    struct Dequeue *next;
};

typedef struct Dequeue node;
node *rear=NULL;
node *front=NULL;

void enqueue_front();
void enqueue_rear();
void dequeue_front();
void dequeue_rear();
void display();

void main()
{
    int choice, dqchoice;
    printf("\n\n1) Input restricted queue\n2) Output restricted queue");
    printf("\nEnter your choice: ");
    scanf("%d",&dqchoice);
    switch (dqchoice)
    {
        case 1: 
        {
            do
            {
                printf("\n\n1) Insert an element from rear\n2) Delete an element from front\n3) Delete an element from rear\n4) Display\n5) Exit");
                printf("\nEnter your choice: ");
                scanf("%d",&choice);
                switch (choice)
                {
                    case 1: enqueue_rear();
                            break;

                    case 2: dequeue_front();
                            break;

                    case 3: dequeue_rear();
                            break;

                    case 4: display();
                            break;

                    case 5: exit(0);

                    default: printf("\nInvalid choice");
                                break;
                }
            } while (choice!=5);
        }

        case 2: 
        {
            do
            {
                printf("\n\n1) Insert an element at front\n2) Insert an element at rear\n3) Delete an element from front\n4) Display\n5) Exit");
                printf("\nEnter your choice: ");
                scanf("%d",&choice);
                switch (choice)
                {
                    case 1: enqueue_front();
                            break;

                    case 2: enqueue_rear();
                            break;

                    case 3: dequeue_front();
                            break;

                    case 4: display();
                            break;

                    case 5: exit(0);

                    default: printf("\nInvalid choice");
                                break;
                }
            } while (choice!=5);
        }

        default: printf("\nInvalid choice");
    }
    getch();
}

void enqueue_front()
{
    node *p;
    p=(node *)malloc(sizeof(node));
    printf("\nEnter the element you want to insert: ");
    scanf("%d",&p->data);
    if(front==NULL)
    {
        rear=front=p;
        p->next=NULL;
    }
    else
    {
        p->next=front;
        front=p;
    }
    printf("Element %d is inserted in queue",p->data);
}

void enqueue_rear()
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

void dequeue_front()
{
    if(front==NULL)
        printf("\nQueue underflow");
    else
    {
        node *temp;
        temp=front;
        if(temp->next==NULL)
        {
            rear=NULL;
            front=NULL;
        }
        else
            front=front->next;
        printf("Element %d is deleted from queue",temp->data);
        free(temp);
    }
}

void dequeue_rear()
{
    if(rear==NULL)
        printf("\nQueue underflow");
    else
    {
        node *temp, *p;
        temp=front;
        if(temp->next==NULL)
        {
            rear=NULL;
            front=NULL;
        }
        else
        {
            while(temp->next!=NULL)
            {
                p=temp;
                temp=temp->next;
            }
            p->next=NULL;
            rear=p;
        }
        printf("\n%d is deleted from queue",temp->data);
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