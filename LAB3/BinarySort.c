#include <stdio.h>
#include <stdlib.h>
int count_bits(int n)
{
    int count=0;
    while(n)
    {
        count+=n&1;
        n>>=1;
    }
    return count;
}
int compare(const void *a,const void *b)
{
    int *elemA=*(int **)a;
    int *elemB=*(int **)b;
    int numA=elemA[0];
    int numB=elemB[0];
    int countA=count_bits(numA);
    int countB=count_bits(numB);
    if(countA!=countB)
    {
        return countB-countA;
    }
    else
    {
        return elemA[1]-elemB[1];
    }
}
void Bsort(int arr[],int n)
{
    int **temp=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    {
        temp[i]=(int *)malloc(2*sizeof(int));
        temp[i][0]=arr[i];
        temp[i][1]=i;
    }
    qsort(temp,n,sizeof(int *),compare);
    for(int i=0;i<n;i++)
    {
        arr[i]=temp[i][0];
        free(temp[i]);
    }
    free(temp);
}
int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    Bsort(arr,n);
    printf("Sorted array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }    
    return 0;
}
