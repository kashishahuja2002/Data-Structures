//  Kashish Ahuja
//  Program for operations on dequeue using array

#include<iostream>
using namespace std;
#include<stdlib.h>

#define max 5

class Dequeue
{
    private:
        int dq[max], rear=-1, front=-1;
    
    public:
        void enqueue_front()
        {
            if(front==0)
                cout<<"\nCan not insert element from front";
            else
            {
                int data;
                cout<<"\nEnter element to be inserted: ";
                cin>>data;
                if(front==-1)
                    front=rear=0;
                else
                    front--;
                dq[front]=data;
                cout<<data<<" is inserted in dequeue";
            }
        }

        void enqueue_rear()
        {
            if(rear==max-1)
                cout<<"\nQueue overflow";
            else
            {
                int data;
                cout<<"\nEnter element to be inserted: ";
                cin>>data;
                if(front==-1)
                    front=0;
                rear++;
                dq[rear]=data;
                cout<<data<<" is inserted in dequeue";
            }
        }

        void dequeue_front()
        {
            if(front==-1 || rear<front)
                cout<<"\nQueue underflow";
            else
            {
                cout<<"\n"<<dq[front]<<" is deleted from dequeue";
                front++;
            }
        }

        void dequeue_rear()
        {
            if(front==-1 || rear<front)
                cout<<"\nQueue underflow";
            else
            {
                cout<<"\n"<<dq[rear]<<" is deleted from dequeue";
                rear--;
            }
        }

        void display()
        {
            cout<<"\nDequeue: ";
            if(front!=-1)
            {
                for(int i=front; i<=rear; i++)
                    cout<<dq[i]<<" ";
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