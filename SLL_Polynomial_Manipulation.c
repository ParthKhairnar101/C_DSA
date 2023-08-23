#include <stdio.h>
#include <stdlib.h>
// Structure to represent a term in a polynomial
struct Term
{
    int coefficient;
    int exponent;
    struct Term* next;
};
// Function to create a new term
struct Term* createTerm(int coefficient,int exponent)
{
    struct Term* term=(struct Term*)malloc(sizeof(struct Term));
    term->coefficient=coefficient;
    term->exponent=exponent;
    term->next=NULL;
    return term;
}
// Function to add a term to a polynomial
void addTerm(struct Term** polynomial,int coefficient,int exponent)
{
    struct Term* newTerm=createTerm(coefficient,exponent);
    if(*polynomial==NULL)
    {
        *polynomial=newTerm;
        return;
    }
    struct Term* current=*polynomial;
    while(current->next!=NULL) {
        current=current->next;
    }
    current->next=newTerm;
}
// Function to print a polynomial
void printPolynomial(struct Term* polynomial)
{
    if(polynomial==NULL)
    {
        printf("0\n");
        return;
    }
    struct Term* current=polynomial;
    while(current!=NULL)
    {
        printf("%dx^%d",current->coefficient,current->exponent);
        current=current->next;
        if(current!=NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}
// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1,struct Term* poly2)
{
    struct Term* result=NULL;
    struct Term* current1=poly1;
    struct Term* current2=poly2;
    while(current1!=NULL && current2!=NULL)
    {
        if(current1->exponent>current2->exponent)
        {
            addTerm(&result,current1->coefficient,current1->exponent);
            current1=current1->next;
        }
        else if(current1->exponent<current2->exponent)
        {
            addTerm(&result,current2->coefficient,current2->exponent);
            current2=current2->next;
        }
        else
        {
            addTerm(&result,current1->coefficient+current2->coefficient,current1->exponent);
            current1=current1->next;
            current2=current2->next;
        }
    }
    while(current1!=NULL)
    {
        addTerm(&result,current1->coefficient,current1->exponent);
        current1=current1->next;
    }
    while(current2!=NULL)
    {
        addTerm(&result,current2->coefficient,current2->exponent);
        current2=current2->next;
    }
    return result;
}
int main()
{
    struct Term* poly1=NULL;
    struct Term* poly2=NULL;
    // Creating and adding terms to the first polynomial: 3x^2 + 4x + 2
    addTerm(&poly1,3,2);
    addTerm(&poly1,4,1);
    addTerm(&poly1,2,0);
    // Creating and adding terms to the second polynomial: 5x^3 + 2x^2 - 7
    addTerm(&poly2,5,3);
    addTerm(&poly2,2,2);
    addTerm(&poly2,-7,0);
    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);
    struct Term* result=addPolynomials(poly1,poly2);
    printf("Sum of Polynomials: ");
    printPolynomial(result);
    // Free memory
    while(poly1!=NULL)
    {
        struct Term* temp=poly1;
        poly1=poly1->next;
        free(temp);
    }
    while(poly2!=NULL)
    {
        struct Term* temp=poly2;
        poly2=poly2->next;
        free(temp);
    }
    while(result!=NULL)
    {
        struct Term* temp=result;
        result=result->next;
        free(temp);
    }
    return 0;
}
