#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Structure to represent a node of the expression tree
struct TreeNode
{
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};
// Structure to represent a stack for expression tree nodes
struct Stack
{
    struct TreeNode* data[100];
    int top;
};
// Function to initialize a stack
void initialize(struct Stack* stack)
{
    stack->top=-1;
}
// Function to push a node onto the stack
void push(struct Stack* stack,struct TreeNode* node)
{
    stack->top++;
    stack->data[stack->top]=node;
}
// Function to pop a node from the stack
struct TreeNode* pop(struct Stack* stack)
{
    struct TreeNode* node=stack->data[stack->top];
    stack->top--;
    return node;
}
// Function to check if a character is an operator
int isOperator(char c)
{
    return c=='+' || c=='-' || c=='*' || c=='/';
}
// Function to build an expression tree from a postfix expression
struct TreeNode* buildExpressionTree(const char* postfix)
{
    struct Stack stack;
    initialize(&stack);
    int len=strlen(postfix);
    for (int i = 0; i < len; i++) {
        if(isalnum(postfix[i]))
        { // Operand (variable or number)
            struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
            node->data=postfix[i];
            node->left=NULL;
            node->right=NULL;
            push(&stack,node);
        }
        else if(isOperator(postfix[i]))
        { // Operator
            struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
            node->data=postfix[i];
            node->right=pop(&stack);
            node->left=pop(&stack);
            push(&stack,node);
        }
    }
    return pop(&stack);
}
// Function to print the expression tree in infix notation
void printExpressionTree(struct TreeNode* root)
{
    if(root!=NULL)
    {
        if(isOperator(root->data))
        {
            printf("(");
            printExpressionTree(root->left);
            printf(" %c ",root->data);
            printExpressionTree(root->right);
            printf(")");
        }
        else
        {
            printf("%c",root->data);
        }
    }
}
int main()
{
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s",postfix);
    struct TreeNode* root=buildExpressionTree(postfix);
    printf("Expression Tree in Infix Notation: ");
    printExpressionTree(root);
    printf("\n");
    return 0;
}
