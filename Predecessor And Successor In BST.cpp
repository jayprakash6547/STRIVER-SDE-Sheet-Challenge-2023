#include <bits/stdc++.h> 

pair<int, int> predecessorSuccessor(BinaryTreeNode<int>* root, int key) {
    pair<int, int> result;
    BinaryTreeNode<int>* predecessor = nullptr;
    BinaryTreeNode<int>* successor = nullptr;

    while (root != nullptr) {
        if (key < root->data) {
            // Update the successor if the current node is greater than the key
            successor = root;
            root = root->left;
        } else if (key > root->data) {
            // Update the predecessor if the current node is smaller than the key
            predecessor = root;
            root = root->right;
        } else {
            // If the key is found, update both predecessor and successor
            if (root->left != nullptr) {
                // Find the maximum value in the left subtree as the predecessor
                predecessor = root->left;
                while (predecessor->right != nullptr)
                    predecessor = predecessor->right;
            }
            if (root->right != nullptr) {
                // Find the minimum value in the right subtree as the successor
                successor = root->right;
                while (successor->left != nullptr)
                    successor = successor->left;
            }
            break;
        }
    }

    result.first = (predecessor != nullptr) ? predecessor->data : -1;  // -1 if no predecessor found
    result.second = (successor != nullptr) ? successor->data : -1;  // -1 if no successor found

    return result;
}

