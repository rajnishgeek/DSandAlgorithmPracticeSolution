Node* LCA(Node* root, int a, int b)
{
    if (root == NULL)
        return NULL;

    if (root->data == a || root->data == b)
        return root;

    Node* leftLCA = LCA(root->left, a, b);
    Node* rightLCA = LCA(root->right, a, b);

    if (leftLCA != NULL && rightLCA != NULL)
        return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;

}

int findLevel(Node* root, int value, int level)
{
    if (root == NULL)
        return -1;
    if (root->data == value)
        return level;
    int leftTree = findLevel(root->left, value, level + 1);
    if (leftTree == -1)
        return findLevel(root->right, value, level + 1);
    return leftTree;
}
int findDist(Node* root, int a, int b)
{
    if (root == NULL)
        return 0;
    Node* lcaNode = LCA(root, a, b);
    int dist_a = findLevel(lcaNode, a, 0);
    int dist_b = findLevel(lcaNode, b, 0);
    return dist_a + dist_b;
}