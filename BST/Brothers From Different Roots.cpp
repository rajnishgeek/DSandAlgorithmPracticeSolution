bool findInBST2(Node* root, int value)
{
    if (root == NULL)
        return false;
    if (root->data == value)
        return true;
    return findInBST2(root->left, value) || findInBST2(root->right, value);
}

void BST1Nodes(Node* root1, Node* root2, int x, int &count)
{
    if (root1 == NULL)
        return;
    BST1Nodes(root1->left, root2, x, count);
    if (findInBST2(root2, x - root1->data))
        count++;
    BST1Nodes(root1->right, root2, x, count);
}

int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    int count = 0;
    BST1Nodes(root1, root2, x, count);
    return count;
}