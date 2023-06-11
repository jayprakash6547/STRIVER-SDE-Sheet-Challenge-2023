Node* removeKthNode(Node* head, int K) {
    if (head == nullptr || K <= 0)
        return head;
    
    Node dummy(0);  // Dummy node to handle edge case
    dummy.next = head;
    
    Node* fast = &dummy;
    Node* slow = &dummy;
    
    // Move 'fast' pointer K nodes ahead
    for (int i = 0; i < K; ++i) {
        if (fast == nullptr)
            return head;  // K is greater than the length of the list
        fast = fast->next;
    }
    
    // Move 'fast' and 'slow' pointers simultaneously until 'fast' reaches the end
    while (fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    
    // Delete the kth node from the end
    Node* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    
    return dummy.next;
}
