void BSTToMaxHeap(Node* root, vector<int> arr, int* i)
{
    if (root == NULL)
        return;
    root->data = arr[++*i];
    BSTToMaxHeap(root->left, arr, i);
    BSTToMaxHeap(root->right, arr, i);
}

void inorderTraversal(Node* root, vector<int> &arr)
{
    if (root == NULL)
        return;
    inorderTraversal(root->right, arr);
    arr.push_back(root->data);
    inorderTraversal(root->left, arr);
}

void convertToMaxHeapUtil(Node* root)
{
    // Your code goes here
    vector<int> arr;
    int i = -1;
    inorderTraversal(root, arr);
    BSTToMaxHeap(root, arr, &i);
}