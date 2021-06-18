int sum;
void solve(TreeNode* root, string s)
{
    if (root == NULL)
        return;
    //s.push_back((char)('0' + root->val));
    s += to_string(root->val);

    if (root->left == NULL && root->right == NULL)
        sum += stoi(s, nullptr, 2);
    solve(root->left, s);
    solve(root->right, s);
}

int sumRootToLeaf(TreeNode* root)
{
    sum = 0;
    solve(root, "");
    return sum;
}


//***************************************************
//Efficient solution
int sumRootToLeaf(TreeNode* root, int val = 0) {
    if (!root) return 0;
    val = (val * 2 + root->val);
    return root->left == root->right ? val : sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val));
}
