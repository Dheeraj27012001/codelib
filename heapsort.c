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
    for(int i=0;i<n;i++)
    {
        printf("==>%d",arr[i]);
    }
}
void Createheaptree(int arr[],int n)
{
    int i,j,tmp;
    for(i=2;i<=n;i++)
    {
        j=i;
        while(j>1 && (arr[j]>arr[j/2]))
        {
            tmp=arr[j/2];
            arr[j/2]=arr[j];
            arr[j]=tmp;
            j=j/2;
        }
    }
}
int heapsort(int arr[],int n)
{
    int i,j,k,tmp;
    Createheaptree(arr,n);
    for(k=n;k>1;k--)
    {
        tmp=arr[1];
        arr[1]=arr[k];
        arr[k]=tmp;
        i=1;
        j=2;
        if(j+1<k)
        {
            if(arr[j]<arr[j+1])
            {
                j++;
            }
        }
        while(j<k && arr[j]>arr[i])
        {
            tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
            i=j;
            j=j*2;
            if(j+1<k)
            {
                if(arr[j+1]>arr[j])
                {
                    j++;
                }
            }
        }
    }
}
int main()
{
    int n;
    int *arr;
    printf("ENTER THE NO OF ELEMENTS: ");
    scanf("%d",&n);
    arr=(int*)malloc((sizeof(int))*n);
    capture(arr,n);
    heapsort(arr,n);
    display(arr,n);
}

