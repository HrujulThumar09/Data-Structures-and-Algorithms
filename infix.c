#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack
{
    int top;
    char* a;
    int size;
}stack;
stack create_stack(int size)
{
    stack s;
    s.size=size;
    s.top=-1;
    s.a=(char*)malloc(size*sizeof(char));
}
void push(stack* s,char op)
{
    s->top++;
    s->a[s->top]=op;
}
char pop(stack* s)
{
    return s->a[s->top--];
}
char peep(stack* s)
{
    return s->a[s->top];
}
int isEmpty(stack* s)
{
    return s->top==-1;
}
int isOperand(char op)
{
    return (op >= 'a' && op<='z' || op >= 'A' && op <= 'Z');
}
int prec(char op)
{
    switch(op)
    {
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        case '^':return 3;
        return -1;
    }
}
void infixTopostfix(char* exp)
{
    int i,k;
    stack s=create_stack(strlen(exp));
    char exp1[strlen(exp)];
    for(i=0,k=-1;exp[i]!='\n';i++)
    {
        if(isOperand(exp[i]))
            exp1[++k]=exp[i];

        else if(exp[i]=='(')
                push(&s,exp[i]);
        else if(exp[i]==')')
        {
            char gar;
            while(peep(&s)!='(' && !isEmpty(&s))
                    exp1[++k]=pop(&s);
            if(isEmpty(&s) && peep(&s)!= '(')
                gar==pop(&s);
        }
        else
        {
            while(prec(exp[i]) <=prec(peep(&s)) && !isEmpty(&s))
                exp1[++k]=pop(&s);
            push(&s,exp[i]);
        }
    }
    while(!isEmpty(&s))
        exp1[++k]=pop(&s);
    exp[++k]='\n';
    printf("%s",exp1);
}
void main()
{
    char exp[]="a+b*(c^d-e)^(f+g*h)-i";
    infixTopostfix(exp);
}
