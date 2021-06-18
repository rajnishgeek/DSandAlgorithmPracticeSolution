struct Info
{
	int size, max, min, ans;
	bool isBST;
};

Info largestBstHelper(Node *root)
{
	if (root == NULL)
		return {0, INT_MIN, INT_MAX, 0, true};

	if (root->left == NULL && root->right == NULL)
		return {1, root->data, root->data, 1, true};

	Info l = largestBstHelper(root->left);
	Info r = largestBstHelper(root->right);

	Info ret;
	ret.size = 1 + l.size + r.size;

	if (l.isBST && r.isBST && l.max < root->data && root->data < r.min)
	{
		ret.min = min(l.min, min(root->data, r.min));
		ret.max = max(r.max, max(l.max, root->data));

		ret.ans = ret.size;
		ret.isBST = true;
		return ret;
	}

	ret.ans = max(l.ans, r.ans);
	ret.isBST = false;
	return ret;
}

int largestBst(Node *root)
{
	return largestBstHelper.ans;
}