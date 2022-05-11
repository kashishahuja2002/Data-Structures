//  Kashish Ahuja
//  Program for insertion sort

#include<iostream>
using namespace std;

int main()
{
    int n, *arr;
    cout<<"Enter number of elements in array: ";
    cin>>n;
    arr=new int[n];
    cout<<"Enter elements of array: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];

    //  sorting
    for(int i=1; i<n; i++)
    {
        int temp=arr[i];
        int j=i-1;
        while((j>=0) && temp<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }

    cout<<"\nArray elements after sorting: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;
}