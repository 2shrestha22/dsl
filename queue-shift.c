/*queue with shifting
*/
#include<stdio.h>
#define qsize 5
struct queue
{
    int rear,front;
    int data[qsize];
};

void insert(struct queue *s)
{
    if(s->rear==qsize-1)
        printf("\t\t\tQueue is full\n");
    else
    {
        printf("Enter the data to be inserted in the queue:\t");
        scanf("%d",&s->data[++s->rear]);
    }
}
void Delete(struct queue *s)
{
    int i;
    if(s->rear<s->front)
        printf("\t\t\tQueue is empty\n");
    else
    {
        printf("\t\t\t%d is deleted from queue\n",s->data[s->front]);
        for(i=s->front;i<s->rear;i++)
        {
            s->data[i]=s->data[i+1];
        }
        s->rear--;
    }
}
void main()
{
    struct queue q;
    q.rear=-1;
    q.front=0;
    int choice;
    while(1)
    {
        printf("Enter your choice:\n");
        printf("1. Insert data\n2. Delete data\n3. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert(&q);
            break;
            case 2:Delete(&q);
            break;
            case 3:exit(1);
            default: printf("\t\t\t\tWrong Input\n");
        }
    }
}
