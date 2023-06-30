#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int *arr;
    int to;
    int size;
public:
    
    Stack(int capacity) {
       arr=new int[capacity];
       size=capacity;
       to=-1;
    }

    void push(int num) {
       if(isFull())return;
       to++;
       arr[to]=num;
    }

    int pop() {
       if(isEmpty())return -1;
       int ans=arr[to];
       to--;
       return ans;
    }
    
    int top() {
        if(isEmpty())return -1;
        return arr[to];
    }
    
    int isEmpty() {
        return to==-1;
    }
    
    int isFull() {
       return (to-1)==size;
    }
    
};