#include <bits/stdc++.h>
int expandAroundCenter(const string str, int left, int right) {
    while (left >= 0 && right < str.length() && str[left] == str[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}
// using two pointer approach


string longestPalinSubstring(string str)
{
     int n = str.length();
    int maxLen = 0;
    int maxStart = 0;

    for (int i = 0; i < n; i++) {
        int len1 = expandAroundCenter(str, i, i);
        int len2 = expandAroundCenter(str, i, i + 1);
        int len = max(len1, len2);

        if (len > maxLen) {
            maxLen = len;
            maxStart = i - (len - 1) / 2;
        }
    }

    return str.substr(maxStart, maxLen);
}