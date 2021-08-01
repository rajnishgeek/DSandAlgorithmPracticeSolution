TreeNode* pruneTree(TreeNode* root)
{
    if (root == NULL)
        return NULL;
    TreeNode* leftSubTree = pruneTree(root->left);
    if (leftSubTree == NULL)
        root->left = NULL;
    TreeNode* rightSubTree = pruneTree(root->right);
    if (rightSubTree == NULL)
        root->right = NULL;
    return (leftSubTree == NULL && rightSubTree == NULL && root->val == 0) ? NULL : root;
}