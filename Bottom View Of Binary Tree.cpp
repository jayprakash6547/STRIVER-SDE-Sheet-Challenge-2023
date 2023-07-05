#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    vector<int> result;

    if (root == NULL)
        return result;

    map<int, int> distanceMap;
    queue<pair<BinaryTreeNode<int>*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        BinaryTreeNode<int>* node = q.front().first;
        int distance = q.front().second;
        q.pop();

        distanceMap[distance] = node->data;

        if (node->left)
            q.push(make_pair(node->left, distance - 1));
        if (node->right)
            q.push(make_pair(node->right, distance + 1));
    }

    for (auto it = distanceMap.begin(); it != distanceMap.end(); it++) {
        result.push_back(it->second);
    }

    return result;
    
}
