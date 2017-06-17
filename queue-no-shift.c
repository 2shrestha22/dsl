/*queue without shifting
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
        printf("Queue is full\n");
    else
    {
        printf("Enter the data to be inserted in the queue:\t");
        scanf("%d",&s->data[++s->rear]);
    }
}
void Delete(struct queue *s)
{
    if(s->rear<s->front)
        printf("Queue is empty\n");
    else
    {
        printf("%d is deleted from queue\n",s->data[s->front++]);
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
        printf("1. Insert data\n2. Delete data\n3. Exit\n");
        printf("Enter your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert(&q);
            break;
            case 2:Delete(&q);
            break;
            case 3:exit(1);
            default: printf("Wrong Input");
        }
    }
}
