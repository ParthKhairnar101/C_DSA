#include <stdio.h>
#define n 100
int stack[n];
int top=-1;
int odd[n];
int even[n];
int o=0,e=0;
int isEmpty()
{
    return top==-1;
}
int isFull()
{
    return top==n-1;
}
void push(int item)
{
    if(!isFull())
    {
        stack[++top]=item;
    }
    else
    {
        printf("Stack is full. Cannot push.\n");
    }
}
void pop()
{
    if(!isEmpty())
    {
        if(stack[top]%2!=0)
        {
            odd[o]=stack[top];
            o++;
        }
        else
        {
            even[e]=stack[top];
            e++;
        }
        top--;
    }
    else
        printf("Stack is empty. Cannot Pop.\n");
}    
void display()
{
    for(int i=0;i<=top;i++)
    {
        printf("%d\n",stack[i]);
    }
    if(o==0)
    {
        printf("-1\n");
    }
    else
    {
        for(int i=0;i<o;i++)
        {
            printf("%d\n",odd[i]);
        }
    }
    if(e==0)
    {
        printf("-99\n");
    }
    else
    {
        for(int i=0;i<e;i++)
        {
            printf("%d\n",even[i]);
        }
    }
}
int main()
{
    while(true)
    {
        int choice;
        scanf("%d",&choice);
        if(choice==1)
        {
            int no;
            scanf("%d",&no);
            for(int i=0;i<no;i++)
            {
                int num;
                scanf("%d",&num);
                push(num);
            }
        }
        else if(choice==2)
        { 
            int no;
            scanf("%d",&no);
            if(n>no)
            {
                for(int i=0;i<no;i++)
                {
                    pop();
                }
            }
        }
        scanf("%d",&choice);
        if(choice==1)
            continue;
        else
            break;
    }
    display();
    return 0;
}