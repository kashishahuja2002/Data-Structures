//  Kashish Ahuja
//  Program for operations on circular queue using array

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define max 5
int cirque[max], rear=-1, front=-1;

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
    if(front==(rear+1)%max)
        printf("\nQueue overflow");
    else
    {
        int data;
        printf("\nEnter element you want to insert: ");
        scanf("%d",&data);
        rear=(rear+1)%max;
        cirque[rear]=data;
        if(front==-1)
            front++;
        printf("Element %d is inserted in queue",data);
    }
}

void dequeue()
{
    if(front==-1)
        printf("\nQueue underflow");
    else
    {
        if(front==rear)
        {
            printf("%d is deleted from queue",cirque[front]);
            front=rear=-1;
        }
        else
        {
            printf("%d is deleted from queue",cirque[front]);
            front=(front+1)%max;
        }
    }
}

void display()
{
    printf("\nCircular queue: ");
    if(front!=-1)
    {
        int i=front;
        while (i!=rear)
        {
            printf("%d ",cirque[i]);
            i=(i+1)%max;
        }
        printf("%d ",cirque[i]);
    }
}