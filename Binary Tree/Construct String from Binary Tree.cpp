//time O(n)
string res;
void solve(TreeNode* root)
{
    if (root == NULL)
        return;
    res += to_string(root->val);
    if (root->left == NULL && root->right == NULL)
        return;
    if (root->left == NULL)
    {
        res.push_back('(');
        res.push_back(')');
    }
    if (root->left != NULL)
    {
        res.push_back('(');
        solve(root->left);
        res.push_back(')');
    }
    if (root->right != NULL)
    {
        res.push_back('(');
        solve(root->right);
        res.push_back(')');
    }

}

string tree2str(TreeNode* root)
{
    res.clear();
    solve(root);
    return res;
}


//Optimize code, time O(n);
string tree2str(TreeNode* root)
{
    if (root == NULL)
        return "";
    string result = root->val + "";
    string leftTree = tree2str(root->left);
    string rightTree = tree2str(root->right);
    if (leftTree == "" && rightTree == "")
        return result;
    if (leftTree == "")
        return result + "()" + "(" + rightTree + ")";
    if (rightTree == "")
        return "(" + result + ")";
    return result + "(" + leftTree + ")" + "(" + rightTree + ")";
}