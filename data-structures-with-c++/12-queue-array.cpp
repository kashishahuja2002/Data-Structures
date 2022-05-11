//  Kashish Ahuja
//  Program for operations on queue using array

#include<iostream>
using namespace std;
#include<stdlib.h>

#define max 5

class Queue
{
    private:
        int queue[max], rear=-1, front=0;
    
    public:
        void enqueue()
        {
            if(rear==max-1)
                cout<<"\nQueue Overflow";
            else
            {
                int data;
                cout<<"\nEnter element you want to insert: ";
                cin>>data;
                rear++;
                queue[rear]=data;
                cout<<"Element "<<data<<" is inserted in queue";
            }
        }

        void dequeue()
        {
            if(rear<front)
                cout<<"\nQueue underflow";
            else
            {
                cout<<"\nElement "<<queue[front]<<" is deleted from queue";
                front++;
            }
        }

        void display()
        {
            if(rear<front)
                cout<<"\nQueue underflow";
            else
            {
                cout<<"\nQueue: ";
                for(int i=front; i<=rear; i++)
                    cout<<queue[i]<<" ";
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