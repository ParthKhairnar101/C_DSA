#include <stdio.h>
#include <stdlib.h>
void countingSort(int arr[],int n)
{
    int max=arr[0],min=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    int range=max-min+1;
    int *count=(int *)calloc(range,sizeof(int));
    int *output=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        count[arr[i]-min]++;
    }
    for(int i=1;i<range;i++)
    {
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        output[count[arr[i]-min]-1]=arr[i];
        count[arr[i]-min]--;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
    free(count);
    free(output);
}
int main()
{
    int arr[]={4,2,2,8,3,3,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    countingSort(arr,n);
    printf("Sorted array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
