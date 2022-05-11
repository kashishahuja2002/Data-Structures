//  Kashish Ahuja
//  Program for operations on stack using linked list

#include<iostream>
using namespace std;
#include<stdlib.h>

struct StackLinkedList
{
    int data;
    struct StackLinkedList *next;
};

typedef struct StackLinkedList node;

class Stack
{
    private:
        node *top=NULL;

    public:
        void push()
        {
            node *p;
            p=new node;
            int data;
            cout<<"\nEnter an element: ";
            cin>>p->data;
            p->next=top;
            top=p;
            cout<<p->data<<" is inserted in stack";
        }

        void pop()
        {
            if(top==NULL)
                cout<<"\nStack Underflow";
            else
            {
                node *temp;
                temp=top;
                top=top->next;
                cout<<"\n"<<temp->data<<" is deleted from stack";
                delete(temp);
            }
        }

        void display()
        {
                cout<<"\nStack: ";
                node *temp=top;
                while(temp!=NULL)
                {
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
        }
};

int main()
{
    Stack s;
    int choice;
    do
    {
        cout<<"\n\n1) Insert an element (Push)\n2) Delete an element (Pop)\n3) Display\n4) Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1: s.push();
                    break;

            case 2: s.pop();
                    break;

            case 3: s.display();
                    break;

            case 4: exit(0);

            default: cout<<"\nInvalid choice";
                     break;
        }
    } while (choice!=4);
    return 0;
}