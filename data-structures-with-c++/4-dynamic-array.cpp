//  Kashish Ahuja
//  Program for dynamic memory allocation in 1D and 2D array

#include<iostream>
using namespace std;

int main()
{
    int *arr_1, **arr_2;
    int n, r, c;

    cout<<"Enter number of elements in 1D array: ";
    cin>>n;
    arr_1 = new int[n];
    cout<<"Enter array elements: ";
    for(int i=0; i<n; i++)
        cin>>arr_1[i];
    cout<<"1D array: ";
    for(int i=0; i<n; i++)
        cout<<arr_1[i]<<" ";
    delete[] arr_1;

    cout<<"\nEnter number of rows and columns in 2D array: ";
    cin>>r>>c;
    arr_2 = new int *[r];
    for(int i=0; i<r; i++)
        arr_2[i] = new int[c];
    cout<<"Enter array elements: ";
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin>>arr_2[i][j];
    cout<<"2D array: ";
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cout<<arr_2[i][j]<<" ";
    for(int i=0; i<r; i++)
        delete[] arr_2[i];
    delete[] arr_2;

    return 0;
}