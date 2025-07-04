#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} n1;

n1 *head=NULL, *newnode, *temp;
int main()
{
    int a;
    printf("how many node you want to insert: ");
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        // int b;
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
        temp->next=head;
    }
    // insertionatbeg(&head);
    temp = head;
    while (temp->next != head)
    {
        printf("%d", temp->data);
        while (temp->next != NULL)
        {
            printf("->");
            break;
        }
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}
