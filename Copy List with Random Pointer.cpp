#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    LinkedListNode<int>*ans;
    bool f=1;
    while(head!=NULL){
        LinkedListNode<int>*temp=new LinkedListNode<int>(head->data);
        if(f)ans=temp,f=0;
        temp->next=head->next;
        temp->random=head->random;
        head=head->next;
        temp=temp->next;
    }
    return ans;
}
