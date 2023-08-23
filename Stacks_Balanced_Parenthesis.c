#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// Structure to represent a stack
struct Stack
{
    char data[100];
    int top;
};
// Function to initialize a stack
void initialize(struct Stack* stack)
{
    stack->top=-1;
}
// Function to push an element onto the stack
void push(struct Stack* stack,char item)
{
    stack->top++;
    stack->data[stack->top]=item;
}
// Function to pop an element from the stack
char pop(struct Stack* stack)
{
    char item=stack->data[stack->top];
    stack->top--;
    return item;
}
// Function to check if a character is an opening parenthesis
bool isOpening(char c)
{
    return c=='(' || c=='[' || c=='{';
}
// Function to check if a character is a closing parenthesis
bool isClosing(char c)
{
    return c==')' || c==']' || c=='}';
}
// Function to check if two characters form a balanced pair
bool isBalancedPair(char opening,char closing)
{
    return (opening=='(' && closing==')') ||
           (opening=='[' && closing==']') ||
           (opening=='{' && closing=='}');
}
// Function to check if an expression has balanced parentheses
bool isBalancedExpression(const char* expression)
{
    struct Stack stack;
    initialize(&stack);
    int len=strlen(expression);
    for(int i=0;i<len;i++)
    {
        char current=expression[i];

        if(isOpening(current))
        {
            push(&stack,current);
        }
        else if(isClosing(current))
        {
            if(stack.top==-1 || !isBalancedPair(stack.data[stack.top],current))
            {
                return false;
            }
            pop(&stack);
        }
    }
    return stack.top==-1;  // If the stack is empty, the expression is balanced
}
int main()
{
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s",expression);
    if(isBalancedExpression(expression))
    {
        printf("The expression has balanced parentheses.\n");
    }
    else
    {
        printf("The expression does not have balanced parentheses.\n");
    }
    return 0;
}
