//  Kashish Ahuja
//  Program for operations on dequeue using linked list

#include<iostream>
using namespace std;
#include<stdlib.h>

struct DequeueLinkedList
{
    int data;
    struct DequeueLinkedList *next;
};

typedef struct DequeueLinkedList node;

class Dequeue
{
    private:
        node *rear=NULL;
        node *front=NULL;

    public:
        void enqueue_front()
        {
            node *p;
            p=new node;
            cout<<"\nEnter the element you want to insert: ";
            cin>>p->data;
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
            cout<<"Element "<<p->data<<" is inserted in queue";
        }

        void enqueue_rear()
        {
            node *p;
            p=new node;
            cout<<"\nEnter the element you want to insert: ";
            cin>>p->data;
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
            cout<<"Element "<<p->data<<" is inserted in queue";
        }

        void dequeue_front()
        {
            if(front==NULL)
                cout<<"\nQueue underflow";
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
                cout<<"Element "<<temp->data<<" is deleted from queue";
                delete(temp);
            }
        }

        void dequeue_rear()
        {
            if(rear==NULL)
                cout<<"\nQueue underflow";
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
                cout<<"\n"<<temp->data<<" is deleted from queue";
                delete(temp);
            }
        }

        void display()
        {
            node *temp;
            temp=front;
            cout<<"\nQueue: ";
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }

};

int main()
{
    Dequeue dq;
    int choice, dqchoice;
    cout<<"\n\n1) Input restricted queue\n2) Output restricted queue";
    cout<<"\nEnter your choice: ";
    cin>>dqchoice;
    switch (dqchoice)
    {
        case 1: 
        {
            do
            {
                cout<<"\n\n1) Insert an element from rear\n2) Delete an element from front\n3) Delete an element from rear\n4) Display\n5) Exit";
                cout<<"\nEnter your choice: ";
                cin>>choice;
                switch (choice)
                {
                    case 1: dq.enqueue_rear();
                            break;

                    case 2: dq.dequeue_front();
                            break;

                    case 3: dq.dequeue_rear();
                            break;

                    case 4: dq.display();
                            break;

                    case 5: exit(0);

                    default: cout<<"\nInvalid choice";
                                break;
                }
            } while (choice!=5);
        }

        case 2: 
        {
            do
            {
                cout<<"\n\n1) Insert an element at front\n2) Insert an element at rear\n3) Delete an element from front\n4) Display\n5) Exit";
                cout<<"\nEnter your choice: ";
                cin>>choice;
                switch (choice)
                {
                    case 1: dq.enqueue_front();
                            break;

                    case 2: dq.enqueue_rear();
                            break;

                    case 3: dq.dequeue_front();
                            break;

                    case 4: dq.display();
                            break;

                    case 5: exit(0);

                    default: cout<<"\nInvalid choice";
                                break;
                }
            } while (choice!=5);
        }

        default: cout<<"\nInvalid choice";
    }
    return 0;
}