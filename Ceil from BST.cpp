#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
      BinaryTreeNode<int> *res = NULL;

    while (node != NULL) {
        if (node->data == x) {
            // x is present in the BST
            return node->data;
        } else if (node->data < x) {
            // Move to the right subtree
            node = node->right;
        } else {
            res = node;
            node = node->left;
        }
    }

    return (res != NULL) ? res->data : -1;
}