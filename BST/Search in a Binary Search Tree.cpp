TreeNode* res;
void solve(TreeNode* root, int value)
{
    if (root == NULL)
        return;
    if (root->val == value)
    {
        res = root;
        return;
    }
    if (value < root->val)
        solve(root->left, value);
    else
        solve(root->right, value);
}

TreeNode* searchBST(TreeNode* root, int val)
{
    res = NULL;
    solve(root, val);
    return res;
}