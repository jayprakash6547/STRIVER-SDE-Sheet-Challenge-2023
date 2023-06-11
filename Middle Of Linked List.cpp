/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    // Write your code here
        if (head == nullptr || head->next == nullptr) {
        return head;  // Empty list or single node list
    }
    
    Node* slow = head;
    Node* fast = head;
    
    // Move 'slow' one node at a time and 'fast' two nodes at a time
    // When 'fast' reaches the end, 'slow' will be at the middle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

