//time O(N*H)

TreeNode* BST(vector<int> &v, int start, int end)
{
    if (start > end)
        return NULL;
    TreeNode* root = new TreeNode(v[start]);
    int rightIndex = start + 1;
    for (; rightIndex <= end; rightIndex++)
    {
        if (v[start] < v[rightIndex])
            break;
    }
    if (start + 1 <= rightIndex - 1)
        root->left = BST(v, start + 1, rightIndex - 1);
    if (rightIndex <= end)
        root->right = BST(v, rightIndex, end);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder)
{
    return BST(preorder, 0, preorder.size() - 1);
}


//**********************************************************************
/*
Give the function a bound the maximum number it will handle.
The left recursion will take the elements smaller than node.val
The right recursion will take the remaining elements smaller than bound

Complexity
bstFromPreorder is called exactly N times.
It's same as a preorder traversal.
Time O(N)
Space O(H)


*/
TreeNode* BST(vector<int> &v, int &i, int bound)
{
    if (i == v.size() || v[i] > bound)
        return NULL;
    TreeNode* root = new TreeNode(v[i++]);
    root->left = BST(v, i, root->val);
    root->right = BST(v, i, bound);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder)
{
    return BST(preorder, 0, INT_MAX;
}