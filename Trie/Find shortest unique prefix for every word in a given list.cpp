struct node {
    int freq;
    node* children[26];
    node()
    {
        freq = 0;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

void add(node* root, string s, int index)
{
    if (index == s.size())
        return;
    if (root->children[s[index] - 'a'] == NULL)
        root->children[s[index] - 'a'] = new node();

    root->children[s[index] - 'a']->freq++;
    add(root->children[s[index] - 'a'], s, index + 1);
}


int search(node* root, string s, int index)
{
    if (root->children[s[index] - 'a']->freq == 1)
        return index;
    if (root->children[s[index] - 'a'] != NULL)
        return search(root->children[s[index] - 'a'], s, index + 1);

    return -1;
}

vector<string> findPrefixes(string arr[], int n)
{
    //code here
    vector<string> result;

    //ceating root node
    node* root = new node();

    //adding all string into the trie
    for (int i = 0; i < n; i++)
        add(root, arr[i], 0);

    for (int i = 0; i < n; i++)
    {
        int index = search(root, arr[i], 0);
        string s = "";
        for (auto it : arr[i])
        {
            if (index < 0)
                break;
            s += it;
            index--;
        }
        result.push_back(s);
    }
    return result;
}