int solve(Node* node)
{
    if (node == NULL)
        return 0;
    int l = solve(node->left);
    int r = solve(node->right);
    int sum = l + r + node->data;
    node->data = l + r;
    return sum;
}
void toSumTree(Node *node)
{
    solve(node);
}