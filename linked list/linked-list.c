#include<stdio.h>

struct node
{
    int info;
    struct node *next;                  //it is used to point next node so node type pointer is created
};

struct node *ptr;
struct node *head=NULL;
struct node *newptr;

struct node *getnode()
{
    newptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter Data:\t");
    scanf("%d",&newptr->info);
    newptr->next=NULL;
    return newptr;
}

void main()
{
    int ch;
    struct node *last;
    while(1)
    {
        printf("1.Add node\n2.Show node\n3.Exit\nEnter your choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: newptr=getnode();
                    if(head==NULL)
                        head=newptr;
                    else
                        last->next=newptr;
                    last=newptr;
                    break;
            case 2: ptr=head;
                    while(ptr->next!=NULL)
                    {
                        ptr=ptr->next;
                        printf("%d\t",ptr->info);
                    }
                    break;
            case 3: exit(1);
            default: printf("Invalid Input");
        }
    }
}
