/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/


bool symmetric(BinaryTreeNode<int> *t1, BinaryTreeNode<int> *t2) {
    if(t1 == NULL and t2 != NULL) return false;
    if(t1 != NULL and t2 == NULL) return false;
    if(t1 == NULL and t2 == NULL) return true;
    if(t1->data != t2->data) return false;
    return symmetric(t1->left, t2->right) and symmetric(t1->right, t2->left);
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root == NULL) return true;
    if(root->left == NULL and root->right == NULL) return false;
    return symmetric(root->left, root->right);
}

