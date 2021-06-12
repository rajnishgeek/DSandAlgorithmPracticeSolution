TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root == NULL)
        return NULL;
    else if (root->val > p->val && root->val < q->val)
        return root;
    else if (root->val == p->val || root->val == q->val)
        return root;

    else if (q->val < root->val)
        return LCA(root->left, p, q);
    else
        return LCA(root->right, p, q);
}
public:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (p->val > q->val)
        swap(p, q);
    return LCA(root, p, q);
}

//efficient code
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root->val > p->val &&  root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (root->val < p->val &&  root->val < q->val)
        lowestCommonAncestor(root->right, p, q);
    return root;
}