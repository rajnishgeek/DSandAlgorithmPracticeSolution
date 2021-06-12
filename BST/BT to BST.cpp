Node* BST(vector<int> &bt, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    Node* root = new Node(bt[mid]);
    root->left = BST(bt, start, mid - 1);
    root->right = BST(bt, mid + 1, end);
    return root;
}

void store(vector<int> &bt, Node* root)
{
    if (root == NULL)
        return;
    store(bt, root->left);
    bt.push_back(root->data);
    store(bt, root->right);
}

Node *binaryTreeToBST (Node *root)
{
    vector<int> bt;
    store(bt, root);
    sort(bt.begin(), bt.end());
    return BST(bt, 0, bt.size() - 1);
}