#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->array=(int*)malloc(stack->capacity*sizeof(int));
    return stack;
}
int isEmpty(struct Stack* stack)
{
    return stack->top==-1;
}
void push(struct Stack* stack,int item)
{
    stack->array[++stack->top]=item;
}
int pop(struct Stack* stack)
{
    if (!isEmpty(stack)) 
    {
        return stack->array[stack->top--];
    }
    return -1; // Empty stack sentinel value
}
int evaluatePrefix(char* exp)
{
    struct Stack* stack=createStack(strlen(exp));
    if(!stack)
    {
        return -1; // Error in memory allocation
    }
    int length=strlen(exp);
    for(int i=length-1;i>=0;i--)
    {
        if(isdigit(exp[i]))
        {
            push(stack,exp[i]-'0');
        }
        else
        {
            int operand1=pop(stack);
            int operand2=pop(stack);
            switch(exp[i])
            {
                case '+':
                    push(stack,operand1+operand2);
                    break;
                case '-':
                    push(stack,operand1-operand2);
                    break;
                case '*':
                    push(stack,operand1*operand2);
                    break;
                case '/':
                    push(stack,operand1/operand2);
                    break;
            }
        }
    }
    int result=pop(stack);
    free(stack);
    return result;
}
int main()
{
    char exp[]="*+823";
    int result=evaluatePrefix(exp);
    printf("Result: %d\n",result);
    return 0;
}
