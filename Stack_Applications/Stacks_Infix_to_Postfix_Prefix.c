#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Stack
{
    int top;
    unsigned capacity;
    char* array;
};
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->array=(char*)malloc(stack->capacity*sizeof(char));
    return stack;
}
int isEmpty(struct Stack* stack)
{
    return stack->top==-1;
}
char peek(struct Stack* stack)
{
    if(!isEmpty(stack))
    {
        return stack->array[stack->top];
    }
    return '\0'; // Empty stack sentinel value
}
void push(struct Stack* stack,char item)
{
    stack->array[++stack->top]=item;
}
char pop(struct Stack* stack)
{
    if(!isEmpty(stack))
    {
        return stack->array[stack->top--];
    }
    return '\0'; // Empty stack sentinel value
}
int isOperator(char c)
{
    return c=='+' || c=='-' || c=='*' || c=='/';
}
int precedence(char c)
{
    if(c=='*' || c=='/')
        return 2;
    if(c=='+' || c=='-')
        return 1;
    return 0;
}
void infixToPostfix(char* infix,char* postfix)
{
    struct Stack* stack=createStack(strlen(infix));
    int i,j;
    for(i=0,j=0;infix[i];i++)
    {
        if(isalnum(infix[i]))
        {
            postfix[j++]=infix[i];
        }
        else if(infix[i]=='(')
        {
            push(stack,infix[i]);
        }
        else if(infix[i]==')')
        {
            while(!isEmpty(stack) && peek(stack)!='(')
            {
                postfix[j++]=pop(stack);
            }
            pop(stack); // Pop the '('
        }
        else
        {
            while(!isEmpty(stack) && precedence(peek(stack))>=precedence(infix[i]))
            {
                postfix[j++]=pop(stack);
            }
            push(stack,infix[i]);
        }
    }
    while(!isEmpty(stack))
    {
        postfix[j++]=pop(stack);
    }
    postfix[j]='\0';
    free(stack);
}
void reverseString(char* str)
{
    int length=strlen(str);
    for(int i=0,j=length-1;i<j;i++,j--)
    {
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
}
void infixToPrefix(char* infix,char* prefix)
{
    // Reverse the infix expression
    reverseString(infix);
    // Replace '(' with ')' and vice versa
    for(int i=0;infix[i];i++)
    {
        if(infix[i]=='(')
            infix[i]=')';
        else if(infix[i]==')')
            infix[i]='(';
    }
    // Convert the reversed infix to postfix
    char postfix[strlen(infix) + 1];
    infixToPostfix(infix, postfix);
    // Reverse the postfix expression to get the prefix
    reverseString(postfix);
    strcpy(prefix,postfix);
}
int main()
{
    char infix[]="a+b*(c-d/e)";
    char postfix[100],prefix[100];
    infixToPostfix(infix,postfix);
    infixToPrefix(infix,prefix);
    printf("Infix Expression: %s\n",infix);
    printf("Postfix Expression: %s\n",postfix);
    printf("Prefix Expression: %s\n",prefix);

    return 0;
}
