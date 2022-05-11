//  Kashish Ahuja
//  Program for operations on singly linked list

#include<iostream>
using namespace std;
#include<stdlib.h>

int count=0;

struct SinglyLinkedList
{
    int data;
    struct SinglyLinkedList *next;
};

typedef struct SinglyLinkedList node;
node *start=NULL;

class SLL 
{
    private:
        int count = 0; 
        
    public:

        void insertAtBegin()
        {
            node *p;
            p=new node;
            cout<<"\nEnter data to be inserted in node: ";
            cin>>p->data;
            p->next=start;
            start=p;
            cout<<p->data<<" is inserted at beginning";
            count++;
        }

        void insertAtPosition()
        {
            int pos;
            cout<<"\nEnter position to inserted node: ";
            cin>>pos;
            if((pos>0 && pos<=count+1) || pos==1)
            {
                node *p, *temp;

                p = new node;
                cout<<"Enter data to be inserted in node: ";
                cin>>p->data;
                if(pos==1)
                {
                    p->next=start;
                    start=p;
                }
                else
                {
                    int i=1;
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
            p = new node;
            cout<<"\nEnter data to be inserted in node: ";
            cin>>p->data;
            if(start==NULL)
            {
                p->next=start;
                start=p;
            }
            else
            {
                node *temp;
                temp=start;
                while(temp->next!=NULL)
                    temp=temp->next;
                temp->next=p;
                p->next=NULL;
            }
            cout<<p->data<<" is inserted at end";
            count++;
        }

        void display()
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

        void deleteFromBegin()
        {
            if(start==NULL)
                cout<<"\nList underflow";
            else
            {
                node *temp;
                temp=start;
                start=start->next;
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
                        start=start->next;
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
                    cout<<"\n"<<temp->data<<" is deleted from position "<<pos;
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
                if(count==1)
                    start=start->next;
                else
                {
                    while(temp->next!=NULL)
                    {
                        p=temp;
                        temp=temp->next;
                    }
                    p->next=NULL;
                }
                cout<<"\n"<<temp->data<<" is deleted from end";
                count--;
                delete(temp);
            }
        }
};



int main()
{
    int choice;
    SLL sll;
    do
    {
        cout<<"\n\n1) Insert an element at the beginning\n2) Insert an element at a position\n3) Insert an element at the end\n4) Display\n5) Delete an element from the beginning\n6) Delete an element from a position\n7) Delete an element from the end\n8) Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: sll.insertAtBegin();
                    break;

            case 2: sll.insertAtPosition();
                    break;

            case 3: sll.insertAtEnd();
                    break;

            case 4: sll.display();
                    break;

            case 5: sll.deleteFromBegin();
                    break;

            case 6: sll.deleteFromPosition();
                    break;

            case 7: sll.deleteFromEnd();
                    break;
                
            case 8: exit(0);

            default: cout<<"\nInvalid choice";
        }

    } while (choice!=8);
    return 0;
}