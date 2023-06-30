#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    stack<int>stack;
    vector<int>ans(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!stack.empty()){
            if(stack.top()>arr[i]){
                ans[i]=stack.top();
                break;
            }stack.pop();
        }
        stack.push(arr[i]);
    }
    return ans;

}