#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Structure for the stack
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
// Function to create a new stack
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->array=(int*)malloc(stack->capacity*sizeof(int));
    return stack;
}
// Function to check if the stack is empty
int isEmpty(struct Stack* stack)
{
    return stack->top==-1;
}
// Function to push an element onto the stack
void push(struct Stack* stack,int item)
{
    stack->array[++stack->top]=item;
}
// Function to pop an element from the stack
int pop(struct Stack* stack)
{
    if(!isEmpty(stack))
    {
        return stack->array[stack->top--];
    }
    return -1; // Empty stack sentinel value
}
// Function to evaluate a postfix expression
int evaluatePostfix(char* exp)
{
    struct Stack* stack=createStack(strlen(exp));
    if(!stack)
    {
        return -1; // Error in memory allocation
    }
    for(int i=0;exp[i];i++)
    {
        if(isdigit(exp[i]))
        {
            push(stack,exp[i]-'0');
        }
        else
        {
            int operand2=pop(stack);
            int operand1=pop(stack);
            switch (exp[i])
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
    char exp[]="82+3*";
    int result=evaluatePostfix(exp);
    printf("Result: %d\n",result);
    return 0;
}
