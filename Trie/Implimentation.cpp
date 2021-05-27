#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    TrieNode *root;
    //search helper function
    bool searchWordHelper(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            if (root->isTerminal == true)
                return true;
            else
                return false;
        }

        //small calculation
        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
            child = root->children[index];
        else
            return false;

        //recursion call
        return searchWordHelper(child, word.substr(1));
    }

    //remover helper function
    void removeHelper(TrieNode *root, string word)
    {
        //base case
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        //small calculation
        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
            child = root->children[index];
        else //word not found
            return;

        //recusion call
        removeHelper(child, word.substr(1));

        //remove char if it is useless
        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                    return;
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    //insert helper function
    void insertWord(TrieNode *root, string word)
    {
        //base Case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        //small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
            child = root->children[index];
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //recursion call
        insertWord(child, word.substr(1));
    }

public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
    }

    //for user
    void insert(string word)
    {
        insertWord(root, word);
    }

    //for user
    void remove(string word)
    {
        removeHelper(root, word);
    }

    //for user search function
    bool search(string word)
    {
        return searchWordHelper(root, word);
    }
};

int main()
{
    TrieNode *boj = new TrieNode('');
    return 0;
}