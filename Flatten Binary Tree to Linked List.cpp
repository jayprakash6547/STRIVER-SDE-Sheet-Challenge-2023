#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/


void flattenBT(TreeNode<int>* root, TreeNode<int>* &next){
    // Base Case
    if(root == NULL) return;
    // Flatten Right Sub Tree
    flattenBT(root->right, next);
    // Flatten Left Sub Tree
    flattenBT(root->left, next);
    // Update/Modify
    root->left = NULL;
    root->right = next;
    next = root;
}


TreeNode<int>* flattenBinaryTree(TreeNode<int> *root)
{
    // Approach 1: Recursive Approach > Using a next pointer.
    // Time Complexity: O(N)
    // Spave Complexity: O(Height)
    TreeNode<int>* next = NULL;
    flattenBT(root, next);
    return root;
}