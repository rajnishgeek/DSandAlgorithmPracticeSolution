vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while (!st.empty() || curr != NULL)
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
    }
    return res;
}