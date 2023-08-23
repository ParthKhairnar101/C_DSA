#include <stdio.h>
#include <stdlib.h>
int array[100];
int top1=-1;
int top2=100;
void push1(int x)
{
    if(top1<top2-1)
    {
        array[++top1]=x;
    }
    else
    {
        printf("Stack 1 overflow.Cannot push.\n");
    }
}
void push2(int x)
{
    if(top1<top2-1)
    {
        array[--top2]=x;
    }
    else
    {
        printf("Stack 2 overflow.Cannot push.\n");
    }
}
int pop1()
{
    if(top1>=0)
    {
        return array[top1--];
    }
    else
    {
        printf("Stack 1 is empty.Cannot pop.\n");
        return -1;
    }
}
int pop2()
{
    if(top2<100)
    {
        return array[top2++];
    }
    else
    {
        printf("Stack 2 is empty.Cannot pop.\n");
        return -1;
    }
}
void display1()
{
    if(top1>=0)
    {
        printf("Stack 1 elements:\n");
        for(int i=0;i<=top1;i++)
        {
            printf("%d ",array[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Stack 1 is empty.\n");
    }
}
void display2()
{
    if(top2<100)
    {
        printf("Stack 2 elements:\n");
        for(int i=99;i>=top2;i--)
        {
            printf("%d ",array[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Stack 2 is empty.\n");
    }
}
int main()
{
    int choice,item;
    do
    {
        printf("\n***** MENU *****\n");
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Display Stack 1\n");
        printf("6. Display Stack 2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter item to push to Stack 1: ");
                scanf("%d",&item);
                push1(item);
                break;
            case 2:
                printf("Enter item to push to Stack 2: ");
                scanf("%d",&item);
                push2(item);
                break;
            case 3:
                printf("Popped from Stack 1: %d\n",pop1());
                break;
            case 4:
                printf("Popped from Stack 2: %d\n",pop2());
                break;
            case 5:
                display1();
                break;
            case 6:
                display2();
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.Please try again.\n");
        }
    }while(choice!=7);
    return 0;
}