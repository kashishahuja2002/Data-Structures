//  Kashish Ahuja
//  Program for operations on queue using array

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define max 5
int queue[max], rear=-1, front=-1;

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
    if(rear==max-1)
        printf("\nQueue Overflow");
    else
    {
        int data;
        printf("\nEnter element you want to insert: ");
        scanf("%d",&data);
        rear++;
        queue[rear]=data;
        if(front==-1)
            front=0;
        printf("Element %d is inserted in queue",data);
    }
}

void dequeue()
{
    if(front==-1 || rear<front)
        printf("\nQueue underflow");
    else
    {
        printf("\nElement %d is deleted from queue",queue[front]);
        front++;
    }
}

void display()
{
    printf("\nQueue: ");
    if(front!=-1)
    {
        for(int i=front; i<=rear; i++)
            printf("%d ",queue[i]);
    }
}