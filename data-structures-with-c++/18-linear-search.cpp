//  Kashish Ahuja
//  Program for linear search

#include<iostream>
using namespace std;

int main()
{
    int arr[15], i, n, key, search=0;

    cout<<"Enter number of elements of array: ";
    cin>>n;

    cout<<"Enter elements of array: ";
    for(i=0; i<n; i++)
        cin>>arr[i]; 

    cout<<"Enter the key element to be searched: ";
    cin>>key;

    //  searching
    for(i=0; i<n; i++)
    {
        if(key==arr[i])
        {
            cout<<"\nKey element "<<key<<" found at location "<<i;
            search=1;
        }
    }
    if(search==0)
    {
        cout<<"\nKey element "<<key<<" not found in array.";
    }

    return 0;
} 
