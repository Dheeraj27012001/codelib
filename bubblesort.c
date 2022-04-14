#include<stdio.h>
#include<stdlib.h>
void capture(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
    printf("Enter the data: ",i+1);
    scanf("%d",&arr[i]);
    }
}
void display(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("==>%d",arr[i]);
    }
}
void bubblesort(int arr[],int n)
{
    int i,j,tmp,flag;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            int flag=0;
            if(arr[j+1]<arr[j])
            {
                tmp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=tmp;
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
    display(arr,n);
}
int main()
{
    int n;
    int *arr;
    printf("ENTER THE NO OF ELEMENTS: ");
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    capture(arr,n);
    bubblesort(arr,n);
}

