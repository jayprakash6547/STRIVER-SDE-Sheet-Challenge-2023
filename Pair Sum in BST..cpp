#include <bits/stdc++.h> 
bool isPairSum(BinaryTreeNode<int> *root, int sum, unordered_set<int> &s) 
{ 
    if(root==NULL)return false;
    
    if(isPairSum(root->left,sum,s)==true)
        return true;
        
    if(s.find(sum-root->data)!=s.end())  
        return true;
    else
        s.insert(root->data);
    return isPairSum(root->right,sum,s);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    unordered_set<int> s;
    return isPairSum(root, k, s);
}


