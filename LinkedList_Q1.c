#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* mergeSortedLists(struct Node* list1,struct Node* list2)
{
    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;
    struct Node* mergedList=NULL;
    if(list1->data<=list2->data)
    {
        mergedList=list1;
        mergedList->next=mergeSortedLists(list1->next,list2);
    }
    else
    {
        mergedList=list2;
        mergedList->next=mergeSortedLists(list1,list2->next);
    }
    return mergedList;
}
void insert(struct Node** head,int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=*head;
    *head=newNode;
}
void printList(struct Node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
int main()
{
    struct Node* list1=NULL;
    insert(&list1,9);
    insert(&list1,7);
    insert(&list1,5);
    struct Node* list2=NULL;
    insert(&list2,8);
    insert(&list2,6);
    insert(&list2,4);
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);
    struct Node* mergedList=mergeSortedLists(list1,list2);
    printf("Merged List: ");
    printList(mergedList);
    return 0;
}