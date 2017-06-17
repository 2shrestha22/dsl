#include<stdio.h>
#define bool int
#define size 20

struct stack
{
    char data[size];
    int top;
};

bool isEmpty(struct stack *p)
{
    if(p->top==-1)
        return 1;
    else
        return 0;
}
bool isFull(struct stack *p)
{
    if(p->top==size-1)
        return 1;
    else
        return 0;
}

void main()
{
    struct stack S;
    S.top=-1;
    char exp[20];
    printf("Enter Parentheses:\t");
    gets(exp);
    int i;
    int length=strlen(exp);
    for(i=0;i<length;i++)
    {
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
            {
                if(isFull(&S))
                    printf("Stack is Full");           //when more than 20 parenthesis are stored.
                else
                    S.data[++S.top]=exp[i];
            }
        if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
            {
                    if(isEmpty(&S))
                    {
                        printf("Invalid Expression\t");
                        exit(0);
                    }
                    else
                    {
                        if(S.data[S.top]=='('&&exp[i]==')'||S.data[S.top]=='{'&&exp[i]=='}'||S.data[S.top]=='['&&exp[i]==']')// error xa..
                            S.top--;
                        else
                        {
                            printf("Invalid Expression\n");
                            exit(0);
                        }
                    }
            }
    }
    if(isEmpty(&S))
        printf("Valid Expression\t");
    else printf("Invalid Expression\t");

}
