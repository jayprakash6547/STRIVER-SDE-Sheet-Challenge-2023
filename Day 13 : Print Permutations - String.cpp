#include <bits/stdc++.h> 
void generatePermutations(string& s, int start, vector<string>& permutations) {
    if (start == s.length() - 1) {
        permutations.push_back(s);
        return;
    }

    for (int i = start; i < s.length(); i++) {
        swap(s[start], s[i]);
        generatePermutations(s, start + 1, permutations);
        swap(s[start], s[i]);
    }
}

vector<string> findPermutations(string& s) {
    vector<string> permutations;
    generatePermutations(s, 0, permutations);
    return permutations;
// }
}
