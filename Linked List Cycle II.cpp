Node* firstNode(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Check if there is a cycle
    bool hasCycle = false;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    // If there is no cycle, return nullptr
    if (!hasCycle) {
        return nullptr;
    }

    // Move the slow pointer back to the head
    slow = head;

    // Move both pointers at the same speed until they meet again
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Return the first node of the cycle
    return slow;
}

