#include <stdio.h>
int fsort(int *,int);
void printArray(int *,int);
int main()
{
    int n;
    printf("Enter size of the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int count=fsort(arr,n);
    for(int i=0;i<count;i++)
    {
        for(int j=i+1;j<count;j++)
        {
            if(arr[i]<arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printArray(arr,count);
    return 0;
}
int fsort(int* arr,int n)
{
    int max = -1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    int frequency[max+1];
    for(int i=0;i<=max;i++)
    {
        frequency[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        frequency[arr[i]]++;
    }
    int count=0;
    for(int i=0;i<=max;i++)
    {
        if(frequency[i]>0)
        {
            int value=100000-i;
            arr[count]=100000*frequency[i]+value;
            count++;
        }
    }
    return count;
}
void printArray(int* arr,int count)
{
    for(int i=0;i<count;i++)
    {
        int freq=arr[i]/100000;
        int value=100000-(arr[i]%100000);
        for(int j=0;j<freq;j++)
        {
            printf("%d ",value);
        }
    }
}