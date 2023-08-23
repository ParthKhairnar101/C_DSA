#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter elements in the array:");\
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int element,position,i;
    printf("Enter position and element\n");
    scanf("%d%d",&position,&element);
    if(position<=n && position>=0)
    {
        for(i=n;i>position;i--)
            arr[i]=arr[i-1];
        arr[position]=element;
        for(i=0;i<=n;i++)
            printf("%d ", arr[i]);
    }
    else
        printf("Invalid Position\n");

    return 0;
  }
