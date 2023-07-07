#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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
int height(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return true;
    }
    if(isBalancedBT(root->left) && isBalancedBT(root->right)){
        if(abs(height(root->left) - height(root->right)) <=1 ){
            return true;
        }
    }
    return false;
}