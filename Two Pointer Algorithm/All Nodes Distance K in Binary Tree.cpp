unordered_map<TreeNode*, int> m;

void find(TreeNode* root, TreeNode* target)
{
    if (root == NULL)
        return;
    if (root == target)
    {
        m[root] = 0;
        return;
    }

    find(root->left, target);
    if (m.count(root->left))
    {
        m[root] = m[root->left] + 1;
        return;
    }

    find(root->right, target);
    if (m.count(root->right))
    {
        m[root] = m[root->right] + 1;
        return;
    }
}


void searchNode(TreeNode* root, int len, int k, vector<int> &result)
{
    if (root == NULL)
        return;
    if (m.count(root))
        len = m[root];
    if (len == k)
        return.push_back(root->val);
    searchNode(root->left, len + 1, k, result);
    searchNode(root->right, len + 1, k, result);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
{
    vector<int> result;
    find(root, target);
    searchNode(root, 0, k, result);
    return result;
}