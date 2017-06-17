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
    if(sym>57||sym<48)        //48 to 57, sym>'9'||sym<'0' can be used also.
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
    printf("Enter Prefix Expression:\t");
    gets(exp);
    int l=strlen(exp);
    for(i=l-1;i>=0;i--)                             //starting from last of the expression
    {
        if(isDigit(exp[i]))
        {
            push(&S,(double)(exp[i]-'0'));          //converts the character digit to numeric digit.
        }
        else
        {
            opnd1=pop(&S);                          //since we start from last the first popped digit is operand1,
            opnd2=pop(&S);                          //so that <operand2><operator><operand1> is valid
            value=calculate(exp[i],opnd1,opnd2);
            push(&S,value);
        }
    }
    printf("Result is: %f",pop(&S));
}


