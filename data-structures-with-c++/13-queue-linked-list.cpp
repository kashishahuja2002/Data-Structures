//  Kashish Ahuja   
//  Program for operations on queue using linked list

#include<iostream>
using namespace std;
#include<stdlib.h>

struct QueueLinkedList
{
    int data;
    struct QueueLinkedList *next;
};

typedef struct QueueLinkedList node;

class Queue
{
    private:
        node *rear=NULL;
        node *front=NULL;
    
    public:
        void enqueue()
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

        void dequeue()
        {
            if(front==NULL)
                printf("\nQueue underflow");
            else
            {
                node *temp;
                temp=front;
                if(rear==front)
                    rear=front=NULL;
                else
                    front=front->next;
                cout<<"Element "<<temp->data<<" is deleted from queue";
                delete(temp);
            }
        }

        void display()
        {
            if(front==NULL)
                cout<<"\nQueue underflow";
            else
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
        }
};

int main()
{
    Queue q;
    int choice;
    do
    {
        cout<<"\n\n1) Insert an element (Enqueue)\n2) Delete an element (Dequeue)\n3) Display\n4) Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1: q.enqueue();
                    break;

            case 2: q.dequeue();
                    break;

            case 3: q.display();
                    break;

            case 4: exit(0);

            default: cout<<"\nInvalid choice";
                        break;
        }
    } while (choice!=4);
    return 0;
}