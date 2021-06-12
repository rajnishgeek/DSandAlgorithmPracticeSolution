TreeNode* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd)
{
    if (inStart > inEnd)
        return NULL;
    int rootData = preorder[preStart];
    int rootIndex = -1;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }
    int leftInStart = inStart;
    int leftInEnd = rootIndex - 1;
    int leftPreStart = preStart + 1;
    int leftPreEnd = leftInEnd - leftInStart + leftPreStart;
    int rightInStart = rootIndex + 1;
    int rightInEnd = inEnd;
    int rightPreStart = leftPreEnd + 1;
    int rightPreEnd = preEnd;

    TreeNode* root = new TreeNode(rootData);
    root->left = buildTreeHelper(preorder, inorder, leftPreStart, leftPreEnd, leftInStart, leftInEnd);
    root->right = buildTreeHelper(preorder, inorder, rightPreStart, rightPreEnd, rightInStart, rightInEnd);
    return root;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    return buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}