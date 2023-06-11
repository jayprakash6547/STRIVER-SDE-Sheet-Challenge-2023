#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int> elements(arr.begin(), arr.end());
    int longest_sequence = 0;

    for (const int& num : arr) {
        // Check if the current element is the starting element of a sequence
        if (elements.find(num - 1) == elements.end()) {
            int current_sequence = 1;
            int current_num = num + 1;

            // Continue checking for consecutive elements
            while (elements.find(current_num) != elements.end()) {
                ++current_sequence;
                ++current_num;
            }

            // Update the longest_sequence
            longest_sequence = max(longest_sequence, current_sequence);
        }
    }

    return longest_sequence;
}