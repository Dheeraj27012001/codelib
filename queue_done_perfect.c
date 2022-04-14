#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 10
int front=-1;
int rear=-1;
void push(int arr[]);
int full();
void pop(int arr[]);
int empty();
void display(int arr[]);
int main()
{
    int arr[STACKSIZE];
    int ch;
    do
    {
        printf("--------------------------\n");
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push(arr);
            break;
            case 2:pop(arr);
            break;
            case 3:display(arr);
            break;
            case 4:printf("program terminating\n");
            break;
        }
    }while(ch!=4);
}
void push(int arr[])
{
    if(full())
    {
        printf("|QUEUE IS FULL|\n");
    }
    else
    {
        int data;
        printf("Enter the data: ");
        scanf("%d",&data);
        if(front==-1)
        {
            front=0;
        }
        rear=rear+1;
        arr[rear]=data;
    }
}
int full()
{
    return(rear==STACKSIZE-1);
}
void pop(int arr[])
{
    if(empty())
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
        int data;
        data=arr[front];
        front++;
        printf("Deleted data: %d\n",data);
    }
}
int empty()
{
    return(rear==-1 || front>rear);
}
void display(int arr[])
{
    if(empty())
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("|%d|\n",arr[i]);
        }
    }
}
