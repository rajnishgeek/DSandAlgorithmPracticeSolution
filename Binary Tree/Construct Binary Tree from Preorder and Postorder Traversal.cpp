int findIndex(vector<int> &post, int value, int i, int j)
{
    for (; i <= j; i++)
    {
        if (value = post[i])
            return i;
    }
    return -1;
}



// TreeNode* BT(vector<int> &pre, int preStart, int preEnd, vector<int> &post, int postStart, int postEnd)
// {
//     if (preStart > preEnd)
//         return NULL;

//     TreeNode * root = new TreeNode(pre[preStart])


//     if (preStart == preEnd)
//         return root;

//     int leftPreStart = preStart + 1;
//     int leftPreEnd;
//     int rightPreStart;
//     int rightPreEnd = preEnd;
//     int leftPostStart = postStart;
//     int leftPostEnd = findIndex(post, pre[preStart], postStart, postEnd);
//     int rightPostStart = leftPostEnd + 1;;
//     int rightPostEnd = postEnd - 1;;



//     leftPreEnd = leftPostEnd - leftPostStart + leftPreStart;
//     rightPreStart = leftPreEnd + 1;
//     root->left = BT(pre, leftPreStart, leftPreEnd, post, leftPostStart, leftPostEnd);
//     root->right = BT(pre, rightPreStart, rightPreEnd, post, rightPostStart, rightPostEnd);
//     return root;
// }

TreeNode* BT(vector<int> &pre, int preStart, int preEnd, vector<int> &post, int postStart, int postEnd)
{
    if (preStart > preEnd)
        return NULL;

    TreeNode * root = new TreeNode(pre[preStart])


    if (preStart == preEnd)
        return root;

    int leftPreStart = preStart + 1;
    // int leftPreEnd;
    // int rightPreStart;
    // int rightPreEnd = preEnd;
    // int leftPostStart = postStart;
    int leftPostEnd = findIndex(post, pre[preStart], postStart, postEnd);
    int rightPostStart = leftPostEnd + 1;;
    int rightPostEnd = postEnd - 1;;



    leftPreEnd = leftPostEnd - postStart + leftPreStart;
    rightPreStart = leftPreEnd + 1;
    root->left = BT(pre, leftPreStart, leftPreEnd, post, leftPostStart, leftPostEnd);
    root->right = BT(pre, rightPreStart, rightPreEnd, post, rightPostStart, rightPostEnd);
    return root;
}


TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post)
{
    return BT(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
}