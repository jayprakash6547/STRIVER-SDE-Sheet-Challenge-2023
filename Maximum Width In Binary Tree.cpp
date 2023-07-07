#include <bits/stdc++.h>

// template <typename T>
// class TreeNode {
// public:
//     T val;
//     TreeNode<T> *left;
//     TreeNode<T> *right;

//     TreeNode(T val) {
//         this->val = val;
//         left = nullptr;
//         right = nullptr;
//     }
// };

int getMaxWidth(TreeNode<int> *root) {
    if (root == nullptr)
        return 0;

    int maxWidth = 0;

    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        int levelWidth = q.size();

        maxWidth = max(maxWidth, levelWidth);

        for (int i = 0; i < levelWidth; i++) {
            TreeNode<int>* node = q.front();
            q.pop();

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
    }

    return maxWidth;
}
