//  Kashish Ahuja
//  Program for operations on dequeue using array

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define max 5
int dequeue[max], rear=-1, front=-1;

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
    if(front==0)
        printf("\nCan not insert element from front");
    else
    {
        int data;
        printf("\nEnter element to be inserted: ");
        scanf("%d",&data);
        if(front==-1)
            front=rear=0;
        else
            front--;
        dequeue[front]=data;
        printf("%d is inserted in dequeue",data);
    }
}

void enqueue_rear()
{
    if(rear==max-1)
        printf("\nQueue overflow");
    else
    {
        int data;
        printf("\nEnter element to be inserted: ");
        scanf("%d",&data);
        if(front==-1)
            front=rear=0;
        else    
            rear++;
        dequeue[rear]=data;
        printf("%d is inserted in dequeue",data);
    }
}

void dequeue_front()
{
    if(front==-1 || rear<front)
        printf("\nQueue underflow");
    else
    {
        printf("\n%d is deleted from dequeue",dequeue[front]);
        front++;
    }
}

void dequeue_rear()
{
    if(front==-1 || rear<front)
        printf("\nQueue underflow");
    else
    {
        printf("\n%d is deleted from dequeue",dequeue[rear]);
        rear--;
    }
}

void display()
{
    printf("\nDequeue: ");
    if(front!=-1)
    {
        for(int i=front; i<=rear; i++)
            printf("%d ",dequeue[i]);
    }
}