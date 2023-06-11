

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node dummy(0);  // Dummy node to hold the result
    Node* curr = &dummy;
    int carry = 0;
    
    while (num1 || num2 || carry) {
        int sum = carry;
        
        if (num1) {
            sum += num1->data;
            num1 = num1->next;
        }
        
        if (num2) {
            sum += num2->data;
            num2 = num2->next;
        }
        
        carry = sum / 10;
        sum %= 10;
        
        curr->next = new Node(sum);
        curr = curr->next;
    }
    
    return dummy.next;
}
