#include<bits/stdc++.h>
int minCharsforPalindrome(string s) {
	int i=0,j=s.size()-1;
	int x=j,ans=0;
	while(i<j){
		if(s[i]==s[j]){
			i++;j--;
		}else{
			ans++;
			i=0;j=--x;
		}
	}
	return ans;
}
