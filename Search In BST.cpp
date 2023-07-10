#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {

    // recursive solution
    /*if(root ==NULL)
    return false;
  else if(root->data==x)
    return true;
   else if(root->data>x){
        searchInBST(root->left,x);
    }
    else{
        searchInBST(root->right,x);
    }*/
    
    // iterative solution
    while(root!=NULL){
        if(root->data == x)
        return true;
        if(root->data < x){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return false;
}