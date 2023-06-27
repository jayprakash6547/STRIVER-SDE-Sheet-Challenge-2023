#include <bits/stdc++.h> 

void solve(int index, string s, unordered_set<string>& dictionary, vector<string>& ds, vector<string>& result) {
    if (index == s.length()) {
        string str;
        for (int i = 0; i < ds.size(); i++) {
            str += ds[i] + " ";
        }
        result.push_back(str);
        return;
    }

    for (int i = index; i < s.length(); i++) {
        if (dictionary.count(s.substr(index, i - index + 1))) {
            ds.push_back(s.substr(index, i - index + 1));
            solve(i + 1, s, dictionary, ds, result);
            ds.pop_back();
        }
    }
}

vector<string> wordBreak(string s, vector<string>& dictionary) {
    unordered_set<string> dict(dictionary.begin(), dictionary.end());
    vector<string> result;
    vector<string> ds;
    solve(0, s, dict, ds, result);
    return result;
}