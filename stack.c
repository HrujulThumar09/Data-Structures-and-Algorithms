#include<stdio.h>
typedef struct stack
{
    int size;
    int *a;
    int top;
}stack;
stack create_stack(int maxsize)
{
    stack new_stack;
    new_stack.size=maxsize;
    new_stack.top=-1;
    new_stack.a=(int*)malloc(maxsize*sizeof(int));
    return new_stack;
}
void push(stack* s)
{
    if(s->top==(s->size-1))
    {
        printf("Stack overflow\n\n");
        return;
    }
    int y;
    printf("Enter number to push: ");
    scanf("%d",&y);
    s->top++;
    s->a[s->top]=y;
    return;
}
void pop(stack* s)
{
    if(s->top=-1)
    {
        printf("Stack underflow\n\n");
        return;
    }
    s->top--;
    return;
}
void peep(stack* s)
{
    int pos;
    printf("Enter position to peek: ");
    scanf("%d",&pos);
    if((s->top-pos)<0)
    {
        printf("Stack underflow\n\n");
        return;
    }
    printf("Top element of stack is %d\n",s->a[s->top-pos]);
}
void change(stack* s)
{
    int pos,val;
    printf("Enter positon to change: ");
    scanf("%d",&pos);
    if((s->top-pos)<0)
    {
        printf("Stack underflow\n\n");
        return;
    }
    printf("Enter new value: ");
    scanf("%d",&val);
    s->a[s->top-pos]=val;
}
void main()
{
     stack s=create_stack(10);
     int op;
    do
    {
        printf("Enter operation\n0 for push\n1 for pop \n2 for peep\n 3 for change\n4 for exit\n: ");
        scanf("%d",&op);
        switch(op)
        {
            case 0:push(&s);break;
            case 1:pop(&s);break;
            case 2:peep(&s);break;
            case 3:change(&s);break;
        }
    }while(op!=4);

}
