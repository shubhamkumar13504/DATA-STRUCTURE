#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} n1;

n1 *head, *newnode, *temp;

void deletionatend(n1 **head)
{
    n1 *prev;
    temp=*head;
    while(temp->next!=NULL){
      prev=temp;
      temp=temp->next;  
    }
    prev->next=NULL;
    free(temp);
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
    deletionatend(&head);
    temp = head;
    while (temp != NULL)
    {
        printf("the values are : %d\n", temp->data);
        temp = temp->next;
    }
}