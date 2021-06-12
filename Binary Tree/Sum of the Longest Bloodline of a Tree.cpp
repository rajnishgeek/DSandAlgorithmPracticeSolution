int maxi;
int height(Node* root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}


void solve(Node* root, int h, int preSum)
{
    if (root == NULL)
        return;
    preSum +=  root->data;
    if (root->left == NULL && root->right == NULL && h == 1 )
        maxi = max(maxi, preSum);
    solve(root->left, h - 1, preSum);
    solve(root->right, h - 1, preSum);
}


int sumOfLongRootToLeafPath(Node *root)
{
    int h = height(root);
    maxi = 0;
    solve(root, h, 0);
    return maxi;
}