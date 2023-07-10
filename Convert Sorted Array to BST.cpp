#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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
TreeNode<int>* sortedArrToBST(vector<int> &arr, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    TreeNode<int>* node = new TreeNode<int>(arr[mid]);

    node->left = sortedArrToBST(arr, start, mid - 1);
    node->right = sortedArrToBST(arr, mid + 1, end);

    return node;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n) {
    return sortedArrToBST(arr, 0, n - 1);
}

