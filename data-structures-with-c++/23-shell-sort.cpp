//  Kashish Ahuja
//  Program for shell sort

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

    for (int gap=n/2; gap>0; gap/=2)
    {
        for (int i=gap; i<n; i+=1)
        {
            int temp = arr[i];
            int j;            
            for (j=i; j>=gap && arr[j-gap] > temp; j-=gap)
                arr[j] = arr[j-gap];
            arr[j] = temp;
        }
    cout<<"\nArray elements after sorting: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    }

    return 0;
}