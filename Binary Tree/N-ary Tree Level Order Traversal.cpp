vector<vector<int>> levelOrder(Node* root)
{
    vector<vector<int>> result;
    if (root == NULL)
        return result;
    queue<Node*> q;

    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        // Node* temp=q.front()
        vector<int> v;
        for (int i = 0; i < size; i++)
        {
            Node* temp = q.front();
            q.pop();
            v.push_back(temp->val);
            for (int i = 0; i < temp->children.size(); i++)
                q.push(temp->children[i]);
        }
        result.push_back(v);
    }
    return result;
}