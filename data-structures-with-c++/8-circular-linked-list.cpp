//  Kashish Ahuja
//  Program for operations on circular linked list

#include<iostream>
using namespace std;
#include<stdlib.h>

struct CircularLinkedList
{
    int data;
    struct CircularLinkedList *next;
};

typedef struct CircularLinkedList node;
node *start=NULL;
node *last=NULL;

class CLL
{
    private:
        int count=0;

    public:
        void insertAtBegin()
        {
            node *p;
            p=new node;
            cout<<"\nEnter element to be inserted: ";
            cin>>p->data;
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
            cout<<p->data<<" is inserted at beginning";
            count++;
        }

        void insertAtPosition()
        {
            int pos;
            cout<<"\nEnter position to inserted element: ";
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
                cout<<p->data<<" is inserted at position "<<pos;
                count++;
            }
            else    
                cout<<"Position "<<pos<<" does not exist in list";
        }

        void insertAtEnd()
        {
            node *p;
            p=new node;
            cout<<"\nEnter data to be inserted in node: ";
            cin>>p->data;
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
            cout<<p->data<<" is inserted at end";
            count++;
        }

        void display()
        {
            node *temp;
            temp=start;
            cout<<"\nList: ";
            // do
            // {
            //     cout<<"%d ",temp->data);
            //     temp=temp->next;
            // } while (temp!=start);

            if(start!=NULL)
            {
                while(temp->next != start)  
                {  
                    cout<<temp->data<<" ";  
                    temp = temp->next;  
                }  
                cout<<temp->data;
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
                    last->next=start;
                }
                cout<<"\n"<<temp->data<<" is deleted from beginning";
                count--;
                delete(temp);
            }
        }

        void deleteFromPosition()
        {
            if(start==NULL)
                    cout<<"\nList underflow";
            else
            {
                int pos, i=1;
                cout<<"\nEnter position from where you want to delete node: ";
                cin>>pos;
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
                    cout<<temp->data<<" is deleted from position "<<pos;
                    count--;
                    delete(temp);
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
                cout<<"\n"<<temp->data<<" is deleted from end";
                count--;
                delete(temp);
            }
        }
};

int main()
{
    CLL cll;
    int choice;
    do
    {
        cout<<"\n\n1) Insert an element at the beginning\n2) Insert an element at a position\n3) Insert an element at the end\n4) Display\n5) Delete an element from the beginning\n6) Delete an element from a position\n7) Delete an element from the end\n8) Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: cll.insertAtBegin();
                    break;

            case 2: cll.insertAtPosition();
                    break;

            case 3: cll.insertAtEnd();
                    break;

            case 4: cll.display();
                    break;

            case 5: cll.deleteFromBegin();
                    break;

            case 6: cll.deleteFromPosition();
                    break;

            case 7: cll.deleteFromEnd();
                    break;
                
            case 8: exit(0);

            default: cout<<"\nInvalid choice";
        }

    } while (choice!=8);
    return 0;
}