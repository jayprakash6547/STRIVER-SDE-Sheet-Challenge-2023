#include <bits/stdc++.h> 
bool areAnagram(string &s1, string &s2){
    if(s1.size()!=s2.size())return false;
    unordered_map<char,int>mp;
    for(auto c:s1)mp[c]++;
    for (auto c : s2) {
      mp[c]--;
      if (mp[c] < 0)
        return false;
    }
    return true;
}