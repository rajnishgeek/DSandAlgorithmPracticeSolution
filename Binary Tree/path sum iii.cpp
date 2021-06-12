//Time O(n)
int pathSumRoot(TreeNode *root, int sum)
{
	if (root == NULL)
		return 0;
	int res = 0;
	if (root->val == sum)
		res++;
	res += pathSumRoot(root->left, sum - root->val);
	res += pathSumRoot(root->right, sum - root->val);
	return res;
}

int pathSum(TreeNode* root, int targetSum)
{
	if (root == NULL)
		return 0;
	return pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + pathSumRoot(root, targetSum);
}


//Prefix sum approach
int solve(TreeNode *root, int prefixSum, int sum, unordered_map<int, int> &m)
{
	if (root == NULL)
		return 0;
	prefixSum += root->val;
	int res = 0;
	if (m.count(prefixSum - sum))
		res += m[prefixSum - sum];
	m[prefixSum]
}

int pathSumRoot(TreeNode *root, int sum)
{
	unordered_map<int, int> m;
	m[0] = 1;
	return solve(root, 0, targetSum, m);
}