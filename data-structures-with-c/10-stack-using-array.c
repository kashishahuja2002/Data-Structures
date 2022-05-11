//  Kashish Ahuja
//  Program for operations on stack using array

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define max 5
int stack[max], top=-1;
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
        if(top==max-1)
                printf("\nStack Overflow");
        else
        {
                int data;
                printf("\nEnter an element: ");
                scanf("%d",&data);
                top++;
                stack[top]=data;
                printf("%d is inserted in stack",data);
        }
}

void pop()
{
        if(top==-1)
                printf("\nStack Underflow");
        else
        {
                printf("\n%d is deleted from stack",stack[top]);
                top--;
        }
}

void display()
{
        printf("\nStack: ");
        for(int i=top; i>=0; i--)
                printf("%d ",stack[i]);
}