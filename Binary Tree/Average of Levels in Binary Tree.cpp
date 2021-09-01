int height(TreeNode* root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}


void findNodes(TreeNode* root, vector<vector<int>> &levelNodes, int height)
{
    if (root == NULL)
        return;
    levelNodes[height].push_back(root->val);
    findNodes(root->left, levelNodes, height + 1);
    findNodes(root->right, levelNodes, height + 1);
}

vector<double> averageOfLevels(TreeNode* root)
{
    int h = height(root);
    int mod = 100000;
    vector<double> result;
    vector<vector<int>> levelNodes(h, vector<int> {});
    findNodes(root, levelNodes, 0);
    for (auto v : levelNodes)
    {
        double sum = 0;
        for (auto element : v)
            sum += element;
        result.push_back(sum / v.size());
    }
    return result;
}