/* =========================================================
7. Delete node from circular doubly linked list
Display before and after deletion
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
    struct node *temp=head;
    if(head==NULL) return;

    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    } while(temp!=head);
}

int main()
{
    struct node *head=NULL,*temp,*newnode;
    int n,i,key;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);

        if(head==NULL)
        {
            head=temp=newnode;
            head->next=head->prev=head;
        }
        else
        {
            newnode->prev=temp;
            newnode->next=head;
            temp->next=newnode;
            head->prev=newnode;
            temp=newnode;
        }
    }

    printf("Before Deletion: ");
    display(head);

    printf("\nEnter value to delete: ");
    scanf("%d",&key);

    temp=head;
    do
    {
        if(temp->data==key)
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;

            if(temp==head)
                head=temp->next;

            free(temp);
            break;
        }
        temp=temp->next;
    } while(temp!=head);

    printf("After Deletion: ");
    display(head);

    return 0;
}