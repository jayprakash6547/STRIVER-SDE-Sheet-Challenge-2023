#include <bits/stdc++.h>

// template <typename T>
// class BinaryTreeNode {
// public:
//     T val;
//     BinaryTreeNode<T> *left;
//     BinaryTreeNode<T> *right;

//     BinaryTreeNode(T val) {
//         this->val = val;
//         left = nullptr;
//         right = nullptr;
//     }
// };

vector<int> getLevelOrder(BinaryTreeNode<int> *root) {
    vector<int> levelOrder;

    if (root == nullptr)
        return levelOrder;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode<int>* node = q.front();
        q.pop();

        levelOrder.push_back(node->val);

        if (node->left)
            q.push(node->left);

        if (node->right)
            q.push(node->right);
    }

    return levelOrder;
}
