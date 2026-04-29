/* =========================================================
6. Insert node at beginning, middle, end in doubly linked list
========================================================= */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev,*next;
};

void display(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}

int main()
{
    struct node *head=NULL,*temp,*newnode;
    int n,i,pos,val;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->prev=newnode->next=NULL;

        if(head==NULL)
            head=temp=newnode;
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }

    printf("Original List: ");
    display(head);

    /* Beginning */
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter value for beginning: ");
    scanf("%d",&newnode->data);

    newnode->prev=NULL;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;

    /* Middle */
    printf("Enter position for middle insert: ");
    scanf("%d",&pos);

    printf("Enter value: ");
    scanf("%d",&val);

    temp=head;
    for(i=1;i<pos-1;i++)
        temp=temp->next;

    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;

    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;

    /* End */
    printf("Enter value for end: ");
    scanf("%d",&val);

    while(temp->next!=NULL)
        temp=temp->next;

    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    newnode->prev=temp;
    temp->next=newnode;

    printf("Updated List: ");
    display(head);

    return 0;
}