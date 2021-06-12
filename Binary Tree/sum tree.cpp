bool res;
int solve(Node* root)
{
    if (root == NULL)
        return 0;
    int l = solve(root->left);
    int r = solve(root->right);
    if (root->left == NULL && root->right == NULL)
        return root->data;
    if (l + r != root->data)
        res = false;
    root->data = l + r + root->data;
    return root->data;
}

bool isSumTree(Node* root)
{
    res = true;
    solve(root);
    return res;
}