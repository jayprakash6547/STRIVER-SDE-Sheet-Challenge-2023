#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	int maxi=INT_MIN,product=1;
	for(int i=0;i<n;i++){
		product*=arr[i];
		maxi=max(maxi,product);
		if(product==0){
			product=1;
		}
	}
	product=1;
	for(int i=n-1;i>=0;i--){
		product*=arr[i];
		maxi=max(maxi,product);
		if(product==0){
			product=1;
		}
	}
	return maxi;
}
