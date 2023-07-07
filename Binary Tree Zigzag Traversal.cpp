#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
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

*************************************************************/


vector<int> zigZagTraversal(BinaryTreeNode<int> *root) {
    // Approach: Using a queue and temp vectors.
    vector<int> ans;
    if(root == NULL) return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    bool flag = true;
    while(!q.empty()){
        int n = q.size();
        vector<int> temp(n);
        for(int i = 0; i < n; i++){
            BinaryTreeNode<int> *curr = q.front();
            q.pop();
            // Check
            if(flag)
                temp[i] = curr->data;
            else
                temp[n - i - 1] = curr->data;
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
        // update the ans
        for(auto it : temp){
            ans.push_back(it);
        }
        flag = !flag;
    }
}
