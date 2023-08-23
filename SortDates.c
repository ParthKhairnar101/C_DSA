#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b)
{
    int *dateA=*((int **)a);
    int *dateB=*((int **)b);
    if(dateA[2]!=dateB[2])
    {
        return dateA[2]-dateB[2];
    }
    else if(dateA[1]!=dateB[1])
    {
        return dateA[1]-dateB[1];
    }
    else
    {
        return dateA[0]-dateB[0];
    }
}
void Date_sort(int **arr,int n)
{
    qsort(arr,n,sizeof(int *),compare);
}

int main()
{
    int n;
    printf("Enter the number of dates: ");
    scanf("%d",&n);
    int **arr=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    {
        arr[i]=(int *)malloc(3*sizeof(int));
        printf("Enter date %d (day month year): ",i+1);
        scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
    }
    Date_sort(arr,n);
    printf("Sorted dates:\n");
    for(int i=0;i<n;i++)
    {
        printf("%2d/%2d/%4d\n",arr[i][0],arr[i][1],arr[i][2]);
        free(arr[i]);
    }
    free(arr);
    return 0;
}
