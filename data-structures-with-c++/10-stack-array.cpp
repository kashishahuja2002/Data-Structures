//  Kashish Ahuja
//  Program for operations on stack using array

#include<iostream>
using namespace std;
#include<stdlib.h>

#define max 5

class Stack
{
    private:
        int stack[max], top=-1;

    public:
        void push()
        {
                if(top==max-1)
                        cout<<"\nStack Overflow";
                else
                {
                        int data;
                        cout<<"\nEnter an element: ";
                        cin>>data;
                        top++;
                        stack[top]=data;
                        cout<<data<<" is inserted in stack";
                }
        }

        void pop()
        {
                if(top==-1)
                        cout<<"\nStack Underflow";
                else
                {
                        cout<<"\n"<<stack[top]<<" is deleted from stack";
                        top--;
                }
        }

        void display()
        {
                cout<<"\nStack: ";
                for(int i=top; i>=0; i--)
                        cout<<stack[i]<<" ";
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

