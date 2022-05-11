//  Kashish Ahuja
//  Program for selection sort

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
    for(int i=0; i<n-1; i++)
    {
        int min_idx=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[min_idx])
                min_idx=j;
        }
        int temp=arr[i];
        arr[i]=arr[min_idx];
        arr[min_idx]=temp;
    }

    cout<<"\nArray elements after sorting: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;
}