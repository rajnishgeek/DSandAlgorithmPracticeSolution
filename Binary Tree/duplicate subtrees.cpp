//time O(n), space O(n)

unordered_map<string, int> m;
vector<TreeNode*> res;
string inorder(TreeNode* root)
{
	if (root == NULL)
		return "";

	string s = "(";
	s += inorder(root->left);
	s += to_string(root->val);
	s += inorder(root->right);
	s += ")";
	if (m[s] == 1)
		res.push_back(root);
	m[s]++;
	return s;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
{
	m.clear();
	res.clear();
	inorder(root);
	return res;
}