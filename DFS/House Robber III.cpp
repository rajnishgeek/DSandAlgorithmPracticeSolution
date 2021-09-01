pair<int, int> robHouse(TreeNode* root)
{
    pair<int, int> res = {0, 0};
    if (root == NULL)
        return res;

    pair<int, int> leftSub = robHouse(root->left);
    pair<int, int> rightSub = robHouse(root->right);
    res.first = max(leftSub.first, leftSub.second) + max(rightSub.first, rightSub.second);
    res.second = root->val + leftSub.first + rightSub.first;
    return res;
}

int rob(TreeNode * root)
{
    pair<int, int> p = robHouse(root);
    return max(p.first, p.second);
}