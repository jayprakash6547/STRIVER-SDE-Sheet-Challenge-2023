#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void inOrder(BinaryTreeNode<int>* root, vector<int>& traversal) {
    if (root == NULL)
        return;

    inOrder(root->left, traversal);
    traversal.push_back(root->data);
    inOrder(root->right, traversal);
}

void preOrder(BinaryTreeNode<int>* root, vector<int>& traversal) {
    if (root == NULL)
        return;

    traversal.push_back(root->data);
    preOrder(root->left, traversal);
    preOrder(root->right, traversal);
}

void postOrder(BinaryTreeNode<int>* root, vector<int>& traversal) {
    if (root == NULL)
        return;

    postOrder(root->left, traversal);
    postOrder(root->right, traversal);
    traversal.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> traversals;

    vector<int> inOrderTraversal;
    inOrder(root, inOrderTraversal);
    traversals.push_back(inOrderTraversal);

    vector<int> preOrderTraversal;
    preOrder(root, preOrderTraversal);
    traversals.push_back(preOrderTraversal);

    vector<int> postOrderTraversal;
    postOrder(root, postOrderTraversal);
    traversals.push_back(postOrderTraversal);

    return traversals;
}