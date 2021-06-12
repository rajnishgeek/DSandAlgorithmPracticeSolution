bool isBal;
int solve(TreeNode* root, bool &isBal)
{
    if (root == NULL)
        return 0;
    int l = solve(root->left, isBal);
    int r = solve(root->right, isBal);
    if (abs(l - r) > 1)
        isBal = false;
    return 1 + max(l, r);
}

bool isBalanced(TreeNode* root)
{
    if (root == NULL)
        return true;
    isBal = true;
    solve(root, isBal);
    return isBal;
}