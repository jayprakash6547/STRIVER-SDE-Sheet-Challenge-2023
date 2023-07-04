#include <bits/stdc++.h>
vector<int> stringMatch(string text, string pattern) {
    vector<int> positions;  // Store the starting positions of matches
    int n = text.length();
    int m = pattern.length();
    for (int i = 0; i <= n - m; i++) {
        bool match = true;
        // Check if the current substring matches the pattern
        for (int j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }
        if (match) {
          positions.push_back(
              i + 1); // Add 1 to convert 0-based index to 1-based index
       }
    }
    return positions;
}