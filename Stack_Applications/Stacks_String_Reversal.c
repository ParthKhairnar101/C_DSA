#include <stdio.h>
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
// Function to push a character onto the stack
void push(struct Stack* stack,char item)
{
    stack->top++;
    stack->data[stack->top]=item;
}
// Function to pop a character from the stack
char pop(struct Stack* stack)
{
    char item=stack->data[stack->top];
    stack->top--;
    return item;
}
// Function to reverse a string using a stack
void reverseString(char* str)
{
    int length=strlen(str);
    struct Stack stack;
    initialize(&stack);
    // Push characters onto the stack
    for(int i=0;i<length;i++)
    {
        push(&stack,str[i]);
    }
    // Pop characters from the stack to reverse the string
    for(int i=0;i<length;i++)
    {
        str[i]=pop(&stack);
    }
}
int main()
{
    char input[100];
    printf("Enter a string: ");
    scanf("%s",input);
    reverseString(input);
    printf("Reversed string: %s\n",input);
    return 0;
}
