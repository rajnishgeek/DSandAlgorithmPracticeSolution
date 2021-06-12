int res;
void solve(Node* root, int k, int &count)
{
    if (root == NULL || count >= k)
        return;
    solve(root->left, k, count);
    count++;
    if (count == k)
    {
        res = root->data;
        return;
    }
    solve(root->right, k, count);
}

int KthSmallestElement(Node *root, int K)
{
    //add code here.
    res = -1;
    int count = 0;
    solve(root, K, count);
    return res;
}