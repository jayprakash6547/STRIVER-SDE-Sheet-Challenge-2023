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

TreeNode<int>*  cT(vector<int> &inorder, vector<int> &preorder, int is, int ie,int &preIndex)
    {
        if(is>ie)
        {
            return NULL;
        }
      TreeNode<int> *root=new TreeNode<int> (preorder[preIndex++]);
        int inIndex;
        for(int i=0;i<=ie;i++)
        {
            if(root->data==inorder[i])
            {
                inIndex=i;
                break;
           }

        }
        root->left=cT(inorder,preorder,is,inIndex-1,preIndex);
        root->right=cT(inorder,preorder,inIndex+1,ie,preIndex);
        return root;
    }
   TreeNode<int> *buildBinaryTree(vector<int> &inorder,vector<int> &preorder)
    {
        int preIndex=0;
        int is=0, ie=inorder.size()-1;
        return cT(inorder,preorder,is,ie,preIndex);
    }