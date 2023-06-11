#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
     if (node == nullptr || node->next == nullptr)
        return;

    LinkedListNode<int>* nextNode = node->next;
    node->data = nextNode->data;
    node->next = nextNode->next;
    delete nextNode;
}