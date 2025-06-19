#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} n1;

n1 *head, *newnode, *temp;

void reversed(n1 **head)
{
    n1 * prev=NULL, *next1,*current;
    next1=current=*head;
    while(next1!=0){
        next1=next1->next;
        current->next=prev;
        prev=current;
        current=next1;
    }
    *head=prev;

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
    reversed(&head);
    temp = head;
    while (temp != NULL)
    {
        printf("the values are : %d\n", temp->data);
        temp = temp->next;
    }
}