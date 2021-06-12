void storeElement(TreeNode *root, vector<int> &sorted)
{
    if (root == NULL)
        return;
    storeElement(root->left, sorted);
    sorted.push_back(root->val);
    storeElement(root->right, sorted);
}

TreeNode* arrayToBalanceBST(vector<int> &sorted, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    TreeNode *newRoot = new TreeNode(sorted[mid]);
    newRoot->left = arrayToBalanceBST(sorted, start, mid - 1);
    newRoot->right = arrayToBalanceBST(sorted, mid + 1, end);
    return newRoot;
}

TreeNode* balanceBST(TreeNode* root)
{
    vector<int> sorted;
    storeElement(root, sorted);
    return arrayToBalanceBST(sorted, 0, sorted.size() - 1);
}