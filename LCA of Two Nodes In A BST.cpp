#include<bits/stdc++.h>
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q) {
    if (root == nullptr)
        return nullptr;

    int rootValue = root->data;
    int PValue = P->data;
    int QValue = Q->data;

    // If both P and Q are smaller than the current node, LCA is in the left subtree
    if (PValue < rootValue && QValue < rootValue)
        return LCAinaBST(root->left, P, Q);

    // If both P and Q are greater than the current node, LCA is in the right subtree
    if (PValue > rootValue && QValue > rootValue)
        return LCAinaBST(root->right, P, Q);

    // If one node is smaller and the other is greater, or one of the nodes is the current node
    // itself, then the current node is the LCA
    return root;
}

