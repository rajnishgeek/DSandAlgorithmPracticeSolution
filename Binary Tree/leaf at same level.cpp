bool res;
int height(Node* root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

void isSameHeight(Node* root, int h)
{
    if (root == NULL)
        return;
    isSameHeight(root->left, h - 1);
    if (root->left == NULL && root->right == NULL && h != 1)
        res = false;
    isSameHeight(root->right, h - 1);
}

bool check(Node *root)
{
    int h = height(root);
    res = true;
    isSameHeight(root, h);
    return res;
}

