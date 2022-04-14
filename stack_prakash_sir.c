#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define STACKSIZE 10
struct stack_CHINTU
{
    int top;
    char colour[STACKSIZE];
};
typedef struct stack_CHINTU STACK;

int main()
{
 STACK s;
 s.top=-1;
 int choice;
 while(1)
 {
     printf("\nMENU\n");
     printf("1-push\n2-pop\n3-peek\n4-print\n5-exit\n");
     printf("enter the choice\n");
     scanf("%d",&choice);

     switch(choice)
     {
         case 1:push(&s);
                break;
         case 2:pop(&s);
                break;
         case 3:peek(&s);
                break;
         case 4:print(&s);
                break;
         case 5:printf("program terminating");
                break;
     }
 }
}

void push(STACK *s)
{
    if(full(s))
    {
        printf("stack is full\n");
    }
    char x;
    printf("enter color to be pushed\n");
    scanf("%s",x);
    s->top++;
    s->colour[s->top]=x;
    printf("insertion successful");
}

int full(STACK *s)
{
    if(s->top==STACKSIZE-1)
        return TRUE;
    else
        return FALSE;
}

void pop(STACK *s)
{
    if(empty(s))
    {
        printf("the stack is empty\n");
    }
    char x;
    x=s->colour[s->top];
    s->top--;
    printf("popped colour is %s",x);
}

int empty(STACK *s)
{
    if(s->top==-1)
        return TRUE;
    else
        return FALSE;
}

void peek(STACK *s)
{
   if(empty(s))
    {
        printf("the stack is empty\n");
    }
    char x;
    x=s->colour[s->top];
    printf("the visible color is %s",x);
}

void print(STACK *s)
{
     if(empty(s))
    {
        printf("the stack is empty\n");
    }
    int i;
    for(i=s->top;i>=0;i--)
    {
        printf("|%s|",s->colour[i]);
    }
}

