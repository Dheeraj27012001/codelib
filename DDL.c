#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
};
typedef struct node * NODE;
NODE create()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d",&temp->data);
    temp->prev=temp->next=NULL;
    return temp;
}
NODE addfront(NODE first)
{
    NODE last,temp;
    temp=create();
    if(first==NULL)
        return temp;
    else
    {first->prev=temp;
    temp->next=first;
    return temp;
    }
}
NODE addrear(NODE first)
{
    NODE last,temp;
    temp=create();
    if(first==NULL)
        return temp;
    else
    {
    for(last=first;last->next!=NULL;last=last->next);
    temp->prev=last;
    last->next=temp;
    return first;
    }
}
NODE deletefront(NODE first)
{
    NODE temp;
    if(first==NULL)
        printf("List is empty\n");
    else
    {temp=first;
    first=first->next;
    first->prev=NULL;
    printf("The front data to be deleted data : %d\n",temp->data);
    free(temp);
    return first;
    }
}
NODE deleterear(NODE first)
{
    NODE temp,last;
    if(first==NULL)
        printf("List is empty\n");
    else
    {
    for(last=first;last->next!=NULL;last=last->next);
    temp=last;
    last->prev->next=NULL;
    printf("The last data to be deleted data : %d\n",temp->data);
    free(temp);
    return first;
    }
}

void display(NODE first)
{
    NODE last;
    for(last=first;last!=NULL;last=last->next)
    {
        printf("%d\n",last->data);
    }
}
void revdisplay(NODE first)
{
    NODE last,temp;
    for(last=first;last->next!=NULL;last=last->next);
    for(temp=last;temp!=NULL;temp=temp->prev)
    {
        printf("%d\n",temp->data);
    }
}
NODE insertspec(NODE first)
{
    NODE last,temp; int i=0,pos;
    printf("Enter position\n");
    scanf("%d",&pos);
    temp=create();
    if(pos==1)
    {   temp->next=first;
        first->prev=temp;
        return temp;}
    else
    {   last=first;
        for(i=1;i<pos;i++)
            last=last->next;
        last->prev->next=temp;
        temp->next=last;
        return first;
    }
}
NODE deletespec(NODE first)
{
    NODE last,temp; int i=0,pos;
    printf("Enter position\n");
    scanf("%d",&pos);
    if(pos==1)
    {   temp=first;
        first=first->next;
        first->prev=NULL;
        printf("%d is data to be deleted\n",temp->data);
        free(temp);
        return first;}
    else
    {   last=first;
        for(i=1;i<pos;i++)
            last=last->next;
        temp=last;
        last->prev->next=last->next;
        last->next->prev=temp->prev;
        printf("%d is data to be deleted\n",temp->data);
        free(temp);
        return first;
    }
}

int main()
{ NODE first; int ch;
  first=NULL;
  while(1)
  { printf("1.ADD first\t2.Add rear\t3.Delete front\t\t4.Delete end\t\t5.display\t6.Reverse display\n7.Insert position\t8.delete position\t9.Exit\n");
    scanf("%d",&ch);

    switch(ch)
    { case 1:first=addfront(first);
      break;
      case 2:first=addrear(first);
      break;
      case 3:first=deletefront(first);
      break;
      case 4:first=deleterear(first);
      break;
      case 5:display(first);
      break;
      case 6:revdisplay(first);
      break;
      case 7:first=insertspec(first);
      break;
      case 8:first=deletespec(first);
      break;
      case 9:exit(0);
      default : printf("Invalid choice\n");
    }
}
}
