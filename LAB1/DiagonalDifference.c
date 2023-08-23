
#include<stdio.h>
int main()
{
    int n;
    printf("Enter number of rows/columns in array:");
    scanf("%d",&n);
    int arr[n][n];
    printf("\nEnter elements in the array:");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);    
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d",arr[i][j]);    
        }
        printf("\n");
    }
    int s1=0,s2=0,diff=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                s1=s1+arr[i][j];
            if((i+j)==(n-1))
                s2=s2+arr[i][j];    
        }
    }
    diff=s1-s2;
    if(diff<0)
        diff=-diff;
    printf("Sum across the first diagonal: %d\n",s1);
    printf("Sum across the second diagonal: %d\n",s2);
    printf("Absolute Difference: %d",diff);
    return 0;
}