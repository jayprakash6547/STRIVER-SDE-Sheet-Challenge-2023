#include <bits/stdc++.h> 

int kthSmallest(TreeNode<int> *root, int k)
{
	 stack<TreeNode<int>*> st;
    TreeNode<int>* curr = root;
    int count = 0;

    while (curr != NULL || !st.empty()) {
        // Reach the leftmost node of the current subtree
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        count++;

        if (count == k) {
            return curr->data;  // Found the k-th smallest node
        }

        curr = curr->right;  // Move to the right subtree
    }

    return -1;  // k is greater than the number of nodes in the BST


}