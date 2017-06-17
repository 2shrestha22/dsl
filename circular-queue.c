/*implementation of circular queue


#include<stdio.h>
#define qsize 3
struct queue
{
    int front,rear;
    int data[qsize];
};

int isEmpty(struct queue *q)
{
    if(q->front==q->rear)
        return 1;
    else
        return 0;
}
int isFull(struct queue *q)
{
    if(q->front==(q->rear+1)%qsize)
        return 1;
    else
        return 0;
}
void addToQ(struct queue *q)
{
    if(isFull(&q))
        printf("Queue is full/n");
    else
    {
        printf("Enter the data to add:\t");
        q->rear=(q->rear+1)%qsize;
        scanf("%d",&q->data[q->rear]);
    }
}
void deleteFromQ(struct queue *q)
{
    if(isEmpty(&q))
        printf("Queue is empty/n");
    else
    {
        printf("%d is deleted from the queue\n",q->data[q->front]);
        q->front++;
    }
}

void main()
{
    struct queue Q;
    Q.front=0;
    Q.rear=-1;
    int choice=4;
    while(1)
    {
        printf("1. Add data to queue\n2. Delete data from queue\n3. Exit\n\nEnter your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: addToQ(&Q);
            break;
            case 2: deleteFromQ(&Q);
            break;
            case 3: exit(1);
            default: printf("Wring input\t");
        }
    }
}*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#define qsize 6
struct queue
{
    int front,rear;
    int data[qsize];
};

void addToQ(struct queue *q)
{
    if(q->front==(q->rear+1)%qsize)
        printf("\t\t\tQueue is full\n");
    else
    {
        printf("Enter the data to add:\t");
        q->rear=(q->rear+1)%qsize;
        scanf("%d",&q->data[q->rear]);
    }
}
void deleteFromQ(struct queue *q)
{
    if(q->front==q->rear)
        printf("\t\t\tQueue is empty\n");
    else
    {
        q->front=(q->front+1)%qsize;
        printf("%d is deleted from the queue\n",q->data[q->front]);
    }
}
void display(struct queue q)
{
    int i=q.front+1;
    printf("\n\t\t\tThe queue is:\n");
    do
    {
        printf("\t\t\t%d\n",q.data[i]);
        i=(i+1)%qsize;
    }
    while(i!=q.rear);
}

void main()
{
    struct queue Q;
    Q.front=0;
    Q.rear=0;
    int choice=4;
    while(1)
    {
        printf("##############################################\n##############################################\n1. Add data to queue\n2. Delete data from queue\n3. Display queue\n4. Exit\n\nEnter your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: addToQ(&Q);
            break;
            case 2: deleteFromQ(&Q);
            break;
            case 3: display(Q);
            break;
            case 4: exit(1);
            default: printf("Wring input\t");
        }
    }
}
