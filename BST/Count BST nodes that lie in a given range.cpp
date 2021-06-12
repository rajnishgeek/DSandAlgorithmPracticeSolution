void solve(Node* root, int l, int h, int &count)
{
  if (root == NULL)
    return;
  if (h < root->data)
    solve(root->left, l, h, count);
  if (l > root->data)
    solve(root->right, l, h, count);
  if (root->data >= l && root->data <= h)
  {
    count++;
    solve(root->left, l, root->data - 1, count);
    solve(root->right, root->data, h, count);
  }
}


//Function to count number of nodes in BST that lie in the given range.
int getCount(Node *root, int l, int h)
{
  // your code goes here
  int count = 0;
  solve(root, l, h, count);
  return count;
}