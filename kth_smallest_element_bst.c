
int inOrder(Node *root, int &count, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int ans = inOrder(root->left, count, k);
    if (ans != -1)
    {
        return ans;
    }
    count++;
    if (count == k)
    {
        return root->data;
    }
    return inOrder(root->right, count, k);
}
int KthSmallestElement(Node *root, int k)
{
    int count = 0;
    return inOrder(root, count, k);
}
