#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} n1;

n1 *head, *newnode, *temp;

void insertionatend(n1 **head)
{
    temp=*head;
    newnode = (n1 *)malloc(sizeof(n1));
    printf("enter values to insert at end: ");
    scanf("%d", &newnode->data);
    newnode->next=NULL;
    while(temp->next!= NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
int main()
{
    head = 0;
    int a;
    printf("how many node you want to insert: ");
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        int b;
        newnode = (n1 *)malloc(sizeof(n1));
        printf("enter values : ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    insertionatend(&head);
    temp = head;
    while (temp != NULL)
    {
        printf("the values are : %d\n", temp->data);
        temp = temp->next;
    }
}