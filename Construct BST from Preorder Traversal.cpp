#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* solve(vector<int>& preOrder,int& i,int bound){
    if(i==preOrder.size() || preOrder[i]>bound) return NULL;
    TreeNode<int>* root =new TreeNode<int>(preOrder[i++]);
    root->left=solve(preOrder,i,root->data);
    root->right=solve(preOrder,i,bound);
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
     int i=0,val=1e9;
     return solve(preOrder,i,val);
}