//  Kashish Ahuja
//  Program for operations on circular doubly linked list

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct CircularDoublyLinkedList
{
    int data;
    struct CircularDoublyLinkedList *prev, *next;
};

typedef struct CircularDoublyLinkedList node;
node *start=NULL;
node *last=NULL;
int count=0;

void insertAtBegin()
{
    node *p;
    p=(node *)malloc(sizeof(node));
    printf("\nEnter element to be inserted: ");
    scanf("%d",&p->data);
    if(start==NULL)
    {
        start=last=p;
        p->prev=p->next=p;
    }
    else
    {
        p->next=start;
        start->prev=p;
        start=p;
        start->prev=last;
        last->next=start;
    }
    printf("%d is inserted at the beginning",p->data);
    count++;
}

void insertAtPosition()
{
    int pos; 
    printf("\nEnter position to insert element: ");
    scanf("%d",&pos);
    if(pos>0 && pos<=count+1)
    {
        node *p;
        p=(node *)malloc(sizeof(node));
        printf("Enter element to be inserted: ");
        scanf("%d",&p->data);
        if(pos==1)
        {
            if(start==NULL)
            {
                start=last=p;
                p->prev=p->next=p;
            }
            else
            {
                p->next=start;
                start->prev=p;
                start=p;
                start->prev=last;
                last->next=start;
            }
        }
        else if(pos==count+1)
        {
            last->next=p;
            p->prev=last;
            last=p;
            last->next=start;
            start->prev=last;
        }
        else
        {
            node *temp;
            temp=start;
            int i=1;
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            p->next=temp->next;
            p->prev=temp;
            temp->next->prev=p;
            temp->next=p;
        }
        printf("%d is inserted at position %d",p->data,pos);
        count++;
    }
    else
        printf("\nPosition %d does not exist in list",pos);
}

void insertAtEnd()
{
    node *p;
    p=(node *)malloc(sizeof(node));
    printf("\nEnter element to be inserted: ");
    scanf("%d",&p->data);
    if(start==NULL)
    {
        start=last=p;
        p->prev=p->next=p;
    }
    else
    {
        last->next=p;
        p->prev=last;
        last=p;
        last->next=start;
        start->prev=last;
    }
    printf("%d is inserted at the end",p->data);
    count++;
}

void displayForward()
{
    node *temp;
    temp=start;
    printf("\nList: ");
    if(start!=NULL)
    {
        while(temp->next != start)  
        {  
            printf("%d ", temp->data);  
            temp = temp->next;  
        }  
        printf("%d ", temp->data);
    }
}

void displayBackward()
{
    node *temp;
    temp=last;
    printf("\nList: ");
    if(last!=NULL)
    {
        while(temp->prev!=last)
        {
            printf("%d ",temp->data);
            temp=temp->prev;
        }
        printf("%d ",temp->data);
    }
}

void deleteFromBegin()
{
    if(start==NULL)
        printf("\nList underflow");
    else
    {
        node *temp;
        temp=start;
        if(start==last)
            start=last=NULL;
        else
        {
            start=start->next;
            start->prev=last;
            last->next=start;
        }
        printf("\n%d is deleted from beginning",temp->data);
        free(temp);
        count--;
    }
}

void deleteFromPosition()
{
    if(start==NULL)
        printf("\nList underflow");
    else
    {
        int pos;
        printf("\nEnter position to delete element: ");
        scanf("%d",&pos);
        if(pos>0 && pos<=count)
        {   
            node *temp;
            if(pos==1)
            {
                temp=start;
                if(start==last)
                    start=last=NULL;
                else
                {
                    start=start->next;
                    start->prev=last;
                    last->next=start;
                }
            }
            else if(pos==count)
            {
                temp=last;
                last=last->prev;
                last->next=start;
                start->prev=last;
            }
            else
            {
                node *p, *q;
                temp=start;
                int i=1;
                while(i<pos)
                {
                    p=temp;
                    temp=temp->next;
                    i++;
                }
                p->next=temp->next;
                q=temp->next;
                q->prev=p;
                temp->next=temp->prev=NULL;            
            }
            printf("%d is deleted from position %d",temp->data, pos);
            free(temp);
            count--;
        }
        else
            printf("Position %d does not exist in list",pos);
    }
}

void deleteFromEnd()
{
    if(start==NULL)
        printf("\nList underflow");
    else
    {
        node *temp;
        if(start==last)
        {
            temp=start;
            start=last=NULL;
        }
        else
        {
            temp=last;
            last=last->prev;
            last->next=start;
            start->prev=last;
        }
        printf("\n%d is deleted from end",temp->data);
        free(temp);
        count--;
    }
}

void main()
{
    int choice;
    do
    {
        printf("\n\n1) Insert an element at the beginning\n2) Insert an element at a position\n3) Insert an element at the end\n4) Display (Forward)\n5) Display (Backward)\n6) Delete an element from the beginning\n7) Delete an element from a position\n8) Delete an element from the end\n9) Exit");
        printf("\nEnter you choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1: insertAtBegin();
                    break;

            case 2: insertAtPosition();
                    break;

            case 3: insertAtEnd();
                    break;

            case 4: displayForward();
                    break;

            case 5: displayBackward();
                    break;

            case 6: deleteFromBegin();
                    break;

            case 7: deleteFromPosition();
                    break;

            case 8: deleteFromEnd();
                    break;
                
            case 9: exit(0);

            default: printf("\nInvalid choice");
        }

    } while (choice!=9);
    getch();
}