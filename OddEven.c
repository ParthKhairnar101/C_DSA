#include<stdio.h>
int main()
{
    int n,p;
    printf("Enter a number:");
    scanf("%d",&n);
    printf("Enter a position(index):");
    scanf("%d",&p);
    int i=0;
    int temp=n;
    while(temp>0)
    {
        int rem=n%10;
        i++;
        temp=temp/10;
    }
    int arr[i];
    while(n>0)
    {
        int rem=n%10;
        arr[i-1]=rem;
        i--;
        n=n/10;
    }
    int x=arr[p-1];
    if(x%2==0)
        printf("Even");
    else
        printf("Odd");
    return 0;
}