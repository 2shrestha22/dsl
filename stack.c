#include<stdio.h>
#define STACK_SIZE 5

struct stack
{
    int top;
    int data[STACK_SIZE]
};

void push(struct stack *s)
{
    if(s->top==STACK_SIZE-1)
        printf("Stack is full no more data can be added\n");
    else
    {
        printf("Enter the data to be pushed\n");
        scanf("%d",&s->data[++(s->top)]);
    }
}
void pop(struct stack *s)
{
    if(s->top==-1)
        printf("Stack is empty\n");
    else
        printf("%d is popped\n",(s->data[s->top--]));
}
void view(struct stack s)
{
    int i;
    if(s.top==-1)
        printf("Stack is empty\n");
    else
    {
        printf("Data on stack is:\n");
        for(i=s.top;i>=0;i--)
            printf("%d\n",s.data[i]);
    }
}

void main()
{
    struct stack s;
    int choice;
    s.top=-1;
    printf("1.Push value\n2.Pop value\n3.View stack\n4.Exit\n");
    while(1)
    {
        printf("Enter your choice\n");
        scanf("%d",&choice);
    switch(choice)
    {

    case 1:
        push(&s);
        break;
    case 2:
        pop(&s);
        break;
    case 3:
        view(s);
        break;
    case 4:
        exit(0);
    default:
        printf("Wrong Input");
    }
    }
}
