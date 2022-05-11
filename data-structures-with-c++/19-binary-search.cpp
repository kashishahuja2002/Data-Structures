//  Kashish Ahuja
//  Program for binary search

#include<iostream>
using namespace std;

int main() {
    int arr[50];
    cout<<"Enter size of array: ";
    int n;  cin>>n;
    cout<<"Enter elements of array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched: ";
    int key; cin>>key;
    int flag=0;
    int low=0, high=(n-1), mid;
    while(low<=high) {
        mid = (low+high)/2;
        if(key==arr[mid]) {
            cout<<"Element "<<key<<" found at index "<<mid<<".";
            flag=1;
            break;
        }
        else if(key<arr[mid]) {
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    if(flag==0) {
        cout<<"Element "<<key<<" not found.";
    }
    return 0;
}