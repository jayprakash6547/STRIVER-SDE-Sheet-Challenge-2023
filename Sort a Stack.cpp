#include <bits/stdc++.h> 
void sortStack(stack<int> &stack)
{
	vector<int>temp;
	while(!stack.empty()){
		temp.push_back(stack.top());
		stack.pop();
	}
	sort(temp.begin(),temp.end());
	for(int i=0;i<temp.size();i++){
		stack.push(temp[i]);
	}
	
}