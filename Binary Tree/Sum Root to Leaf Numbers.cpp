int res;
void solve(TreeNode* root, int preSum)
{
    if (root == NULL)
        return;
    preSum = preSum * 10 + root->val;
    if (root->left == NULL && root->right == NULL)
        res += preSum;
    solve(root->left, preSum);
    solve(root->right, preSum);
}

int sumNumbers(TreeNode* root)
{
    res = 0;
    solve(root, 0);
    return res;
}