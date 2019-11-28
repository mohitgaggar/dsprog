/*
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct stack
{
    int data[MAX];
    int top;
}stack;


// stack * push(stack *s,int x)
// {
//     stack * temp =(stack*)malloc(sizeof(stack));
//     temp->data=x;
//     if(s==NULL)
//         s=temp;
//     else
//     {
//         temp->link=s;
//         s=temp;
//     }
//     return s;
    
// }

// int pop(stack *s)
// {
//     if(s!=NULL)
//     {
//         int a =s->data;
//         s=s->link;
//         return a;
//     }
// }

void push(stack *s,int x)
{
    s->top=s->top+1;
    s->data[s->top]=x;
}

int pop(stack *s)
{
    int x;
    x=s->data[s->top];
    s->top=s->top-1;
    return(x);
}


int math(int a,int b,char c)
{
    if(c=='+')
        return (a+b);
    else if(c=='-')
        return (a-b);
    else if(c=='*')
        return (a*b);
    else if(c=='/')
        return (a/b);
    else if(c=='%')
        return (a%b);    
}

int eval(char * postfix)
{
    stack * s=NULL;
    int n1,n2;
    for(int i=0;postfix[i]!='\0';i++)
    {
        if(isdigit(postfix[i]))
        {
            printf("%d",postfix[i]-48);
         push(s,postfix[i]-48);
        }
        else 
        {   
            n1=pop(s);
            n2=pop(s);
            n1=math(n1,n2,postfix[i]);
            push(s,n1);
        }
    }
    return pop(s);
}

void main()
{
    char * s;
    printf("Enter the postfix:");
    scanf("%s",s);
    int sum=eval(s);
    printf("SUm=%d",sum);
}
*/

// POSTFIX EVALUATION

#include<stdio.h>
// #include<conio.h>

#define MAX 20

typedef struct stack
{
    int data[MAX];
    int top;
}stack;

void init(stack *);
int empty(stack *);
int full(stack *);
int pop(stack *);
void push(stack *,int);
int evaluate(char x,int op1,int op2);

void main()
{
    stack s;
    char x;
    int op1,op2,val;
    init(&s);
    printf("Enter the expression (each operand is sigle digit): ");

    while((x=getchar())!='\n')
    {
        if(isdigit(x))
                push(&s,x-48);    //x-48 for removing the effect of ASCII
        else
        {
            op2=pop(&s);
            op1=pop(&s);
            val=evaluate(x,op1,op2);
            push(&s,val);
        }
    }
    val=pop(&s);
    printf("\nValue of expression=%d",val);
}

int evaluate(char x,int op1,int op2)
{
    if(x=='+')
        return(op1+op2);
    if(x=='-')
        return(op1-op2);
    if(x=='*')
        return(op1*op2);
    if(x=='/')
            return(op1/op2);
    if(x=='%')
            return(op1%op2);
}

void init(stack *s)
{
    s->top=-1;
}

int empty(stack *s)
{
    if(s->top==-1)
        return(1);
    return(0);
}

int full(stack *s)
{
    if(s->top==MAX-1)
        return(1);
    return(0);
}

void push(stack *s,int x)
{
    s->top=s->top+1;
    s->data[s->top]=x;
}

int pop(stack *s)
{
    int x;
    x=s->data[s->top];
    s->top=s->top-1;
    return(x);
}



