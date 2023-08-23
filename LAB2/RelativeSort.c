#include <stdio.h>
void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubbleSort(int* A1,int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(A1[j]>A1[j+1])
            {
                swap(&A1[j],&A1[j+1]);
            }
        }
    }
}
int findIndex(int* A2,int n,int num)
{
    for(int i=0;i<n;i++)
    {
        if(A2[i]==num)
        {
            return i;
        }
    }
    return -1;
}
void relative_Sort(int* A1,int n1,int* A2,int n2)
{
    bubbleSort(A1,n1);
    int sortedIndex=0;
    for(int i=0;i<n2;i++)
    {
        int index=findIndex(A1,n1,A2[i]);
        if(index!=-1)
        {
            swap(&A1[index],&A1[sortedIndex]);
            sortedIndex++;
        }
    }
    bubbleSort(&A1[sortedIndex],n1-sortedIndex);
}
int main()
{
    int n1,n2;
    printf("Enter size of the first array (A1): ");
    scanf("%d",&n1);
    int A1[n1];
    printf("Enter elements of the first array (A1): ");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&A1[i]);
    }
    printf("Enter size of the second array (A2): ");
    scanf("%d",&n2);
    int A2[n2];
    printf("Enter elements of the second array (A2): ");
    for(int i=0;i<n2;i++)
    {
        scanf("%d",&A2[i]);
    }
    relative_Sort(A1,n1,A2,n2);
    printf("Resulting sorted array (A1): ");
    for(int i=0;i<n1;i++)
    {
        printf("%d ",A1[i]);
    }
    return 0;
}
