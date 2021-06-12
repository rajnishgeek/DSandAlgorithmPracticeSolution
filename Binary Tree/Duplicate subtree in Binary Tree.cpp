unordered_set<string> m;

string isDuplicate(Node* root)
{
     string s = "";
     if (root == NULL)
          return s + '$';

     string leftStr = isDuplicate(root->left);
     if (leftStr.compare(s) == 0)
          return s;

     string rightStr = isDuplicate(root->right);
     if (rightStr.compare(s) == 0)
          return s;

     s += root->data + leftStr + rightStr;
     if (s.size() > 3 && m.find(s) != m.end())
          return "";
     m.insert(s);
     return s;
}

bool dupSub(Node *root)
{
     m.clear();
     if (isDuplicate(root).compare("") == 0)
          return true;
     return false;
}