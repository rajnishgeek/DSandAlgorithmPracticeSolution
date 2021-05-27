class TrieNode {
public:
    TrieNode *children[26];
    bool isWord;

    TrieNode(bool b = false)
    {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isWord = b;
    }
};

class Trie {
    TrieNode *root;

    TrieNode* find(string word)
    {
        TrieNode *child = root;
        for (int i = 0; i < word.size() && child != NULL ; i++)
        {
            int index = word[i] - 'a';
            child = child->children[index];
        }
        return child;
    }
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *child = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (child->children[index] == NULL)
                child->children[index] = new TrieNode();
            child = child->children[index];
        }
        child->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *child = find(word);
        return (child != NULL && child->isWord == true);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return find(prefix) != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */