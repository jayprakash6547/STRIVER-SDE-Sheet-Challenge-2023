#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    unordered_set<char> char_set;
    int max_substrings = 0;
    int window_start = 0;

    for (int i = 0; i < input.length(); ++i) {
        char current_char = input[i];

        while (char_set.find(current_char) != char_set.end()) {
            // Shrink the window from the start to exclude the repeated character
            char_set.erase(input[window_start]);
            ++window_start;
        }

        // Update the set with the current character
        char_set.insert(current_char);

        // Update the number of unique substrings
        max_substrings = max(max_substrings, i - window_start + 1);
    }

    return max_substrings;
}