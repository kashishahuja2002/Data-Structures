//  Kashish Ahuja
//  Program for bubble sort

#include<iostream>
using namespace std;

int main()
{
    int arr[15], i, j, n, temp;

    cout<<"Enter number of elements of array: ";
    cin>>n;

    cout<<"Enter elements of array: ";
    for(i=0; i<n; i++)
        cin>>arr[i]; 

    //  sorting
    for(i=1; i<n; i++)
    {
        for(j=0; j<(n-1); j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    cout<<"Array elements after sorting: ";
    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;
} 
