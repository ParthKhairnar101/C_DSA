#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter elements in the array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int k1,k2;
    printf("Enter two key values between which you want to find the sorted values:");
    scanf("%d %d",&k1,&k2);
    int i,j,position,swap;
    for(i=0;i<(n-1);i++) 
    {
       position=i;
       for(j=i+1;j<n;j++) {
          if(arr[position]>arr[j])
            position=j;
       }
       if(position!=i) 
       {
          swap=arr[i];
          arr[i]=arr[position];
          arr[position]=swap;
       }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>k1 && arr[i]<k2)
            printf("%d\t",arr[i]);
    }
    return 0;
}