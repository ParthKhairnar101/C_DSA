#include <stdio.h>
void topelement(int arr[],int n)
{
    int i,j;
    for (i=0;i<n;i++) 
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]<=arr[j])
                break;
        }
        if(j==n)
            printf("%d ",arr[i]);
    }
}
int main()
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
    topelement(arr,n);
    return 0;
}