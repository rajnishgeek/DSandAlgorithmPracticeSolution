bool isHeap(struct Node * tree)
{
    // code here
    if (tree == NULL)
        return true;
    if (tree->left == NULL && tree->right != NULL)
        return false;
    if (tree->left != NULL && tree->data < tree->left->data)
        return false;
    if (tree->right != NULL &&  tree->data < tree->right->data)
        return false;
    return isHeap(tree->left) && isHeap(tree->right);

}