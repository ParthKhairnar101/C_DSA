#include <stdio.h>
#include <stdlib.h>
int stack[100];
int top=-1;
int isFull()
{
    return top==99;
}
int isEmpty()
{
    return top==-1;
}
void push(int item)
{
    if(isFull())
    {
        printf("Stack is full.Cannot push.\n");
    }
    else
    {
        stack[++top]=item;
        printf("%d pushed to stack.\n",item);
    }
}
int pop()
{
    if(isEmpty())
    {
        printf("Stack is empty.Cannot pop.\n");
        return -1;
    }
    else
    {
        int item=stack[top--];
        return item;
    }
}
int peek()
{
    if(isEmpty())
    {
        printf("Stack is empty.\n");
        return -1;
    }
    else{
        return stack[top];
    }
}
void display()
{
    if(isEmpty())
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack contents:\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
int main()
{
    int choice,item;
    printf("\n***** MENU *****\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter item to push: ");
                scanf("%d",&item);
                push(item);
                break;
            case 2:
                item=pop();
                if(item!=-1)
                {
                    printf("%d popped from stack.\n",item);
                }
                break;
            case 3:
                item=peek();
                if(item!=-1) 
                {
                    printf("Top item: %d\n",item);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.Please try again.\n");
        }
    }while(choice!=5);
    return 0;
}