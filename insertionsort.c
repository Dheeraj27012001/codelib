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
void insertionsort(int arr[],int n)
{
    int i,j,ins,temp;
    for(i=1;i<n;i++)
    {
        j=i-1;
        ins=arr[i];
        while(j>=0 && ins<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=ins;
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
    insertionsort(arr,n);
    display(arr,n);
}

