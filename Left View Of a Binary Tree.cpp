#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void LeftView(TreeNode <int>*root,vector<int>&v,int level){
    if(root==NULL){
        return ;
    }
    if(level==v.size())
        v.push_back(root->data);
        LeftView(root->left,v,level+1);
        LeftView(root->right,v,level+1);
    
}


vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int>v;
    LeftView(root,v,0);
    return v;
}