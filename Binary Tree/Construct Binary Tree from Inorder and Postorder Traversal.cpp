TreeNode* buildTreeHelper(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd)
{
    if (inStart > inEnd)
        return NULL;
    int rootData = postorder[postEnd];
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
    int leftPostStart = postStart;
    int leftPostEnd = leftInEnd - leftInStart + leftPostStart;
    int rightInStart = rootIndex + 1;
    int rightInEnd = inEnd;
    int rightPostStart = leftPostEnd + 1;
    int rightPostEnd = postEnd - 1;

    TreeNode* root = new TreeNode(rootData);
    root->left = buildTreeHelper(inorder, postorder, leftInStart, leftInEnd, leftPostStart, leftPostEnd);
    root->right = buildTreeHelper(inorder, postorder, rightInStart, rightInEnd, rightPostStart, rightPostEnd);
    return root;
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}