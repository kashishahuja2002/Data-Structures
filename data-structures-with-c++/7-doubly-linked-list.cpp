//  Kashish Ahuja
//  Program for operations on doubly linked list

#include<iostream>
using namespace std;
#include<stdlib.h>

struct DoublyLinkedList
{
    int data;
    struct DoublyLinkedList *prev, *next;
};

typedef struct DoublyLinkedList node;
node *start=NULL;
node *last=NULL;

class DLL 
{
    private:
        int count = 0;
    
    public:
        void insertAtBegin()
        {
            node *p;
            p=new node;
            cout<<"\nEnter element to be inserted: ";
            cin>>p->data;
            if(start==NULL)
            {
                p->prev=p->next=NULL;
                start=last=p;
            }
            else
            {
                p->next=start;
                start->prev=p;
                start=p;
                p->prev=NULL;
            }
            cout<<p->data<<" is inserted at the beginning";
            count++;
        }

        void insertAtPosition()
        {
            int pos; 
            cout<<"\nEnter position to insert element: ";
            cin>>pos;
            if(pos>0 && pos<=count+1)
            {
                node *p;
                p=new node;
                cout<<"Enter element to be inserted: ";
                cin>>p->data;
                if(pos==1)
                {
                    if(start==NULL)
                    {
                        start=last=p;
                        p->prev=p->next=NULL;
                    }
                    else
                    {
                        p->next=start;
                        start->prev=p;
                        start=p;
                        p->prev=NULL;
                    }
                }
                else if(pos==count+1)
                {
                    last->next=p;
                    p->prev=last;
                    p->next=NULL;
                    last=p;
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
                cout<<p->data<<" is inserted at position "<<pos;
                count++;
            }
            else
                cout<<"\nPosition "<<pos<<" does not exist in list";
        }

        void insertAtEnd()
        {
            node *p;
            p=new node;
            cout<<"\nEnter element to be inserted: ";
            cin>>p->data;
            if(start==NULL)
            {
                start=last=p;
                p->prev=p->next=NULL;
            }
            else
            {
                last->next=p;
                p->prev=last;
                p->next=NULL;
                last=p;
            }
            cout<<p->data<<" is inserted at the end";
            count++;
        }

        void displayForward()
        {
            node *temp;
            temp=start;
            cout<<"\nList: ";
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }

        void displayBackward()
        {
            node *temp;
            temp=last;
            cout<<"\nList: ";
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->prev;
            }
        }

        void deleteFromBegin()
        {
            if(start==NULL)
                cout<<"\nList underflow";
            else
            {
                node *temp;
                temp=start;
                if(start==last)
                    start=last=NULL;
                else
                {
                    start=start->next;
                    start->prev=NULL;
                }
                cout<<"\n"<<temp->data<<" is deleted from beginning";
                delete(temp);
                count--;
            }
        }

        void deleteFromPosition()
        {
            if(start==NULL)
                cout<<"\nList underflow";
            else
            {
                int pos;
                cout<<"\nEnter position to delete element: ";
                cin>>pos;
                if(pos>0 && pos<=count)
                {   
                    node *temp;
                    if(start==last)
                    {
                        temp=start;
                        start=last=NULL;
                    }
                    else if(pos==count)
                    {
                        temp=last;
                        last=last->prev;
                        last->next=NULL;
                        temp->next=temp->prev=NULL;
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
                    cout<<temp->data<<" is deleted from position "<<pos;
                    delete(temp);
                    count--;
                }
                else
                    cout<<"Position "<<pos<<" does not exist in list";
            }
        }

        void deleteFromEnd()
        {
            if(start==NULL)
                cout<<"\nList underflow";
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
                    last->next=NULL;
                }
                cout<<"\n"<<temp->data<<" is deleted from end";
                delete(temp);
                count--;
            }
        }
};

int main()
{
    int choice;
    DLL dll;
    do
    {
        cout<<"\n\n1) Insert an element at the beginning\n2) Insert an element at a position\n3) Insert an element at the end\n4) Display (Forward)\n5) Display (Backward)\n6) Delete an element from the beginning\n7) Delete an element from a position\n8) Delete an element from the end\n9) Exit";
        cout<<"\nEnter you choice: ";
        cin>>choice;

        switch (choice)
        {
            case 1: dll.insertAtBegin();
                    break;

            case 2: dll.insertAtPosition();
                    break;

            case 3: dll.insertAtEnd();
                    break;

            case 4: dll.displayForward();
                    break;

            case 5: dll.displayBackward();
                    break;

            case 6: dll.deleteFromBegin();
                    break;

            case 7: dll.deleteFromPosition();
                    break;

            case 8: dll.deleteFromEnd();
                    break;
                
            case 9: exit(0);

            default: cout<<"\nInvalid choice";
        }

    } while (choice!=9);
    return 0;
}