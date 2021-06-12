int sum;
void greaterBST(TreeNode *root)
{
    if (root->right != NULL)
        greaterBST(root->right);
    root->val += sum;
    sum = root->val;
    if (root->left != NULL)
        greaterBST(root->left);
}

TreeNode* bstToGst(TreeNode* root)
{
    sum = 0;
    greaterBST(root);
    return root;
}