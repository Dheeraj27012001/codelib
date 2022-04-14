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
void selectionsort(int arr[],int n)
{
    int i,j,tmp;
    for(i=0;i<n;i++)
    {
        int min=i;
        for(j=i+1;j<n-1;j++)
        {
            if(arr[min]>arr[j])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            tmp=arr[min];
            arr[min]=arr[i];
            arr[i]=tmp;
        }
    }
}
int main()
{
    int n;
    int *arr;
    printf("ENTER THE NO OF ELEMENTS: ");
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    capture(arr,n);
    selectionsort(arr,n);
    display(arr,n);
}

