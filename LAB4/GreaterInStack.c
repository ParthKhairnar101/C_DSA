#include <stdio.h>
#include <stdlib.h>
int stack[100];
int top=-1;
void push(int item)
{
    stack[++top]=item;
}
int pop()
{
    return stack[top--];
}
void printNextGreater(int arr[],int n)
{
    push(arr[0]);
    for(int i=1;i<n;i++)
    {
        while(top!=-1 && arr[i]>stack[top])
        {
            printf("%d -> %d\n",stack[top],arr[i]);
            pop();
        }
        push(arr[i]);
    }
    while(top!=-1)
    {
        printf("%d -> -1\n",stack[top]);
        pop();
    }
}
int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Next greater elements:\n");
    printNextGreater(arr,n);
    return 0;
}