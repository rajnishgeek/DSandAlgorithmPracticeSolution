int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}


int maxRobbery(TreeNode *root, int start, int end)
{
    if (root == NULL)
        return 0;
}

int rob(TreeNode* root)
{
    int level = height(root);
    return max(maxRobbery(root, 0, level - 2), maxRobbery(root->left, 1, level - 1) + maxRobbery(root->right, 1, level - 1));
}