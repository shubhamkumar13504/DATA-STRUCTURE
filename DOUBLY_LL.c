#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int d;
    struct node *next;
    struct node *prev;

} n;
n *head = NULL, *new, *temp;

void create()
{
    int a;
    printf("how many node you want to insert: ");
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        new = (n *)malloc(sizeof(n));
        printf("enter data : ");
        scanf("%d", &new->d);
        new->next = NULL;
        new->prev = NULL;
        if (head == 0)
        {
            head = temp = new;
        }
        else
        {
            temp->next = new;
            new->prev = temp;
            temp = new;
        }
    }
}
void print()
{
    n *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->d);
        while (temp->next != NULL)
        {
            printf("->");
            break;
        }
        temp = temp->next;
    }
}
void insertbeg()
{
    new = (n *)malloc(sizeof(n));
    printf("enter data to insert at beg : ");
    scanf("%d", &new->d);
    new->next=NULL;
    new->prev=NULL;
    new->next=head;
    head->prev=new;
    
    head=new;

}
void insertend()
{
    new = (n *)malloc(sizeof(n));
    printf("enter data to insert at end : ");
    scanf("%d", &new->d);
    new->next=NULL;
    new->prev=NULL;
    temp->next=new;
    new->prev=temp;
    temp=new;
}
int main()
{
    create();
    // insertbeg();
    insertend();
    print();
}