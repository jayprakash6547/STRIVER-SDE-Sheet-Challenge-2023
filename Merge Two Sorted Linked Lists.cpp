#include <bits/stdc++.h>


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
     Node<int>* dummy=new Node<int>(-1);

    Node<int>* temp=dummy;

    while(first!=NULL && second!=NULL){

        if(first->data<=second->data){

            Node<int> *newnode=new Node<int>(first->data);

            temp->next=newnode;

            first=first->next;

        }

        else{

            Node<int> *newnode=new Node<int>(second->data);

            temp->next=newnode;

            second=second->next;

        }

        temp=temp->next;

    }

    if(first==NULL){

        temp->next=second;

    }

    else if(second==NULL){

        temp->next=first;

    }

    return dummy->next;
}
