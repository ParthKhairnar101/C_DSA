#include <stdio.h>
int linearSearch(int arr[],int n,int target)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==target)
        {
            return i; // Element found, return its index
        }
    }
    return -1; // Element not found
}
int main()
{
    int arr[]={2,4,6,8,10,12,14,16};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=10;
    int index=linearSearch(arr,n,target);
    if(index!=-1)
    {
        printf("Element found at index %d\n",index);
    }
    else
    {
        printf("Element not found\n");
    }
    return 0;
}