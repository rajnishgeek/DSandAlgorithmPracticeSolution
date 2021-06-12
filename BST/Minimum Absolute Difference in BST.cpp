int res;
void solve(TreeNode* root)
{
    if (root == NULL)
        return;
    if (root->left != NULL && abs(root->val - root->left->val) < res)
        res = abs(root->val - root->left->val);
    if (root->right != NULL && abs(root->val - root->right->val) < res)
        res = abs(root->val - root->right->val);
    solve(root->left);
    solve(root->right);
}
int getMinimumDifference(TreeNode* root)
{
    res = INT_MAX;
    solve(root);
    return res;
}