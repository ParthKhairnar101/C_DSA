#include <stdio.h>
int binarySearch(int arr[],int fn,int ln,int x)
{
    while(fn<=ln){
        int mid=fn+(ln-fn)/2;
        if (arr[mid]==x)
            return mid;
        if (arr[mid]<x)
            fn=mid+1;
        else
            ln=mid-1;
    }
    return -1;
}
int main(void)
{
    int n;
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter elements in the array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int x;
    printf("Enter number to be searched:");
    scanf("%d",&x);
    int pos,swap;
    for(int i=0;i<(n-1);i++) 
    {
       pos=i;
       for(int j=i+1;j<n;j++) 
       {
          if(arr[pos]>arr[j])
            pos=j;
       }
       if(pos!=i) 
       {
          swap=arr[i];
          arr[i]=arr[pos];
          arr[pos]=swap;
       }
    }
    int result = binarySearch(arr,0,n-1,x);
    if(result==-1)
        printf("Element is not present in array");
    else
        printf("Element is present at position %d",(result+1));
    return 0;
}