void solve(TreeNode* root, int &res)
{
    if (root == NULL)
        return;
    solve(root->left, res);
    solve(root->right, res);
    if (root->left == NULL && root->right == NULL)
        return;
    int l = 0, r = 0;
    if (root->left)
        l = root->left->val;
    if (root->right)
        r = root->right->val;

    res += abs(l - r);
    root->val += l + r;
}

int findTilt(TreeNode* root)
{
    int res = 0;
    solve(root, res);
    return res;
}