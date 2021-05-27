//Time complexity O(n)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root == NULL)
        return NULL;
    if (root == p || root == q)
        return root;
    TreeNode *leftSubtree = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightSubtree = lowestCommonAncestor(root->right, p, q);
    if (leftSubtree != NULL && rightSubtree != NULL)
        return root;
    if (leftSubtree == NULL && rightSubtree == NULL)
        return NULL;
    return leftSubtree != NULL ? leftSubtree : rightSubtree;
}