/*
Method 1
We can solve this problem by considering the fact that both node and its children can’t
 be in sum at the same time, so when we take a node into our sum we will call recursively
 for its grandchildren or if we don’t take this node then we will call for all its children
 nodes and finally we will choose maximum from both of the results.
It can be seen easily that the above approach can lead to solving the same subproblem many
times, for example in the above diagram node 1 calls node 4 and 5 when its value is chosen and
node 3 also calls them when its value is not chosen so these nodes are processed more than once.
 We can stop solving these nodes more than once by memoizing the result at all nodes.
In the below code, a map is used for memoizing the result which stores the result of the complete
 subtree rooted at a node in the map so that if it is called again, the value is not calculated again
 instead stored value from the map is returned directly.
*/

int sumOfGrandChildren(Node* root, unordered_map<Node*, int> &m)
{
    int sum = 0;
    if (root->left != NULL)
        sum += getMaxSumHelper(root->left->left, m) + getMaxSumHelper(root->left->right, m);
    if (root->right != NULL)
        sum += getMaxSumHelper(root->right->left, m) + getMaxSumHelper(root->right->right, m);
    return sum;
}


int getMaxSumHelper(Node* root, unordered_map<Node*, int> &m)
{
    if (root == NULL)
        return 0;
    if (m.find(root) != m.end())
        return m[root];

    int inclusive = root->data + sumOfGrandChildren(root, m);
    int exclusive = getMaxSumHelper(root->left, m) + getMaxSumHelper(root->right, m);
    m[root] = max(inclusive, exclusive);
    return m[root];
}

int getMaxSum(Node *root)
{
    if (root == NULL)
        return 0;
    unordered_map<Node*, int> m;
    return getMaxSumHelper(root, m);
}



/*
Method 2 (Using pair)
Return a pair for each node in the binary tree such that the first of the pair indicates
 maximum sum when the data of a node is included and the second indicates maximum sum when
  the data of a particular node is not included
*/

pair<int, int> getMaxSumHelper(Node* root)
{
    if (root == NULL)
    {
        pair<int, int> sum(0, 0);
        return sum;
    }

    pair<int, int> leftSum = getMaxSumHelper(root->left);
    pair<int, int> rightSum = getMaxSumHelper(root->right);
    pair<int, int> currSum;
    currSum.first = root->data + leftSum.second + rightSum.second;
    currSum.second = max(leftSum.first, leftSum.second) + max(rightSum.first, rightSum.second);
    return currSum;
}


int getMaxSum(Node *root)
{
    pair<int, int> res = getMaxSumHelper(root);
    return max(res.first, res.second);
}