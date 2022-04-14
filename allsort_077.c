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

void bubblesort(int arr[],int n)
{
    int i,j,tmp,flag;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
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
}
void selectionsort(int arr[],int n)
{
    int i,j,tmp;
    for(i=0;i<n-1;i++)
    {
        int min=i;
        for(j=i+1;j<n;j++)
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
int quicksort1(int arr[],int L,int R)
{
    int i,j,tmp,tmp1;
    i=L+1;
    j=R;
    int p=arr[L];
    while(j>=i)
    {
        while(i<=R && arr[i] < p)
        {
            i++;
        }
        while(j>L && arr[j] > p)
        {
            j--;
        }
        if(j>i)
        {
            tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
        }
    }
    if(L!=j)
    {
        tmp1=arr[L];
        arr[L]=arr[j];
        arr[j]=tmp1;
    }
    return (j);
}
void quicksort(int *arr,int L,int R)
{
    int j;
    if(L<R)
    {
        j=quicksort1(arr,L,R);
        quicksort(&arr,L,j-1);
        quicksort(&arr,j+1,R);
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
            i=j;
            j=j*2;
            if(j+1<k)
            {
                if(arr[j+1]>arr[j])
            tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
                {
                    j++;
                }
            }
        }
    }
}
int main()
{
    int *arr,n,ch;
    n=10;
    arr=(int*)malloc((sizeof(int))*n);
    while(1)
    {
    printf("\nAlgorithms Available\n1.BubbleSort\n2.SelectionSort\n3.InsertionSort\n4.MergeSort\n5.QuickSort\n6.HeapSort");
    printf("\nEnter the sort to be used : ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("\nEnter the no of terms: ");
        scanf("%d",&n);
        capture(arr,n);
        bubblesort(arr,n);
        display(arr,n);
        break;
    case 2:
        printf("\nEnter the no of terms: ");
        scanf("%d",&n);
        capture(arr,n);
        selectionsort(arr,n);
        display(arr,n);
        break;
    case 3:
        printf("\nEnter the no of terms: ");
        scanf("%d",&n);
        capture(arr,n);
        insertionsort(arr,n);
        display(arr,n);
        break;
    case 4:
        printf("\nEnter the no of terms: ");
        scanf("%d",&n);
        capture(arr,n);
        mergesort(arr,0,n-1);
        display(arr,n);
        break;
    case 5:
        printf("\nEnter the no of terms: ");
        scanf("%d",&n);
        capture(arr,n);
        quicksort(&arr,0,n-1);
        display(arr,n);
        break;
    case 6:
        printf("\nEnter the no of terms: ");
        scanf("%d",&n);
        capture(arr,n);
        heapsort(arr,n);
        display(arr,n);

    case 7:
        printf("\n==>THANK YOU<====\n");
        break;
    }
    }
    free(arr);
}
//HEAPSORTKAM NAI KARRA
