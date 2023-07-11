#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	    priority_queue<int ,vector<int>,greater<int>>pq;
		for(int i=0;i<K;++i){
			 pq.push(arr[i]);
		}
		for(int i=K;i<size;++i){
			if(pq.top()<arr[i]){
				pq.pop();
				pq.push(arr[i]);
			}
		}
		return pq.top();
}
