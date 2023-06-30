#include <bits/stdc++.h> 
class Queue {
private:
 int *arr;
 int qfront;
 int rear;
 int size;
public:
    Queue() {
        size=10001;
        arr=new int[size];
        qfront=0;
        rear=0;  
    }

    
    bool isEmpty() {
        if(qfront == rear)
         return true;
        return false;  
    }

    void enqueue(int data) {
        if(rear != size)
        
         arr[rear++]=data;
       
    }

    int dequeue() {
        if(rear == qfront)
         return -1;
        else
        {
            int temp=arr[qfront++];
            if(qfront == rear)
            {
                qfront=0;
                rear=0;
            }
            return temp;
        }
         
        
    }

    int front() {
        if(rear == qfront)
         return -1;
        return arr[qfront]; 
    }
};