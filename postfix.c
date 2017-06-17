#include<stdio.h>
#define size 20
#include<string.h>

struct stack
{
    int top;
    float data[size]
};

void push(struct stack *s,double num)
{
    s->data[++(s->top)]=num;
}

double pop(struct stack *s)
{
    return(s->data[(s->top--)]);
}

int isDigit(char sym)
{
    if(sym>'9'||sym<'0')        //48 to 57, sym>57||sym<48 can be used also
        return 0;
    else
        return 1;
}
double calculate(char sym,double opnd1,double opnd2)
{
    switch(sym)
    {
        case '+': return(opnd1+opnd2);
        case '-': return(opnd1-opnd2);
        case '*': return(opnd1*opnd2);
        case '/': return(opnd1/opnd2);
        default : printf("Invalid Operator:\n");
    }
}


void main()
{
    struct stack S;
    char exp[size];
    int i;
    double opnd1,opnd2,value;
    S.top=-1;
    printf("Enter Postfix Expression:\t");
    gets(exp);
    for(i=0;exp[i]!='\0';i++)
    {
        if(isDigit(exp[i]))
        {
            push(&S,(double)(exp[i]-'0'));
        }
        else
        {
            opnd2=pop(&S);
            opnd1=pop(&S);
            value=calculate(exp[i],opnd1,opnd2);
            push(&S,value);
        }
    }
    printf("Result is: %f",pop(&S));
}

