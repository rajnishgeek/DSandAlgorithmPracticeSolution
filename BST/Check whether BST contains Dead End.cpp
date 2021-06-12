bool isDeadEndPossible(Node* root, int l, int r)
{
    if (root == NULL)
        return false;
    else if (root->left == NULL && root->right == NULL && l == r)
        return true;
    else if (r < root->data)
        return isDeadEndPossible(root->left, l, root->data - 1);
    else if (l > root->data)
        return isDeadEndPossible(root->right, root->data + 1, r);
    return isDeadEndPossible(root->left, l, root->data - 1) || isDeadEndPossible(root->right, root->data + 1, r);
}

bool isDeadEnd(Node *root)
{
    //Your code here
    return isDeadEndPossible(root, 1, INT_MAX);
}