#include <bits/stdc++.h> 
void inorderhelp(TreeNode<int>* root,vector<int>& x){
    if(root==NULL){
        return;
    }
    inorderhelp(root->left,x);
    x.push_back(root->data);
    inorderhelp(root->right,x);
    //inorder traversal
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    vector<int> x;
    inorderhelp(root,x);
    //inorder traversal
    int n=x.size();
    if (k > n) {
      return -1;
    }
    return x[n - k];
    // return kth largest element.
}
