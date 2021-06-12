Node* temp = NULL;
int res;
Node* solve(Node* root, int node, int &k)
{
    if (root == NULL)
        return NULL;
    if (root->data == node || (temp = solve(root->left, node, k)) || (temp = solve(root->right, node, k)))
    {
        if (k > 0)
            k--;
        else if (k == 0)
        {
            res = root->data;
            return NULL;
        }
        return root;
    }
}

int kthAncestor(Node *root, int k, int node)
{
    res = -1;
    if (solve(root, node, k) == NULL)
        return -1;
    return res;
}