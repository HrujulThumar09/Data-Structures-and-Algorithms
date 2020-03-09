#include<stdio.h>
char a[15][15],top=-1;
void push(int x)
{
    top++;
    [top]=x;
}
void main()
{
    char input[15];
    printf("Enter Postfix operator");
    scanf("%s",input);
    int i=0;
    while(input[i]!='\n')
    {
        if(input[i].isalpha())
        {
            push(input[i]);
        }
        else
        {
            int op2=pop();
            int op1=pop();
            switch(input[i])
            {
                case '+':push(op1+op2);
                case '-':push(op1-op2);
                case '*':push(op1*op2);
                case '/':push(op1/op2);
            }
        }
        i++
    }
}
