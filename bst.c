#include<stdio.h>
#include<stdlib.h>
struct bst
{
    int data;
    struct bst *prev;
    struct bst *next;
};
struct bst *create(int value)
{
    struct bst *temp;
    temp=(struct bst*)malloc(sizeof(struct bst));
    temp->data=value;
    temp->prev=NULL;
    temp->next=NULL;
    return(temp);
}
void postorder(struct bst *root)
{
    if(root!=NULL)
    {
        postorder(root->prev);
        postorder(root->next);
        printf("%d ",root->data);
    }
}
void preorder(struct bst *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->prev);
        preorder(root->next);
    }
}
void inorder(struct bst *root)
{
    if(root!=NULL)

    {
        inorder(root->prev);
        printf("%d ",root->data);
        inorder(root->next);
    }
}
struct bst *insert(struct bst *root,int val)
{
    if(root==NULL)
    {
        return(create(val));
    }
    if(val<root->data)
    {
        root->prev=insert(root->prev,val);
    }
    else
    {
        root->next=insert(root->next,val);
    }
    return root;
}

struct bst* min_value_node(struct bst *root)
{

    struct bst *current=root;


    while(current && current ->prev!=NULL)
    {

        current=current->prev;
    }
    return current;
}
struct bst *delete_node(struct bst *root,int data)
{
    if(root==NULL)
    {

        return root;
    }
    if(data < root->data)
    {

        root->prev=delete_node(root->prev,data);
    }
    else if(data >root->data)
    {

        root->next=delete_node(root->next,data);
    }
    else{
        if(root->prev ==NULL)
        {

            struct bst *temp=root->next;
            free(root);
            return temp;
        }
        else if(root->next ==NULL)
        {

            struct bst *temp=root->prev;
            free(root);
            return temp;
        }
        struct bst *temp =min_value_node(root->next);
        {

            root->data =temp->data;
            root->next=delete_node(root->next,temp->data);
        }

    }
    return root;
}
int main()
{
    struct bst *root=NULL;
    int ch,dt,dt1;
   while(1)
   {
    printf("====1:Create\n2:postorder\n3:preorder\n4:inorder\n5:delete\n====");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("Enter the data: ");
        scanf("%d",&dt);
        root=insert(root,dt);
        break;
    case 2:
        postorder(root);
        break;
    case 3:
        preorder(root);
        break;
    case 4:
        inorder(root);
        break;
    case 5:
        printf("enter data to be deleted :");
        scanf("%d",&dt1);
        root=delete_node(root,dt1);
        break;
    case 6:
        exit(0);
    }
}
}
