//BFS solution
//Time O(n), space O(n)

int height(TreeNode* root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
vector<vector<int>> levelOrderBottom(TreeNode* root)
{
    int h = height(root);
    vector<vector<int>> res(h, vector<int> ());
    if (root == NULL)
        return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty() && h-- >= 0)
    {
        int n = q.size();
        while (n--)
        {
            TreeNode* temp = q.front();
            q.pop();
            res[h].push_back(temp->val);
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return res;
}


//DFS Solution
//Time O(n), space O(n)
int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

void solve(TreeNode *root, vector<vector<int>> &res, int level)
{
    if (root == NULL)
        return;
    res[level].push_back(root->val);
    solve(root->left, res, level - 1);
    solve(root->right, res, level - 1);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    int h = height(root);
    vector<vector<int>> res(h, vector<int> {});
    solve(root, res, h - 1);
    return res;
}