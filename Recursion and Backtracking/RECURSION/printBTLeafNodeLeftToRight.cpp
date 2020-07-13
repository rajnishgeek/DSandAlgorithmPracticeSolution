#include<bits/stdc++.h>
using namespace std;

//time complexity of this function is O(N)
//here N is number of nodes

//node structure
struct Node
{
    int val;
    struct Node *left,*right;
};

void printLeftNodeLeftToRight(Node *root)
{
    //here two base case exists
    //base case 1
    if(!root)
        return;

    //base case 2
    if(!root->left && !root->right)
    {
        cout<<root->val<<" ";
        return;
    }

    //if root left is exists
    if(root->left)
    printLeftNodeLeftToRight(root->left);

    //if root right exists
    printLeftNodeLeftToRight(root->right);
}

//create new node
Node *newNode(int val)
{
    Node *temp=new Node;
    temp->val=val;
    temp->left=temp->right=0;
    return temp;
}
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(8);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    printLeftNodeLeftToRight(root);
    return 0;
}
