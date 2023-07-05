#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
        vector<int> result;

    if (root == NULL)
        return result;

    map<int, int> distanceMap;
    queue<pair<TreeNode<int>*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        TreeNode<int>* node = q.front().first;
        int distance = q.front().second;
        q.pop();

        // Store the first occurrence of each horizontal distance
        if (distanceMap.find(distance) == distanceMap.end()) {
            distanceMap[distance] = node->val;
        }

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