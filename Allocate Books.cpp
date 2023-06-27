#include <bits/stdc++.h> 
 bool isPossible(int n, int m, vector<int>& arr,long long int mid){
	 long long int countdays=1;
	 long long int timeSum=0;
	 for(int i=0;i<m;i++){
		 if(timeSum+arr[i]<=mid){
			 timeSum+=arr[i];
		 }
		 else{
			 countdays++;
			 if(countdays > n || arr[i]>mid){
				 return false;
			 }
			 else{
				 timeSum=arr[i];
			 }
			 
		 }
	 }
	 return true;
	
}
long long ayushGivesNinjatest(int n, int m, vector<int>time) 
{	
	// Write your code here.
	long long int s=0;
	long long int  sum=0;
	for(int i=0;i<time.size();i++){
		sum+=time[i];
	}
	
	long long int  e=sum;
	long long int ans=-1;
	
	while(s<=e){
		long long int mid = s+(e-s)/2;
		if(isPossible(n, m, time, mid))
		{
			ans=mid;
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	
	}
	return ans;
}