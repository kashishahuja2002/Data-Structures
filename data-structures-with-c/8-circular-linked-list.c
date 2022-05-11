//  Kashish Ahuja
//  Program for operations on circular linked list

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

struct CircularLinkedList
{
    int data;
    struct CircularLinkedList *next;
};

typedef struct CircularLinkedList node;
node *start=NULL;
node *last=NULL;
int count = 0;

void insertAtBegin()
{
    node *p;
    p=(node *)malloc(sizeof(node));
    printf("\nEnter element to be inserted: ");
    scanf("%d",&p->data);
    if(start==NULL)
    {
        start=last=p;
        p->next=p;
    }
    else
    {
        p->next=start;
        last->next=p;
        start=p;
    }
    printf("%d is inserted at beginning",p->data);
    count++;
}

void insertAtPosition()
{
    int pos;
    printf("\nEnter position to inserted element: ");
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
                p->next=p;
            }
            else
            {
                p->next=start;
                last->next=p;
                start=p;
            }
        }
        else if(pos==count+1)
        {
            last->next=p;
            last=p;
            last->next=start;
        }
        else
        {
            int i=1;
            node *temp;
            temp=start;
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            p->next=temp->next;
            temp->next=p;
        }
        printf("%d is inserted at position %d",p->data, pos);
        count++;
    }
    else    
        printf("Position %d does not exist in list",pos);
}

void insertAtEnd()
{
    node *p;
    p=(node *)malloc(sizeof(node));
    printf("\nEnter data to be inserted in node: ");
    scanf("%d",&p->data);
    if(start==NULL)
    {
        start=last=p;
        p->next=p;
    }
    else
    {
        last->next=p;
        last=p;
        last->next=start;
    }
    printf("%d is inserted at end",p->data);
    count++;
}

void display()
{
    node *temp;
    temp=start;
    printf("\nList: ");
    // do
    // {
    //     printf("%d ",temp->data);
    //     temp=temp->next;
    // } while (temp!=start);

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
            last->next=start;
        }
        printf("\n%d is deleted from beginning",temp->data);
        count--;
        free(temp);
    }
}

void deleteFromPosition()
{
    if(start==NULL)
            printf("\nList underflow");
    else
    {
        int pos, i=1;
        printf("\nEnter position from where you want to delete node: ");
        scanf("%d",&pos);
        if(pos>0 && pos<=count)
        {
            node *temp, *p;
            temp=start;
            if(pos==1)
            {
                if(start==last)
                    start=last=NULL;
                else
                {
                    start=start->next;
                    last->next=start;
                }
            }
            else if(pos==count)
            {
                while(temp->next!=last->next)
                {
                    p=temp;
                    temp=temp->next;
                }
                last=p;
                p->next=start;
            }
            else
            {
                while(i<pos)
                {
                    p=temp;
                    temp=temp->next;
                    i++;
                }
                p->next=temp->next;
                temp->next=NULL;
            }
            printf("%d is deleted from position %d",temp->data,pos);
            count--;
            free(temp);
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
        node *temp, *p;
        temp=start;
        if(start==last)
            start=last=NULL;
        else
        {
            while(temp->next!=last->next)
            {
                p=temp;
                temp=temp->next;
            }
            last=p;
            p->next=start;
        }
        printf("\n%d is deleted from end",temp->data);
        count--;
        free(temp);
    }
}

void main()
{
    int choice;
    do
    {
        printf("\n\n1) Insert an element at the beginning\n2) Insert an element at a position\n3) Insert an element at the end\n4) Display\n5) Delete an element from the beginning\n6) Delete an element from a position\n7) Delete an element from the end\n8) Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: insertAtBegin();
                    break;

            case 2: insertAtPosition();
                    break;

            case 3: insertAtEnd();
                    break;

            case 4: display();
                    break;

            case 5: deleteFromBegin();
                    break;

            case 6: deleteFromPosition();
                    break;

            case 7: deleteFromEnd();
                    break;
                
            case 8: exit(0);

            default: printf("\nInvalid choice");
        }

    } while (choice!=8);
    getch();
}