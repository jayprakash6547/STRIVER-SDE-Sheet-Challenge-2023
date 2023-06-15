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

bool isPalindrome(LinkedListNode<int> *head) {
       if (head == NULL || head->next == NULL)
        return true;

    // Find the middle of the linked list
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *current = slow->next;
    LinkedListNode<int> *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Compare the first half and the reversed second half
    LinkedListNode<int> *firstHalf = head;
    LinkedListNode<int> *secondHalf = prev;
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;

}