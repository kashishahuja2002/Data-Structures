//  Kashish Ahuja
//  Program for binary search

#include<stdio.h>
#include<conio.h>

int main() {
    int arr[50];
    printf("Enter size of array: ");
    int n;  scanf("%d",&n);
    printf("Enter elements of array: ");
    for(int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched: ");
    int key; scanf("%d",&key);
    int flag=0;
    int low=0, high=(n-1), mid;
    while(low<=high) 
    {
        mid = (low+high)/2;
        if(key==arr[mid]) 
        {
            printf("Element %d found at index %d",key,mid);
            flag=1;
            break;
        }
        else if(key<arr[mid]) 
            high=mid-1;
        else 
            low=mid+1;
    }
    if(flag==0) 
        printf("Element %d not found.",key);
        
    return 0;
}