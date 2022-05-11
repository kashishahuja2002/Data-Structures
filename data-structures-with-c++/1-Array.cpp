//  Kashish Ahuja
//  Program to perform operations on array

#include<iostream>
using namespace std;
#include<stdlib.h>

#define max 50
int n, arr[max];

int isFull()
{
    if(n==max)
        return 1;
    else    
        return 0;
}

int isEmpty()
{
    if(n==0)
        return 1;
    else 
        return 0;
}

int inRange(int pos)
{
    if(pos>=0 && pos<=n)
        return 1;
    else    
        return 0;
}

void insertAtBegin(int ele)
{
    for(int i=n; i>0; i--)
        arr[i]=arr[i-1];
    arr[0]=ele;
    printf("Element %d is inserted at the beginning", ele);
    n++;
}

void insertAtPosition(int pos, int ele)
{
    for(int i=n; i>(pos-1); i--)
        arr[i]=arr[i-1];
    arr[(pos-1)]=ele;
    printf("Element %d is inserted at position %d", ele, pos);
    n++;
}

void insertAtEnd(int ele)
{
    arr[n]=ele;
    printf("Element %d is inserted at the end", ele);
    n++;
}

void deleteFromBegin()
{
    printf("\nElement %d is deleted from beginning", arr[0]);
    for(int i=0; i<n-1; i++)
        arr[i+1]=arr[i];
    n--;
}

void deleteFromPosition(int pos)
{
    printf("\nElement %d is deleted from position %d", arr[0], pos);
    for(int i=pos-1; i<n-1; i++)
        arr[i+1]=arr[i];
    n--;
}

void deleteFromEnd()
{
    printf("\nElement %d is deleted from end", arr[n-1]);
    n--;
}

int main()
{
    int choice, ele, pos, arr[max];
    cout<<"\nEnter number of elements in array: ";
    cin>>n;
    cout<<"Enter elements of array: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];

    do
    {
        cout<<"\n\n1) Insert an element at the beginning\n2) Insert an element at a position\n3) Insert an element at the end\n4) Display\n5) Delete an element from the beginning\n6) Delete an element from a position\n7) Delete an element from the end\n8) Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: if(!isFull())
                    {
                        cout<<"\nEnter element to be inserted: ";
                        cin>>ele;
                        insertAtBegin(ele);
                        n++;
                    }
                    else
                        cout<<"\nThe array is full.";
                    break;

            case 2: cout<<"\nEnter position to insert element: ";
                    cin>>pos;
                    if(inRange(pos))
                    {
                        if(!isFull())
                        {
                            cout<<"Enter element to be inserted: ";
                            cin>>ele;
                            insertAtPosition(pos, ele);
                            n++;
                        }
                        else
                            cout<<"\nThe array is full.";
                    }
                    else
                        cout<<"\nPosition is not in the range of array";
                    break;
            
            case 3: if(!isFull())
                    {
                        cout<<"\nEnter element to be inserted: ";
                        cin>>ele;
                        insertAtEnd(ele);
                        n++;
                    }
                    else
                        cout<<"\nPosition is not in the range of array";
                    break;

            case 4: cout<<"\nArray: ";
                    for(int i=0; i<n; i++)
                        cout<<"%d ",arr[i];
                    break;
                
            case 8: exit(0);

            default: cout<<"\nInvalid choice";
        }

    } while (choice!=8);
    
    return 0;
}