vector<int> res;

void store(Node* root)
{
      if (root == NULL)
            return;
      store(root->left);
      res.push_back(root->data);
      store(root->right);
}

float findMedian(struct Node *root)
{
      //Code here
      res.clear();
      store(root);
      if (res.size() % 2 != 0)
            return res[res.size() / 2];
      return (res[res.size() / 2] + res[(res.size() / 2) - 1]) / 2.0;
}