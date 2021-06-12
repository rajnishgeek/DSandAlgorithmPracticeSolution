TreeNode *curr = NULL;

void inorder(TreeNode* root)
{
   if (root == NULL)
      return;
   inorder(root->left);
   root->left = NULL;
   curr->right = root;
   curr = root;
   inorder(root->right);
}

TreeNode* increasingBST(TreeNode* root)
{
   if (root == NULL)
      return NULL;
   TreeNode* res = new TreeNode(0);
   curr = res;
   inorder(root);
   return res->right;
}