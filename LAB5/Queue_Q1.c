#include <stdio.h>
#define n 100
int queue[n];
int f=-1,r=-1;
int odd[n];
int even[n];
int o=0,e=0;
int isEmpty()
{
    return f==-1 && r==-1;
}
int isFull()
{
    return (r+1)%n==f;
}
void enqueue(int item)
{
    if(!isFull())
    {
        if(f==-1)
        {
            f=0;
        }
        r=(r+1)%n;
        queue[r]=item;
    }
    else
    {
        printf("Queue is full. Cannot enqueue.\n");
    }
}
void dequeue()
{
    if(!isEmpty())
    {
        int removed=queue[f];
        if(removed%2!=0)
        {
            odd[o]=removed;
            o++;
        }
        else
        {
            even[e]=removed;
            e++;
        }
        if(f==r)
        {
            f=-1;
            r=-1;
        }
        else
        {
            f=(f+1)%n;
        }
    }
    else
    {
        printf("Queue is empty. Cannot dequeue.\n");
    }
}
void display()
{
    for(int i=f;i<=r;i=(i+1)%n)
    {
        printf("%d\n", queue[i]);
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
                enqueue(num);
            }
        } 
        else if(choice==2)
        {
            int no;
            scanf("%d",&no);
            if((r+1-f+n)%n>=no)
            {
                for(int i=0;i<no;i++)
                {
                    dequeue();
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
