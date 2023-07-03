#include <bits/stdc++.h> 
int atoi(string s) {
    int n=s.size();
    bool flag=false;
    string ans="";
    for(int i=0;i<n;i++){
        if(s[i]=='-')flag=true;
        if(s[i]<65 && s[i]!='-'){
            ans+=s[i];
        }
    }if(flag==true)
    return -stoi(ans);
    return stoi(ans);
}