#include<stdio.h>
#include<stdlib.h>
void capture(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
    printf("Enter the data %d: ",i+1);
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
int mergesort(int arr[],int L,int R)
{
    int M;
    if(L<R)
    {
        M=(L+R)/2;
        mergesort(arr,L,M);
        mergesort(arr,M+1,R);
        mergepast(arr,L,M,M+1,R);
    }
}
int mergepast(int arr[],int s1,int e1,int s2,int e2)
{
    int i,j,k;
    int *tmp=(int*)malloc(sizeof(int)*(e2-s1+1));
    for(i=s1,j=s2,k=0;i<=e1 || j<=e2;k++)
    {
        if((i<=e1 && j<=e2 && arr[i]<arr[j]) || (j>e2))
        {
            tmp[k]=arr[i++];
        }
        else
        {
            tmp[k]=arr[j++];
        }
    }
    for(i=s1,k=0;i<=e2;i++,k++)
    {
        arr[i]=tmp[k];
    }
    free(tmp);
}
int main()
{
    int *arr,n;
    printf("Enter the no of terms: ");
    scanf("%d",&n);
    arr=(int*)malloc((sizeof(int))*n);
    capture(arr,n);
    mergesort(arr,0,n-1);
    display(arr,n);
}
