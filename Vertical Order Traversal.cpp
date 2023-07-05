#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> result;

    if (root == NULL)
        return result;

    map<int, vector<int>> verticalMap;
    queue<pair<TreeNode<int>*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        TreeNode<int> *node = q.front().first;
        int distance = q.front().second;
        q.pop();

        verticalMap[distance].push_back(node->data);

        if (node->left)
            q.push(make_pair(node->left, distance - 1));
        if (node->right)
            q.push(make_pair(node->right, distance + 1));
    }

    for (auto it = verticalMap.begin(); it != verticalMap.end(); it++)
    {
        vector<int> values = it->second;
        for (int i = 0; i < values.size(); i++)
        {
            result.push_back(values[i]);
        }
    }

    return result;
}